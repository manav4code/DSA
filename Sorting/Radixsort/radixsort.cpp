#include <iostream>
#include <vector>

using namespace std;

int getMax(int arr[], int size){
    int max = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void radixsort(int arr[],int size){
    int maxnum = getMax(arr,size);
    int exp = 1;
    while(maxnum){
        vector<vector<int>> hash(10);
        for(int j = 0; j < size; j++){
            int hf = (arr[j]/(exp))%10;
            hash[hf].push_back(arr[j]);
        }

        int index = 0;
        for(int j = 0; j < 10; j++){
            if(!hash[j].empty()){
                for(auto it: hash[j]){
                    arr[index++] = it;
                }
            }
        }

        exp*=10;
        maxnum /= 10;
    }
}

void printArray(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {3,5,2,6,1,7,100,45,36,9};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    printArray(arr,size);

    radixsort(arr,size);
    cout << "Sorted Array: ";
    printArray(arr,size);

    return 0;
}