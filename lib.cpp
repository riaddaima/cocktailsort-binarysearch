#include <iostream>
#include "header.h"

using namespace std;

int menu() {
  int choice;
  cout<<"\n--MENU--\n";
  cout<<"1. Sort Array\n2. Search a number in Array\n3. Print array\n4. Exit\n";
  cin>>choice; // == scanf("%d", &choice);
  return choice;
}

void _swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int i = low, j = high - 1;
    int pivot = (low + high) / 2;
    _swap(&arr[pivot], &arr[high]);
    while (i <= j) {
      if (arr[i] > arr[high]) {
        if (arr[j] < arr[high]) {
          _swap(&arr[i++], &arr[j--]);
        } else {
          j--;
        }
      } else {
        i++;
      }
    }
    _swap(&arr[i], &arr[high]);
    quicksort(arr, low, j);
    quicksort(arr, ++i, high);
  }
}

int binarysearch(int arr[], int lenarr, int target) {

  int L = 0, R = lenarr - 1;
  while (L <= R) {
    int midpoint = (L + R) / 2;
    if (target == arr[midpoint])
      return midpoint;
    else if (target > arr[midpoint])
      L = midpoint++;
    else
      R = midpoint--;
  }
  return -1;
}

void printarr(int arr[], int lenarr) {
  cout<<">> Array : ";
  for (int i = 0; i < lenarr; i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
}
