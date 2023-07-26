#include <iostream>
#include <cassert>

// Merge two sorted subarrays into a single sorted subarray.
void merge(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays to store the divided subarrays
    int* first = new int[len1];
    int* second = new int[len2];

    // Copy elements to the temporary arrays
    int k = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    // Merge the two subarrays back into arr[]
    int index1 = 0;
    int index2 = 0;
    k = s;
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[k++] = first[index1++];
        } else {
            arr[k++] = second[index2++];
        }
    }

    // Copy the remaining elements of first[], if any
    while (index1 < len1) {
        arr[k++] = first[index1++];
    }

    // Copy the remaining elements of second[], if any
    while (index2 < len2) {
        arr[k++] = second[index2++];
    }

    // Free the memory allocated for temporary arrays
    delete[] first;
    delete[] second;
}

// Recursive function to perform merge sort
void mergeSort(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

// Unit tests for merge sort
void unitTests() {
    int arr[] = {22, 2, 1, 2, 14, 2, 56, 53, 6, 78};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    // Check if the array is sorted
    for (int i = 1; i < size; i++) {
        assert(arr[i - 1] <= arr[i]);
    }
}

int main() {
    // Run the unit tests
    unitTests();

    std::cout << "Merge sort unit tests passed successfully." << std::endl;

    return 0;
}
