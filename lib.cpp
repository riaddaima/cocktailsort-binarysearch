#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;

int issorted = 0;

int menu() {
  int choice;
  cout<<"\n--MENU--\n";
  cout<<"1. Sort Array\n2. Search a number in Array\n3. Print array\n4. Exit\n";
  cin>>choice; // == scanf("%d", &choice);
  return choice;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void cocktailsort(int arr[], int lenarr) {

  int i, sorted = 0;
  while (!sorted) {
    for (i = 0; i < lenarr - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        sorted = 0;
      }
      else
        sorted = 1;
    }
    for (i = lenarr - 1; i > 0; i--) {
      if (arr[i] < arr[i - 1]) {
        swap(&arr[i], &arr[i - 1]);
        sorted = 0;
      }
      else
        sorted = 1;
    }
  }
  issorted = 1;
  cout<<">> Array sorted successfully!\n";
}

int binarysearch(int arr[], int lenarr, int target) {

  int L = 0, R = lenarr - 1;
  while (L <= R) {
    int midpoint = L + floor((R - L) / 2);
    if (target == arr[midpoint])
      return midpoint;
    else if (target > arr[midpoint])
      L = midpoint + 1;
    else
      R = midpoint - 1;
  }
  return -1;
}

void printarr(int arr[], int lenarr) {
  cout<<">> Array : ";
  for (int i = 0; i < lenarr; i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
}