#include<iostream>

using namespace std;

void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int h){
    int i = l+1;
    int j = h;

    // First Element as Pivot
    int pivot = arr[l];

    while(i <= j){

        while (arr[i] < pivot){
            i++;
        }
        

        while(arr[j] > pivot){
            j--;
        }
        
        if(i < j){
            swap(arr,i,j);
        }
    }

    swap(arr,l,j);
    
    return j;
}

void quicksort(int arr[],int l, int h){
    if(l < h){
        int pivot = partition(arr, l, h);

        quicksort(arr, l, pivot-1);
        quicksort(arr, pivot + 1, h);
    }
}

void printArray(int arr[], int size){
    for(int i = 0;  i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    int arr[] = {4,5,2,8,1,9,10,15,6};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    printArray(arr,size);

    quicksort(arr,0,size-1);
    cout << "Sorted Array: ";
    printArray(arr,size);

    return 0;
}