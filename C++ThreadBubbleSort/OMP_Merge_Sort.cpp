//#include <iostream>
//#include <vector>
//#include <omp.h>
//#include <chrono>
//#include <random>
//#include <cstdlib> // For std::atoi
//
//const int defaultArraySize = 1000;
//
//// Function to perform Fisher-Yates shuffle
//void fisherYatesShuffle(std::vector<int>& nums) {
//   // The std::random_device is used to generate a random seed. It provides a source of non-deterministic random numbers (based on some external entropy source, such as hardware).
//   std::random_device rd;
//
//   // The Mersenne Twister engine (std::mt19937) is a widely-used pseudo-random number generator. It takes the random seed from the std::random_device and produces a sequence of random numbers.
//   std::mt19937 gen(rd());
//
//   // The std::shuffle function is then used to shuffle the elements in the nums vector.
//   std::shuffle(nums.begin(), nums.end(), gen);
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
//// Function to perform parallel sorting using OpenMP and parallelized merge sort
//void parallelSort(int arr[], int numThreads, int start, int end) {
//   omp_set_num_threads(numThreads);
//
//   // Recursive merge-sort 
//   // 
//   // If this condition is false, it means the array or subarray has only one element or is empty, and no further sorting is needed.
//   if (start < end) {
//      int mid = start + (end - start) / 2;
//
//#pragma omp parallel sections
//      {
//#pragma omp section
//         parallelSort(arr, numThreads, start, mid);
//
//#pragma omp section
//         parallelSort(arr, numThreads, mid + 1, end);
//      }
//
//      merge(arr, start, mid, end);
//   }
//}
//
//int main(int argc, char* argv[]) {
//   // Get array size from command line argument or use default
//   int arraySize = (argc > 1) ? std::atoi(argv[1]) : defaultArraySize;
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
//   // Convert vector to array
//   int* arr = uniqueNumbers.data();
//
//   // Specify the number of threads to use
//   int numThreads = 4;
//
//   // Measure the time taken by the sorting process
//   auto start_time = std::chrono::high_resolution_clock::now();
//
//   // Perform parallel sorting using parallelized merge sort
//   parallelSort(arr, numThreads, 0, arraySize - 1);
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
//   std::cout << "\nTime taken for sorting: " << duration.count()/1000 << " milliseconds" << std::endl;
//
//   return 0;
//}
