#include <iostream>
#include <vector>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int N, int i){
    int left = 2*i + 1;
    int right = 2*i + 2;

    int largest = i;

    if(left < N && arr[left] > arr[largest]) largest = left;
    if(right < N && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr,largest,i);

        heapify(arr,N,largest);
    }
}

void heapsort(int arr[], int N){
    
    // Convert to Max Heap
    for(int i = N/2 -1; i >= 0; i--){
        heapify(arr,N,i);
    }

    for(int i = N-1; i >= 0; i--){
        swap(arr,0,i);
        heapify(arr,i,0);
    }
}

void printArray(int arr[], int N){
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;    
}

int main(){

    int arr[] = {14,2,55,23,32,100,87,49};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    printArray(arr,size);

    heapsort(arr,size);
    cout << "Sorted Array: ";
    printArray(arr,size);

    return 0;
}