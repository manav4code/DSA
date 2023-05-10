#include<bits/stdc++.h>

using namespace std;

int remove_duplicate(int a[],int n){
        int i = 0;
        int k = 0;
        
        while(k < n ){
            while(a[i] >= a[k]){
                if(k == n)return 1;
                k++;
            }
            
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
            
            i++;
        }
        return i;
    }

int main(){
    int arr[] = {2,2,2,2,2};
    int size = sizeof(arr)/sizeof(int);

    cout << remove_duplicate(arr,size);
}