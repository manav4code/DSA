#include<bits/stdc++.h>

using namespace std;

typedef struct Trie{
    struct Trie* child[26];
    int count;
    bool isend;
}Trie;

Trie* __init__(){
    Trie* temp = new Trie;
    temp->isend = false;
    temp->count = 1;

    for(int i = 0 ; i < 26; ++i){
        temp->child[i] = NULL;
    }

    return temp;
}

void insertNode(Trie* root,string key){
    Trie* curr = root;

    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';

        if(curr->child[index] == NULL){
            curr->child[index] = __init__();
            curr = curr->child[index];
        }
        else{
            curr = curr->child[index];
            curr->count += 1;
        }
    }

    curr->isend = true;
    return;
}

int helper(Trie* root,string str){
    Trie* curr = root;

    for(int i = 0; i < str.length(); ++i){
        int index = str[i] - 'a';

        if(!curr->child[index])return 0;
        
        curr = curr->child[index];
    }

    return curr->count;
}

vector<int> prefixCount(int N, int Q, string li[], string query[]){
    Trie* root = __init__();

    // Build Tree
    for(int i = 0;i < N; ++i){
        insertNode(root,li[i]);
    }

    vector<int>res = {};

    for(int i = 0; i < Q; ++i){
        int count = 0;
        count = helper(root,query[i]);
        res.push_back(count);
    }

    return res;

}


int main(){

    string li[] = {"abracadabra", "geeksforgeeks", 
      "abracadabra", "geeks", "geeksthrill"};
    int N = 5;

    string query[] = {"abr","geeks","geeksforgeeks","ge","gar"};
    int Q = 5;

    vector<int> res = prefixCount(N,Q,li,query);

    for(auto i : res){
        cout << i << " ";
    }

    return 0;

}