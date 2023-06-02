#include <iostream>

using namespace std;

void merge(int arr[], int p, int q, int r){

    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[p + i];
    for(int j = 0; j < n2; j++) R[j] = arr[q + j + 1];

    int i = 0, j = 0;
    int k = p;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
            k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int p, int r){
    if(p < r){
        int q = p + (r-p)/2;

        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void printArray(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {4,5,2,3,8,1,9,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array: ";
    printArray(arr,size);

    mergesort(arr,0,size-1);
    cout << "Sorted Array: ";
    printArray(arr,size);

    return 0;
}