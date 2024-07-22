# CMakeList.txt: LeetCodeHot100 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (LeetCodeHot100 "main.cpp" "LeetCodeHot100_049.h" "LeetCodeHot100_062.h" "LeetCodeHot100_128.h" "LeetCodeHot100_283.h" "LeetCodeHot100_011.h" "LeetCodeHot100_015.h" "LeetCodeHot100_042.h" "LeetCodeHot100_003.h" "LeetCodeHot100_438.h" "LeetCodeHot100_438.cpp" "LeetCodeHot100_560.h" "LeetCodeHot100_560.cpp" "LeetCodeHot100_001.h" "LeetCodeHot100_001.cpp" "LeetCodeHot100_239.h" "LeetCodeHot100_239.cpp" "LeetCodeHot100_076.h" "LeetCodeHot100_076.cpp" "LeetCodeHot100_053.h" "LeetCodeHot100_053.cpp" "LeetCodeHot100_056.h" "LeetCodeHot100_056.cpp" "LeetCodeHot100_189.h" "LeetCodeHot100_189.cpp" "LeetCodeHot100_238.h" "LeetCodeHot100_238.cpp" "LeetCodeHot100_041.h" "LeetCodeHot100_041.cpp" "LeetCodeHot100_073.h" "LeetCodeHot100_073.cpp" "LeetCodeHot100_160.h" "LeetCodeHot100_160.cpp" "LeetCodeHot100_206.h" "LeetCodeHot100_206.cpp" "LeetCodeHot100_234.h" "LeetCodeHot100_234.cpp" "LeetCodeHot100_141.h" "LeetCodeHot100_141.cpp" "LeetCodeHot100_142.cpp" "LeetCodeHot100_142.h" "LeetCodeHot100_021.h" "LeetCodeHot100_021.cpp" "LeetCodeHot100_002.h" "LeetCodeHot100_002.cpp" "LeetCodeHot100_019.h" "LeetCodeHot100_019.cpp" "LeetCodeHot100_024.h" "LeetCodeHot100_024.cpp" "LeetCodeHot100_024.h" "LeetCodeHot100_025.cpp" "LeetCodeHot100_025.h" "LeetCodeHot100_138.h" "LeetCodeHot100_138.cpp" "LeetCodeHot100_148.h" "LeetCodeHot100_148.cpp" "LeetCodeHot100_023.h" "LeetCodeHot100_023.cpp" "LeetCodeHot100_146.h" "LeetCodeHot100_146.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCodeHot100 PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
