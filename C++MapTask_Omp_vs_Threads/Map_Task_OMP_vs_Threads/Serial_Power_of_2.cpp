#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

const int defaultArraySize = 1 << 20;

// Function to square each element in a given range of a vector
void squareElements(std::vector<int>& numbers, size_t start, size_t end) {
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

   // Record the start time
   auto startTime = std::chrono::high_resolution_clock::now();

   // Square each element in the vector
   squareElements(numbers, 0, arraySize);

   // Record the end time
   auto endTime = std::chrono::high_resolution_clock::now();

   // Calculate the duration and display it
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
   std::cout << "Serial section took " << duration.count() << " milliseconds." << std::endl;

   // Print the first few squared elements
   for (int i = 0; i < 10; ++i) {
      std::cout << numbers[i] << " ";
   }

   return 0;
}
