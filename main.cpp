#include <iostream>     //Input Output Stream Library
#include <iomanip>      //Input Output Manipulate Library
#include <fstream>      //File Stream Library
#include <algorithm>    //Sort Function Library
#include <array>
#include <cmath>        //math library     
#include <chrono>       //Time library
#include "main.h"

using namespace std;
using namespace std::chrono;

//This function fill's each empty array.
void fillarr(int arr[], int l);

//Prints array
void viewarr(int arr[], int l);
//void viewarr(int arr[]);

//Creates Temporary Array
int * copyArr(int arr[], int l);

//Checks the Array
bool checkarr(int arr[], int l);

//Simple commit test

int main(){

    //2D array to store run times
    long timeData[6][6] ={0};

    //Array that stores pointers to functions
    void (*sortFunc[])(int arr[], int l) = { insertionSort, mergeSort, heapSort, quickSort, quickSortran, radixSort} ;
    int *numArr[6];

    //Time Check
    cout<< "\nCreating arrays... ";
    auto start = high_resolution_clock::now();

    //Arrary that stores unordered arrays
    for(int i = 0; i < 6; i++ ){
        int l = pow(10, i+1);
        numArr[i] = new int[l];
        fillarr(numArr[i],l);
    }

    //viewarr(numArr[4], 100000);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout<< "Elapsed time: " << duration.count() << " nanoseconds. \n";


    //Time templete
    //auto start = high_resolution_clock::now();
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    //duration.count()

    

        //Create six arrays and populate each array
        /*
        int arr1[10] = {0};
        int *a = fillarr(arr1, 10);
        //viewarr(a, 10);

        int arr2[100];
        int *b = fillarr(arr2, 100);

        int arr3[1000];
        int *c = fillarr(arr3, 1000);

        int arr4[10000];
        int *d = fillarr(arr4,10000);

        int arr5[100000];
        int *e = fillarr(arr5,100000);

        int arr6[1000000];
        int *f = fillarr(arr6,1000000);
        */



    //Begin to use sorting algorithms
    cout << "\nRunning Sorting algorithms... \n\n";
    for(int i = 0; i < 6; i++){ //ONly first 4 rows
        for(int j = 0; j < 6; j++){
            //Create temporary arry
            int l = pow(10,i+1);
            int* temp = copyArr(numArr[i],l);

            //Start time
            start = high_resolution_clock::now();

            //feed temporary arry to this function
            (*sortFunc[j])(temp, l);

            //End time
            stop = high_resolution_clock::now();
            duration = duration_cast<nanoseconds>(stop - start);

            //Check arr
            if(checkarr(temp, l)){
                //Store time
                timeData[i][j] = duration.count();
                //viewarr(temp, l);
            }else{
                //Store time
                timeData[i][j] = 0;
            }

            //delete temporary arry
            delete temp;
        }
    }

    //Print Time Data
    cout << left << "N\t\tInsertion\tMerge\t\tHeap\t\tQuick\t\tQuick Random\tRadix \n";
    for(int i = 0; i < 6; i++){
        cout  << setw(10) << pow(10,i+1) << "\t" << left;
        for (const auto &value: timeData[i]) {
            std::cout << setw(10) << value << '\t';
        }
        cout <<"\n";
    }
    cout << "\nThank You Profesor!\n\n";

    //Print Time Data to file
    ofstream myfile;
    myfile.open ("time.txt");
    myfile << left << "N\t\tInsertion\tMerge\t\tHeap\t\tQuick\t\tQuick Random\tRadix \n";
    for(int i = 0; i < 6; i++){
        myfile  << setw(10) << pow(10,i+1) << "\t" << left;
        for (const auto &value: timeData[i]) {
            myfile << setw(10) << value << '\t';
        }
        myfile <<"\n";
    }
    myfile << "\nThank You Profesor!\n\n";
    myfile.close();

    
    //Free memory, no memory leaks
    for(int i = 0; i< 6; i++){
        delete [] numArr[i];
    }
   
}

//This function fills each empty array.
void fillarr(int arr[], int l){
   
    for( int i = 0; i < l; i++){
        //Sets the range of the random numbers 0- 1000
        arr[i] = rand() % 1001;
    }

    return;
}

//Prints the array
void viewarr(int arr[], int l){
    std::cout << " Arrary: [ ";
    for(int i = 0; i < l; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}

//This function copy's the array into a temporary one
int * copyArr(int arr[], int l){

    
    int *temp = new int[l];

    for(int i = 0; i < l; i++){
        temp[i] = arr[i];
    }

    return temp;
}

//Check Sorted
bool checkarr(int arr[], int l){

    //Acending order
    for(int i = 1; i< l; i++){
        if (arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}