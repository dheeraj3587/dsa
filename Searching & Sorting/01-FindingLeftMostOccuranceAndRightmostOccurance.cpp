#include<iostream>
// Function to find the leftmost occurrence of a key in a sorted array
int left(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// Function to find the rightmost occurrence of a key in a sorted array
int right(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    // Prompt the user to enter the size of the array
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Allocate memory for the array
    int* arr = new int[size];

    // Prompt the user to enter the elements of the array
    std::cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Prompt the user to enter the key to search for
    int key;
    std::cout << "Enter the key to search for: ";
    std::cin >> key;

    // Find the leftmost and rightmost occurrences of the key
    int leftmost = left(arr, size, key);
    int rightmost = right(arr, size, key);

    // Print the results
    if (leftmost == -1) {
        std::cout << "Key not found in the array" << std::endl;
    }
    else {
        std::cout << "Leftmost occurrence of key is at index " << leftmost << std::endl;
        std::cout << "Rightmost occurrence of key is at index " << rightmost << std::endl;
    }

    // Deallocate memory for the array
    delete[] arr;

    return 0;
}
