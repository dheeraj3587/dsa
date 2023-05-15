#include <iostream>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int>& arr) {
    int len = arr.size();

    // Outer loop to iterate over the array
    for (int i = 0; i < len - 1; i++) {
        int min = i;

        // Inner loop to find the minimum element
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        // Swap the current element with the minimum element
        std::swap(arr[i], arr[min]);
    }
}

int main() {
    std::vector<int> arr;

    std::cout << "Enter the number of elements: ";
    int n;
    std::cin >> n;

    std::cout << "Enter the elements:\n";

    // Input the elements from the user
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    // Sort the array using selection sort
    selectionSort(arr);

    std::cout << "Sorted array:\n";

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
