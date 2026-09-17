cmake_minimum_required(VERSION 3.20)

# ============================================================================
#  数据结构与算法 练习工程（内层：源码所在目录）
#
#  结构：本目录下每个 .cpp 都是带自己 main() 的独立练习程序，
#        所以采用「一个源文件 = 一个可执行文件」。
#        （把多个都带 main() 的文件塞进同一个工程/项目，就会得到
#          LNK2005 / LNK1169「main 重复定义」或「找不到 main」的报错。）
#
#  自动跳过：练习过程中被整体 // 注释掉、或包在 #if 0 ... #endif 里的文件
#            当前没有可编译的 main()，配置时会被自动跳过并列出清单，
#            这样 `cmake --build` 永远是干净的构建。
#            等你把代码恢复出来，重新配置就会自动重新纳入，无需改本文件。
#
#  用法：
#    cmake --preset mingw-debug && cmake --build --preset mingw-debug
#    cmake --preset msvc        && cmake --build --preset msvc-debug
# ============================================================================

project(dsa_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 中文源文件名 -> ASCII 目标名（CMake 的目标名不允许出现非 ASCII 字符）
set(_KNOWN
  "数组.cpp=array_basics"
  "单项链表.cpp=singly_linked_list"
  "单项循环链表.cpp=circular_linked_list"
  "双指针奇偶数判断.cpp=two_pointers_parity"
  "逆序字符串.cpp=reverse_string"
  "单链表逆序.cpp=list_reverse"
  "单链表是否存在环.cpp=list_has_cycle"
  "单链表求倒数第K个节点.cpp=list_kth_from_end"
  "单链表 有序列表合并.cpp=list_merge_sorted"
)

# 如果你确实需要一个含 #if 0 调试块、但仍然要参与构建的文件，
# 把它的文件名填到这里强制纳入。
set(_FORCE_BUILD
  # "某个文件名.cpp"
)

# 拆成两条平行列表，避免出现含中文的 CMake 变量名
set(_KEYS)
set(_VALS)
foreach(_pair IN LISTS _KNOWN)
  string(FIND "${_pair}" "=" _eq)
  string(SUBSTRING "${_pair}" 0 ${_eq} _k)
  math(EXPR _eq1 "${_eq} + 1")
  string(SUBSTRING "${_pair}" ${_eq1} -1 _v)
  list(APPEND _KEYS "${_k}")
  list(APPEND _VALS "${_v}")
endforeach()

# 统一输出到 ASCII 路径，避免中文 exe 名在构建系统里出问题
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
foreach(_cfg DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${_cfg} "${CMAKE_BINARY_DIR}/bin")
endforeach()

if(MSVC)
  add_compile_options(/utf-8 /W3 /EHsc /MP)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
  add_compile_options(-Wall -finput-charset=UTF-8 -fexec-charset=UTF-8)
  if(MINGW)
    # 静态链接 libstdc++/libgcc：生成的 exe 双击即可运行，不依赖 MSYS2 的 DLL
    add_link_options(-static)
  endif()
endif()

file(GLOB _ALL_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(SORT _ALL_SOURCES)

# ---- 挑出「当前真的能编译」的源文件 ----------------------------------------
# 判据：去掉 // 与 /* */ 注释后仍能找到 main(，且文件里没有 #if 0 关闭块。
set(_SOURCES)
set(_SKIPPED)
foreach(_src IN LISTS _ALL_SOURCES)
  get_filename_component(_fname "${_src}" NAME)
  file(READ "${_src}" _body)
  string(REGEX REPLACE "//[^\r\n]*" "" _stripped "${_body}")
  string(REGEX REPLACE "/\\*([^*]|\\*+[^*/])*\\*+/" "" _stripped "${_stripped}")

  list(FIND _FORCE_BUILD "${_fname}" _forced)
  if(_forced GREATER -1)
    list(APPEND _SOURCES "${_src}")
  elseif(_stripped MATCHES "main[ \t\r\n]*\\(" AND NOT _body MATCHES "(^|\n)[ \t]*#[ \t]*if[ \t]+0")
    list(APPEND _SOURCES "${_src}")
  else()
    list(APPEND _SKIPPED "${_fname}")
  endif()
endforeach()

if(NOT _ALL_SOURCES)
  message(WARNING "本目录下没有找到任何 .cpp 文件：${CMAKE_CURRENT_SOURCE_DIR}")
endif()

set(_auto 0)
set(_targets)
foreach(_src IN LISTS _SOURCES)
  get_filename_component(_fname "${_src}" NAME)
  list(FIND _KEYS "${_fname}" _hit)
  if(_hit GREATER -1)
    list(GET _VALS ${_hit} _target)
  else()
    math(EXPR _auto "${_auto} + 1")
    set(_target "algo_${_auto}")
  endif()

  add_executable(${_target} "${_src}")
  set_target_properties(${_target} PROPERTIES
    OUTPUT_NAME "${_target}"
    FOLDER "practices"
  )
  list(APPEND _targets ${_target})
endforeach()

list(LENGTH _targets _n)
message(STATUS "dsa_practice: 参与构建 ${_n} 个 -> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
foreach(_t IN LISTS _targets)
  message(STATUS "  [构建] ${_t}")
endforeach()

if(_SKIPPED)
  list(LENGTH _SKIPPED _sn)
  message(STATUS "dsa_practice: 跳过 ${_sn} 个（当前没有可编译的 main()，恢复代码后重新配置即可）")
  foreach(_s IN LISTS _SKIPPED)
    message(STATUS "  [跳过] ${_s}")
  endforeach()
endif()
