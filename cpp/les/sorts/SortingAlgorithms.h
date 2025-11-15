#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class SortingAlgorithms {
public:
    static void bubbleSort(std::vector<T>& arr);
    static void selectionSort(std::vector<T>& arr);
    static void insertionSort(std::vector<T>& arr);
    static void mergeSort(std::vector<T>& arr);
    static void quickSort(std::vector<T>& arr);

    static void heapSort(std::vector<T>& arr);


private:
    static void mergeSortRecursive(std::vector<T>& arr, int left, int right);
    static void merge(std::vector<T>& arr, int left, int middle, int right);

    static void quickSortRecursive(std::vector<T>& arr, int low, int high);
    static int partition(std::vector<T>& arr, int low, int high);

    static void heapify(std::vector<T>& arr, int n, int i);
};

