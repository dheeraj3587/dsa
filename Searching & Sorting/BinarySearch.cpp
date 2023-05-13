#include<iostream>
#include <iomanip>

// function to perform bubble sort on the array
void bubble(int arr[], int size){
  int temp;
  for(int i=0; i<size-1; i++){
    for(int j=0; j<size-i-1; j++){
      if(arr[j] < arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

// function to perform binary search on the sorted array
int binary(int *arr, int size, int target){
  int start = 0;
  int end = size;
  int mid;

  while (start <= end){
    mid = (start + end) / 2;

    if(arr[mid] == target){
      return mid;
    }

    if(arr[mid] > target){
      start = mid + 1;
    }
    else{
      end = mid;
    }
  }

  return -1;
}

int main(){
  int num;
  std::cout << "Enter the size of array: " << std::endl;
  std::cin >> num;

  int arr[num];

  // loop to take input elements from the user
  for(int i=0; i<num; i++){
    std::cout << "Enter the " << i << "th element: " << std::endl;
    std::cin >> arr[i];
  }

  bubble(arr, num);

  std::cout << "The sorted array is:" << std::endl;

  // loop to print the sorted array
  for(int n=0; n<num; n++){
    std::cout << std::setw(2) << arr[n] << " ";
  }

  std::cout << std::endl;

  int target;
  std::cout << "Enter the target to search in the array: " << std::endl;
  std::cin >> target;

  int index = binary(arr, num, target);

  if(index == -1){
    std::cout << "The element is not present in the array." << std::endl;
  }
  else{
    std::cout << "The element is present at index " << index << std::endl;
  }

  return 0;
}
