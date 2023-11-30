//#include <iostream>
//#include <thread>
//#include <vector>
//#include <algorithm>
//#include <chrono>
//
//const int arraySize = 1000;
//const int incrementValue = 23;
//
//// Function to increment the array elements
//void incrementArray(int arr[]) {
//   for (int i = 0; i < arraySize; ++i) {
//      arr[i] += incrementValue;
//   }
//}
//
//// Function to perform bubble sort on a section of the array
//void bubbleSort(int arr[], int start, int end) {
//   for (int i = start; i < end; ++i) {
//      for (int j = start; j < end - 1; ++j) {
//         if (arr[j] > arr[j + 1]) {
//            std::swap(arr[j], arr[j + 1]);
//         }
//      }
//   }
//}
//
//// Function to merge two sorted sections of the array
//void merge(int arr[], int start, int mid, int end) {
//   int n1 = mid - start + 1;
//   int n2 = end - mid;
//
//   std::vector<int> left(n1);
//   std::vector<int> right(n2);
//
//   for (int i = 0; i < n1; ++i) {
//      left[i] = arr[start + i];
//   }
//
//   for (int j = 0; j < n2; ++j) {
//      right[j] = arr[mid + 1 + j];
//   }
//
//   int i = 0, j = 0, k = start;
//
//   while (i < n1 && j < n2) {
//      if (left[i] <= right[j]) {
//         arr[k++] = left[i++];
//      }
//      else {
//         arr[k++] = right[j++];
//      }
//   }
//
//   while (i < n1) {
//      arr[k++] = left[i++];
//   }
//
//   while (j < n2) {
//      arr[k++] = right[j++];
//   }
//}
//
//// Function to perform parallel sorting using multiple threads
//void parallelSort(int arr[], int numThreads) {
//   std::vector<std::thread> threads;
//
//   // Split the array into sections based on the number of threads
//   int sectionSize = arraySize / numThreads;
//   for (int i = 0; i < numThreads; ++i) {
//      int start = i * sectionSize;
//      int end = (i == numThreads - 1) ? arraySize : start + sectionSize;
//      threads.emplace_back(bubbleSort, arr, start, end);
//   }
//
//   // Wait for all threads to finish
//   for (auto& thread : threads) {
//      thread.join();
//   }
//
//   // Merge the sorted sections
//   for (int size = sectionSize; size < arraySize; size *= 2) {
//      for (int left = 0; left < arraySize - 1; left += 2 * size) {
//         int mid = std::min(left + size - 1, arraySize - 1);
//         int right = std::min(left + 2 * size - 1, arraySize - 1);
//         merge(arr, left, mid, right);
//      }
//   }
//}
//
//int main() {
//   int arr[arraySize];
//
//   // Initialize array with random values
//   for (int i = 0; i < arraySize; ++i) {
//      arr[i] = rand() % 1000;
//   }
//
//   // Increment array elements
//   incrementArray(arr);
//
//   // Specify the number of threads to use
//   int numThreads = 4;
//
//   // Measure the time taken by the sorting process
//   auto start_time = std::chrono::high_resolution_clock::now();
//
//   // Perform parallel sorting
//   parallelSort(arr, numThreads);
//
//   auto end_time = std::chrono::high_resolution_clock::now();
//   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
//
//   // Display sorted array
//   std::cout << "Sorted Array:" << std::endl;
//   for (int i = 0; i < arraySize; ++i) {
//      std::cout << arr[i] << " ";
//   }
//
//   // Display the time taken
//   std::cout << "\nTime taken for sorting: " << duration.count() << " microseconds" << std::endl;
//
//   return 0;
//}
