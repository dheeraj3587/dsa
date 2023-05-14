#include <iostream>

// **This function finds the peak element in an array**.
int peak(int arr[], int size) {
  // Initialize the start and end indexes.
  int s = 0;
  int e = size - 1;

  // While the start index is less than the end index,
  // do the following:
  while (s < e) {
    // Calculate the middle index.
    int mid = s + (e - s) / 2;

    // If the element at the middle index is less than the element at the next index,
    // then the peak element is at the next index.
    if (arr[mid] < arr[mid + 1]) {
      s = mid + 1;
    } else {
      // Otherwise, the peak element is at the current index.
      e = mid;
    }
  }

  // Return the peak index.
  return s;
}

// **This function prompts the user to enter an array of integers and then calls the peak() function to find the peak index in the array**.
int main() {
  // Declare an array to store the user input.
  int arr[100];

  // Prompt the user to enter the number of elements in the array.
  std::cout << "Enter the number of elements in the array: ";
  int n;
  std::cin >> n;

  // Prompt the user to enter the elements in the array.
  for (int i = 0; i < n; i++) {
    std::cout << "Enter the element at index " << i << ": ";
    std::cin >> arr[i];
  }

  // Call the peak() function to find the peak element in the array.
  int peakIndex = peak(arr, n);

  // Print the peak index.
  std::cout << "The peak index in the array is " <<peakIndex<< std::endl;

  return 0;
}
