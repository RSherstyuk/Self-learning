# C++ Projects

This directory contains various projects and algorithm implementations in C++.

## Contents

*   **`indegrees.cpp`**: Implementation of an algorithm to find all recipes based on available ingredients and supplies, using topological sorting.

*   **`recipes.py`**: A Python version of the recipe finding problem solution.

*   **`sorts/mergeSort.cpp`**: A standalone implementation of the merge sort algorithm.

### `cpp/les` (Educational Materials / Problems)

This subdirectory likely contains code for exploring various C++ concepts and algorithms.

*   **`graph/Graph.cpp` / `graph/Graph.h`**: Implementation of a Graph class with methods for adding edges and topological sorting.
*   **`include/FileRaii.h`**: `FileRaii` class for managing file resources using the RAII idiom.
*   **`include/Shape.h`**: Class hierarchy for geometric shapes (`Shape`, `Circle`, `Sphere`) with virtual methods for calculating area.
*   **`include/Unique_ptr.cpp`**: Examples of using `std::unique_ptr` for memory and resource management, including `Logger` class and `create_buffer` function.
*   **`sorts/SortingAlgorithms.cpp` / `sorts/SortingAlgorithms.h`**: Implementations of various sorting algorithms (bubble sort, selection sort, insertion sort, merge sort, quick sort, heap sort).
*   **`src/Raii.cpp`**: Additional examples of RAII idiom usage with `MyObject`, `Data` (raw pointer), and `ModernData` (`std::unique_ptr`) classes.
*   **`src/main.cpp`**: Examples demonstrating `std::shared_ptr` and a simple graph structure.
*   **`tests/test.cpp`**: Tests for various components.

### `cpp/series` (Problems / Applications)

This subdirectory includes several distinct problems or small applications.

*   **`anime_filter.cpp` / `main.cpp`**: Implementations of filters for anime-style image processing, including color quantization and edge detection.
*   **`ser.cpp`**: Implementations of functions for calculating sine, cosine, and exponential series.
*   **`slidingWindow.cpp`**: An example implementation of the "sliding window" algorithm.

### `cpp/shad` (Algorithms)

This subdirectory is dedicated to algorithm implementations.

*   **`src/algo.cpp` / `src/algo.h`**: Implementation of an `Algo` class with a `fineUnPairEl` method for finding the unpaired element in a vector of numbers.
*   **`tests/algo_test.cpp`**: Tests for `fineUnPairEl`.

### `cpp/ten` (LeetCode Problems / Data Structures)

This subdirectory contains solutions to problems commonly found on platforms like LeetCode, as well as data structure implementations.

*   **`include/Date.hpp` / `src/Date.cpp`**: Implementation of a `Date` class with date correctness validation and functions for working with days/months/years.
*   **`include/Matrix.hpp`**: A templated `Matrix` class for matrix operations, including row alignment.
*   **`sliding_window/SlidingWindow.cpp` / `sliding_window/SlidingWindow.h`**: Implementations of "sliding window" algorithms for problems such as `findMaxAverage` and `minSubArrayLen`.
*   **`src/main.cpp`**: Contains an example `merge` function for merging two sorted vectors.
*   **`two_pointers/SolutionTwoPointers.cpp` / `two_pointers/SolutionTwoPointers.h`**: `SolutionTwoPointers` class with numerous algorithm implementations using the "two-pointers" pattern, such as: `reverseString`, `isPalindrome`, `twoSum`, `threeSum`, `sortedSquares`, `fSum`, `maxArea`, `removeDuplicates`, `moveZeroes`, `isSubseq`, `backspaceCompare`, `merge`, `mergeWith`.
*   **`two_pointers/SolutionTwoPointersB.cpp` / `two_pointers/SolutionTwoPointersB.h`**: An alternative `threeSum` implementation.
*   **`tests/date_test.cpp`**: Tests for the `Date` class.
*   **`tests/matrix_test.cpp`**: Tests for the templated `Matrix` class.
*   **`tests/sliding_window_test.cpp`**: Tests for `SlidingWindow` methods.
*   **`tests/two_test.cpp`**: Tests for `SolutionTwoPointers` methods.
