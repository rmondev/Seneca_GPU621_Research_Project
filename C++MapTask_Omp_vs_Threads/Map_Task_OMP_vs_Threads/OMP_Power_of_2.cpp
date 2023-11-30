#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <numeric>
#include <omp.h>

const int defaultArraySize = 1 << 20;

// Function to square each element in a given range of a vector
void squareElements(std::vector<int>& numbers, size_t start, size_t end) {
#pragma omp parallel for
   for (size_t i = start; i < end; ++i) {
      numbers[i] = numbers[i] * numbers[i];
   }
}

int main(int argc, char* argv[]) {
   // Check for the number of command line arguments
   // Parse the command line argument for array size
   int arraySize = (argc > 1) ? (1 << std::atoi(argv[1])) : defaultArraySize;

   // Create a vector of numbers
   std::vector<int> numbers(arraySize);
   std::iota(numbers.begin(), numbers.end(), 1);

   // Specify the number of threads to use
   const size_t numThreads = 4; // Set to 4 threads
   omp_set_num_threads(numThreads);

   // Calculate the range of elements each thread will process
   size_t elementsPerThread = arraySize / numThreads;

   // Record the start time
   auto startTime = std::chrono::high_resolution_clock::now();

   // Parallelize the loop using OpenMP
#pragma omp parallel for
   for (size_t i = 0; i < numThreads - 1; ++i) {
      squareElements(numbers, i * elementsPerThread, (i + 1) * elementsPerThread);
   }

   // The last thread may handle a slightly larger range
   squareElements(numbers, (numThreads - 1) * elementsPerThread, arraySize);

   // Record the end time
   auto endTime = std::chrono::high_resolution_clock::now();

   // Calculate the duration and display it
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
   std::cout << "Parallel section took " << duration.count() << " milliseconds." << std::endl;

   // Print the first few squared elements
   for (int i = 0; i < 10; ++i) {
      std::cout << numbers[i] << " ";
   }

   return 0;
}
