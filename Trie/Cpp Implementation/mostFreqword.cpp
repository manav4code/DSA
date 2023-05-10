#include<bits/stdc++.h>

using namespace std;

typedef struct Trie{
    bool isend;
    int count;
    struct Trie* child[26];
}Trie;

Trie* getNode(){
    Trie* temp = new Trie;
    temp->isend = false;
    temp->count = 0;

    for(int i = 0 ; i < 26; ++i){
        temp->child[i] = NULL;
    }

    return temp;
}

void insert(Trie* root,string key){
    Trie* curr = root;

    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';

        if(curr->child[index] == NULL){
            curr->child[index] = getNode();
        }

        curr = curr->child[index];
    }

    if(!curr->isend){
        curr->isend = true;
    }
    curr->count++;
    return;
}

int searchString(Trie* root, string searchKey){
    if(root == NULL)return false;

    Trie* curr = root;
    for(int i = 0; i < searchKey.length(); i++){
        int index = searchKey[i] - 'a';
        
        if(curr->child[index]){
            curr = curr->child[index];
        }
        else return -1;
    }
    if(curr->isend){
        curr->isend = false;
        return curr->count;
    }
    return -1;
}


// int main(){
//     string arr[] = {"hello","world"};
//     Trie* root = getNode();

//     for(auto i : arr){
//         insert(root,i);
//     }

//     int maxFreq = INT_MIN;
//     string res;
//     for(auto i : arr){
//         int temp = searchString(root,i);
        
//         if(maxFreq <= temp){
//             res = i;
//             maxFreq = temp;
//         }
//     }

//     cout << "Ans: "<< res << "\n";
    
//     system("pause");
//     return 0;
// }


int main(){
    int first,second;
    first = second = INT_MIN;


    return 0;
}