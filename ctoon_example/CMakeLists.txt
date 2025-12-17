cmake_minimum_required(VERSION 3.15)
project(CtoonExample)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加ctoon库（需要先下载到D:\ctoon）
# 注意：取消下面的注释当ctoon库安装完成后
# add_subdirectory(D:/ctoon ctoon_build)

# 创建可执行文件
add_executable(ctoon_demo main.cpp)

# 链接ctoon库（需要先安装ctoon）
# target_link_libraries(ctoon_demo PRIVATE ctoon)

# 设置包含目录（当ctoon安装后）
# target_include_directories(ctoon_demo PRIVATE D:/ctoon/include)

# 设置输出目录
set_target_properties(ctoon_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
)

# 安装规则
install(TARGETS ctoon_demo
    RUNTIME DESTINATION bin
)
