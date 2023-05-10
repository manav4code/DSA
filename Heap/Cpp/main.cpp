#include<bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[],int n){
    

    for(int i = 1; i < n/2; i++){
        if(arr[i] >= arr[2*i] && arr[i] >= arr[2*i + 1])continue;
        else return false;
    }

    return true;
}

void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void heapify(int arr[],int n,int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l < n && arr[l] > arr[largest]) largest = l;
        if(r < n && arr[r] > arr[largest]) largest = r;
        
        if(largest != i){
            swap(arr,largest,i);
            heapify(arr,n,largest);
        }
    }

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(){

    int arr[] = {-1,5,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    if(isMaxHeap(arr,size)) cout << "Max Heap!";
    else cout << "Not a Max Heap";

    // converting to max heap

    for(int i = (size/2); i >= 0; --i){
        heapify(arr,size,i);
    }
    printArr(arr,size);
    if(isMaxHeap(arr,size)) cout << "Max Heap!";
    else cout << "Not a Max Heap";

    return 0;
}