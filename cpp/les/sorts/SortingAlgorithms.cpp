#include "SortingAlgorithms.h"
#include <vector>

#include <algorithm>
template <typename T>
void SortingAlgorithms<T>::bubbleSort(std::vector<T> &arr) {

  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

template <typename T>
void SortingAlgorithms<T>::selectionSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      std::swap(arr[i], arr[min_idx]);
    }
  }
}

template <typename T>
void SortingAlgorithms<T>::insertionSort(std::vector<T> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

template <typename T>
void SortingAlgorithms<T>::merge(std::vector<T> &arr, int left, int middle,
                                 int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;

  std::vector<T> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[middle + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {

    if (L[i] <= R[j]) {

      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];

    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

template <typename T>
void SortingAlgorithms<T>::mergeSortRecursive(std::vector<T> &arr, int left,
                                              int right) {
  if (left >= right)
    return;
  int middle = left + (right - left) / 2;
  mergeSortRecursive(arr, left, middle);
  mergeSortRecursive(arr, middle + 1, right);
  merge(arr, left, middle, right);
}

template <typename T>
void SortingAlgorithms<T>::mergeSort(std::vector<T> &arr) {
  if (arr.empty())
    return;
  mergeSortRecursive(arr, 0, arr.size() - 1);
}

template <typename T>
int SortingAlgorithms<T>::partition(std::vector<T> &arr, int low, int high) {
  T pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {

      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

template <typename T>
void SortingAlgorithms<T>::quickSortRecursive(std::vector<T> &arr, int low,
                                              int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSortRecursive(arr, low, pi - 1);
    quickSortRecursive(arr, pi + 1, high);
  }
}

template <typename T>
void SortingAlgorithms<T>::quickSort(std::vector<T> &arr) {
  if (arr.empty())
    return;
  quickSortRecursive(arr, 0, arr.size() - 1);
}

template <typename T>
void SortingAlgorithms<T>::heapify(std::vector<T> &arr, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    std::swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}

template <typename T> void SortingAlgorithms<T>::heapSort(std::vector<T> &arr) {
  int n = arr.size();

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);


  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

template class SortingAlgorithms<int>;
template class SortingAlgorithms<double>;
