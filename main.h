#ifndef main_h_
#define main_h_


//Sorting Algorithms
void insertionSort(int arr[], int l);

void mergeSort(int arr[], int l);
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

void heapSort(int arr[], int l);
void heap(int arr[], int n, int i);
void swap(int arr[],int a, int b);

void quickSort(int arr[], int l);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);

void quickSortran(int arr[], int l);
void quickSortran(int array[], int low, int high);
int partition_r(int arr[], int low, int high);

void radixSort(int arr[], int l);
void countingSort(int array[], int size, int place);
int getMax(int arr[], int l);





#endif