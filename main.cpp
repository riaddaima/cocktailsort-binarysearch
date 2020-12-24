#include <iostream>
#include "header.h"
using namespace std;

int issorted = 0;

int main() {
    int arr[] = {4, 3, 10, 5, 8, 2};
    size_t lenarr = sizeof(arr) / sizeof(int);
    int choice;
    do {
        choice = menu();
        switch (choice) {
        //Sort Array.
        case 1:
            if (issorted)
                cout<<">> Array already sorted.\n";
            else {
                quicksort(arr, 0, lenarr-1);
                issorted = 1;
                cout<<">> Array sorted successfully!\n";
            }
            break;
        //Binary Search.   
        case 2:
            if (issorted) {
                int target, result;
                cout<<">> Enter the number to find : ";
                cin>>target;
                result = binarysearch(arr, lenarr, target);
                if (result != -1)
                    cout<<">> "<<target<<" found at index : "<<result<<"\n";
                else
                    cout<<">> "<<target<<" was not found in the array.\n";
            }
            else
                cout<<">> Error : Array not sorted.\n";
            break;
        //Print Array.
        case 3:
            printarr(arr, lenarr);
            break;
        }
    } while (choice != 4);
    cout<<"Exited.\n";
}
