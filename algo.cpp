#include <fstream>      //File Stream Library
#include <algorithm>    //Sort Function Library
#include <array>
#include <cmath>        //math library     
#include <chrono>       //Time library
#include "main.h"


//Sorting Algorithms

//Insertion Sort
void insertionSort(int arr[], int l){

    //Will take forever
    if (l == 1000000)return;

    for(int i = 0; i < l-1; i++){
        if(arr[i] > arr[i+1]){
            //Switcheru
            int j = i;
            while(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                
                //Edge case
                if(j==0) break;

                j--;
            }
        }
    }
} 



//Merge Sort
void mergeSort(int arr[], int l){
    //Do something

    mergeSort(arr,0,l-1);

}

void mergeSort(int arr[], int start, int end){

    if(start < end){
        //mid point
        int mid = start+(end-start)/2;
        //Spliting array
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        //Sorting and merging
        merge(arr, start, mid, end);
    }

}

void merge(int arr[], int start, int mid, int end){

    //Create Two Sub-arrays
    int a1 = mid - start+1;
    int a2 = end - mid;
    int arr1[a1], arr2[a2];

    //Copy arry
    for (int i = 0; i < a1; i++) arr1[i] = arr[start + i];;
    for (int i = 0; i < a2; i++) arr2[i] = arr[mid + 1 + i];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    //Sort the values
    while (i < a1 && j < a2) {
    if (arr1[i] <= arr2[j]) {
      arr[k] = arr1[i];
      i++;
    } else {
      arr[k] = arr2[j];
      j++;
    }
    k++;
   }

    //Add rest of values
    while (i < a1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < a2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

}





//Heap Sort
void heapSort(int arr[], int l){

     // Build max heap
    for (int i = (l / 2) - 1; i >= 0; i--){
        heap(arr, l, i);
    } 

    // Heap sort
    for (int i = l - 1; i >= 0; i--) {
        swap(arr, 0, i);
        heap(arr, i, 0);
    }
}

void heap(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[large])
        large = l;

    if (r < n && arr[r] > arr[large])
        large = r;

    // Swap and continue heapifying if root is not largest
    if (large != i) {
        swap(arr, i, large);
        heap(arr, n, large);
    }
}

void swap(int arr[],int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}





//Quick Sort Friver
void quickSort(int arr[], int l){
    
    quickSort(arr, 0, l);
}

//Recursive
void quickSort(int array[], int start, int end) {
  if (start < end) {
      
    // find the pivot point
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, start, end);

    // recursive call on the left of pivot
    quickSort(array, start, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, end);
  }
}
// function to rearrange array and find pivot point
int partition(int array[], int start, int end) {
    
  // select the rightmost element as pivot
  int pivot = array[end];
  
  // pointer for greater element
  int i = (start - 1);

  // compare them with the pivot
  for (int j = start; j < end; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(array, i, j);
    }
  }
  
  // swap pivot with the greater element at i
  swap(array, i+1, end);
  
  // return the pivot point
  return (i + 1);
}



//Quick Sort Random
void quickSortran(int arr[], int l){
    
    quickSortran(arr, 0, l);
}

void quickSortran(int array[], int start, int end) {

  if (start < end) { 
    // find the pivot point
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition_r(array, start, end);

    // recursive call on the left of pivot
    quickSortran(array, start, pi - 1);

    // recursive call on the right of pivot
    quickSortran(array, pi + 1, end);
  }
}

int partition_r(int arr[], int start, int end)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = start + rand() % (end - start);
 
    // Swap A[random] with A[high]
    swap(arr , random, end);

    //Call normal pivot
    return partition(arr, start, end);
}




//Radix Sort
void radixSort(int arr[], int l){
    // Get max
  int max = getMax(arr, l);

  // Apply counting sort 
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(arr, l, place);
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i){
    count[i] = 0;
    }
  // Calculate count 
  for (int i = 0; i < size; i++){
    count[(array[i] / place) % 10]++;
  }
  // Calculate ccount
  for (int i = 1; i < max; i++){
    count[i] += count[i - 1];
  }
  // Place sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

int getMax(int arr[], int l){
    int max = 0;
    for(int i=0; i< l; i++) if(arr[i] > max) max = arr[i];
    return max;
}
