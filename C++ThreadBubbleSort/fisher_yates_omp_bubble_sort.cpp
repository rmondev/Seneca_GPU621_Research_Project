//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <omp.h>
//#include <chrono>
//#include <random>
//
//const int arraySize = 1000;
//
//// Function to perform Fisher-Yates shuffle
//void fisherYatesShuffle(std::vector<int>& nums) {
//   std::random_device rd;
//   std::mt19937 gen(rd());
//   std::shuffle(nums.begin(), nums.end(), gen);
//}
//
//// Function to perform parallel bubble sort on a section of the array
//void parallelBubbleSort(int arr[], int start, int end) {
//#pragma omp parallel for
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
//// Function to perform parallel sorting using OpenMP
//void parallelSort(int arr[], int numThreads) {
//   // Set the number of threads to use
//   omp_set_num_threads(numThreads);
//
//   // Split the array into sections based on the number of threads
//   int sectionSize = arraySize / numThreads;
//#pragma omp parallel for
//   for (int i = 0; i < numThreads; ++i) {
//      int start = i * sectionSize;
//      int end = (i == numThreads - 1) ? arraySize : start + sectionSize;
//      parallelBubbleSort(arr, start, end);
//   }
//
//   // Merge the sorted sections
//   for (int size = sectionSize; size < arraySize; size *= 2) {
//#pragma omp parallel for
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
//   // Initialize vector with unique random numbers
//   std::vector<int> uniqueNumbers(arraySize);
//   for (int i = 0; i < arraySize; ++i) {
//      uniqueNumbers[i] = i + 1;
//   }
//
//   // Shuffle the unique numbers
//   fisherYatesShuffle(uniqueNumbers);
//
//   // Assign the shuffled unique numbers to the array
//   for (int i = 0; i < arraySize; ++i) {
//      arr[i] = uniqueNumbers[i];
//   }
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
//   // Display the time taken in microseconds
//   std::cout << "\nTime taken for sorting: " << duration.count() << " microseconds" << std::endl;
//
//   return 0;
//}
