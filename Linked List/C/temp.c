#include<stdio.h>
#include<stdlib.h>

void kthSum(int arr[], int k, int size){
    if(size < k)return;
    
    int sum = 0;
    for(int i = 0; i < k; ++i){
        sum += arr[i];
    }

    printf("%d ",sum);

    for(int i = k; i < size; ++i){
        sum = (sum - arr[i-k] + arr[i]);
        printf("%d ",sum);
    }
}

int main(){

    int arr[] = {1,1,2,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);

    printf("Size = %d\n",n);

    kthSum(arr,6,n);

    
    return 0;

}