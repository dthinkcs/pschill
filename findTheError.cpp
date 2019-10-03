#include <bits/stdc++.h>
using namespace std;

int pickIndex(int si, int ei) {
    return 0;
}

int partition(int* arr, int si, int ei) {
    // pick up a element 

    
    int index = pickIndex(si, ei);
    int element = arr[index];
    
    
    // find the number of elements less than that index
    int countSmaller = 0;
    for (int i = si; i <= ei; i++) {
        if (arr[i] < element)
            countSmaller += 1;
    }
    int pivot = countSmaller;
    // place the element in its proper position by swapping index, with coutSmaller
    //swap(arr[pivot], arr[index]); 
    
    // all elements to the left of newIndex must be made smaller
//     int left = si;
//     int right = ei;
//     while (true) {
//         if (arr[left] >= arr[pivot] && arr[right] < arr[pivot]) {
//             swap(arr[left], arr[right]);
//         } else if (arr[left] < arr[pivot]) {
//             left++;
//         } else if (arr[pivot] <= arr[right]) {
//             right--;
//         }
            
//         if (left == pivot || right == pivot) {
//             break;
//         }
    
//     }
    return pivot;
}

void quickSortH(int* input, int si, int ei) {
    if (si >= ei) {
        return;
    }
    
    int pivot = partition(input, si, ei);
    quickSortH(input, si, pivot - 1);
    quickSortH(input, pivot + 1, ei);

}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */

    quickSortH(input, 0, size - 1);
}
