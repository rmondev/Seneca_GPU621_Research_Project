#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <cstdlib>

const int defaultArraySize = 1000;

void fisherYatesShuffle(std::vector<int>& nums) {
   // The std::random_device is used to generate a random seed. It provides a source of non-deterministic random numbers (based on some external entropy source, such as hardware).
   std::random_device rd;

   // The Mersenne Twister engine (std::mt19937) is a widely-used pseudo-random number generator. It takes the random seed from the std::random_device and produces a sequence of random numbers.
   std::mt19937 gen(rd());

   // The std::shuffle function is then used to shuffle the elements in the nums vector.
   std::shuffle(nums.begin(), nums.end(), gen);
}

// Responsible for merging two sorted halves of an array into a single sorted array.
void merge(int arr[], int start, int mid, int end) {
   int n1 = mid - start + 1;
   int n2 = end - mid;

   std::vector<int> left(n1);
   std::vector<int> right(n2);

   for (int i = 0; i < n1; ++i) {
      left[i] = arr[start + i];
   }

   for (int j = 0; j < n2; ++j) {
      right[j] = arr[mid + 1 + j];
   }

   int i = 0, j = 0, k = start;

   while (i < n1 && j < n2) {
      if (left[i] <= right[j]) {
         arr[k++] = left[i++];
      }
      else {
         arr[k++] = right[j++];
      }
   }

   while (i < n1) {
      arr[k++] = left[i++];
   }

   while (j < n2) {
      arr[k++] = right[j++];
   }
}

void mergeSort(int arr[], int start, int end) {
   
   // Recursive merge-sort 
   // 
   // If this condition is false, it means the array or subarray has only one element or is empty, and no further sorting is needed.
   if (start < end) {
      int mid = start + (end - start) / 2;

      // Create threads for both halves
      std::thread leftThread(mergeSort, arr, start, mid);
      std::thread rightThread(mergeSort, arr, mid + 1, end);

      // Join threads to wait for their completion
      leftThread.join();
      rightThread.join();

      // Merge the sorted halves
      merge(arr, start, mid, end);
   }
}

void parallelSort(int arr[], int arraySize) {
   mergeSort(arr, 0, arraySize - 1);
}

int main(int argc, char* argv[]) {
   int arraySize = (argc > 1) ? std::atoi(argv[1]) : defaultArraySize;

   std::vector<int> uniqueNumbers(arraySize);
   for (int i = 0; i < arraySize; ++i) {
      uniqueNumbers[i] = i + 1;
   }

   fisherYatesShuffle(uniqueNumbers);

   int* arr = uniqueNumbers.data();

   auto start_time = std::chrono::high_resolution_clock::now();
   parallelSort(arr, arraySize);
   auto end_time = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

   std::cout << "Sorted Array:" << std::endl;
   for (int i = 0; i < arraySize; ++i) {
      std::cout << arr[i] << " ";
   }

   std::cout << "\nTime taken for sorting: " << duration.count()/1000 << " milliseconds" << std::endl;

   return 0;
}
