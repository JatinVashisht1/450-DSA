#include<iostream>
using namespace std;

void merge(int* A, int low, int mid, int high){
    int B[100]; // to store sorted elements during sorting process

    int i = low;
    int j = mid+1;
    int k = low;

    
    while(i<=mid && j <= high){
        if(A[i] > A[j]){
            B[k] = A[i];
            k++;
            i++;
        }else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k]=A[j];
        k++;
        j++;
    }
    for(i = low; i<=high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int* A, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        merge(A, low, mid, high);
    }
}

void printArray(int* arr, int len){
    for(int i = 0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int a[5] = {3, 2, 5, 1, 8};
    printArray(a, 5);
    mergeSort(a, 0, 4);
    printArray(a, 5);
return 0;
}