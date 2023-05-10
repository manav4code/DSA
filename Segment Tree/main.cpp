#include<bits/stdc++.h>
#define SIZE (1000)

using namespace std;

int arr[SIZE],seg[2*SIZE - 1];

// Sum segment tree
void build(int ind,int low,int high){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high)/2;
    build(2*ind + 1,low,mid);
    build(2*ind+2,mid+1,high);

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}

int query(int ind, int low,int high,int l, int r){
    if(low >= l && high <= r){
        // Inside Query Segment
        return seg[ind];
    }

    if(high < l || low > r){
        // Outside Segment
        return 0;
    }

    int mid = (low + high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);

    return left + right;

}

void printArray(int arr[],int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
    return;
}

int main(int argc,char** argv){
    int size = (int)(*argv[1] - '0');
    for(int i = 0; i < size; ++i){
        cin >> arr[i];
    }

    printArray(arr,size);
    build(0,0,size-1);

    cout << "Enter Query: ";
    int l,r;
    cin >> l >> r;

    cout << "Search Result: ";
    cout << query(0,0,size-1,l,r);
    
    return 0;
}