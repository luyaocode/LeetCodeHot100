# CMakeList.txt: LeetCodeHot100 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (LeetCodeHot100 "main.cpp" "LeetCodeHot100_049.h" "LeetCodeHot100_062.h" "LeetCodeHot100_128.h" "LeetCodeHot100_283.h" "LeetCodeHot100_011.h" "LeetCodeHot100_015.h" "LeetCodeHot100_042.h" "LeetCodeHot100_003.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCodeHot100 PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
