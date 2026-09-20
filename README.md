# Data Structures and Algorithms

本项目为 C++ 实现的数据结构与算法练习仓库：每个 `.cpp` 都是**自带 `main()` 的独立练习程序**，按主题放在 `src/` 子目录下。

This project is a C++ practice repository for classic data structures and algorithms, suitable for both beginners and advanced learners.

## 目录结构 / Repository Layout

```
.
├── src/                          # 当前练习源码（按主题分类）
│   ├── 01_array/                 # 数组：数组.cpp、双指针奇偶数判断.cpp
│   ├── 02_string/                # 字符串：逆序字符串.cpp
│   └── 03_linked_list/           # 链表：单项链表.cpp、单项循环链表.cpp、双向链表.cpp、
│                                 #       双向循环链表.cpp、单链表逆序.cpp、单链表是否存在环.cpp、
│                                 #       单链表求倒数第K个节点.cpp、单链表 有序列表合并.cpp、
│                                 #       约瑟夫环问题.cpp
├── legacy/2026-04-old-project/   # 旧版工程归档（2025-10 ~ 2026-04 历史：Array/List 旧源码、旧 vcxproj）
├── docs/README-old-2026-04-19.md # 旧版 README 存档
├── CMakeLists.txt                # 自动为 src/ 下每个 .cpp 生成一个可执行文件
├── CMakePresets.json             # mingw-debug / mingw-release / msvc 预设
└── data-structures-and-algorithms.vcxproj  # Visual Studio 工程（练习用）
```

## 构建 / Build

```powershell
# MinGW (Ninja)
cmake --preset mingw-debug   ; cmake --build --preset mingw-debug
cmake --preset mingw-release ; cmake --build --preset mingw-release

# MSVC (Visual Studio 18 2026)
cmake --preset msvc          ; cmake --build --preset msvc-debug
```

- 每个源文件生成一个可执行文件，输出到 `build/<preset>/bin/`。
- 目标名（可执行文件名）在 `CMakeLists.txt` 的 `_KNOWN` 列表中登记；未登记的文件自动命名为 `algo_N`。
- 新增练习：把 `.cpp` 放进 `src/` 下对应主题目录即可，重新配置时自动纳入（`file(GLOB_RECURSE ... CONFIGURE_DEPENDS)`）。
- 文件里的 `main()` 被整体注释掉、或包在 `#if 0 ... #endif` 中时，配置阶段会自动跳过并打印清单，不会导致链接错误；确需强制参与构建的文件登记到 `_FORCE_BUILD`。

## 项目文件 / Source Files

| 分类 | 文件 | 说明 |
|------|------|------|
| 数组 | `src/01_array/数组.cpp` | 数组基础操作（增删改查） |
| 数组 | `src/01_array/双指针奇偶数判断.cpp` | 双指针划分奇偶数 |
| 字符串 | `src/02_string/逆序字符串.cpp` | 字符串逆序 |
| 链表 | `src/03_linked_list/单项链表.cpp` | 单链表基本操作 |
| 链表 | `src/03_linked_list/单项循环链表.cpp` | 循环链表 + 约瑟夫环 |
| 链表 | `src/03_linked_list/双向链表.cpp` | 双向链表 |
| 链表 | `src/03_linked_list/双向循环链表.cpp` | 双向循环链表 |
| 链表 | `src/03_linked_list/单链表逆序.cpp` | 单链表反转 |
| 链表 | `src/03_linked_list/单链表是否存在环.cpp` | 快慢指针判环 |
| 链表 | `src/03_linked_list/单链表求倒数第K个节点.cpp` | 双指针求倒数第 K 个 |
| 链表 | `src/03_linked_list/单链表 有序列表合并.cpp` | 合并两个有序链表 |
| 链表 | `src/03_linked_list/约瑟夫环问题.cpp` | 约瑟夫环 |

> 旧版源码（2026-04 之前）保存在 `legacy/2026-04-old-project/`，可作为对照参考。

## 贡献 / Contribution

欢迎提交 Pull Request 或 Issue 交流学习心得。
