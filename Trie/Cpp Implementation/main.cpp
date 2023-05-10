#include<bits/stdc++.h>

#define is ==

using namespace std;

typedef struct Trie{
    bool isend;
    struct Trie* child[26];
}Trie;


// Constructor of Trie
// Initializes isend to false and memset array to NULL
Trie* getNode(){
    Trie* temp = new Trie;
    temp->isend = false;

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

    curr->isend = true;
    return;
}

bool search(Trie* root, string searchKey){
    if(root == NULL)return false;

    Trie* curr = root;
    for(int i = 0; i < searchKey.length(); i++){
        int index = searchKey[i] - 'a';
        
        if(curr->child[index]){
            curr = curr->child[index];
        }
        else return false;
    }
    return true;
}

Trie* buildTrie(const vector<string>vec){
    Trie* root = getNode();

    for(auto i : vec){
        insert(root,i);
    }

    return root;
}

int main(){

        vector<vector<string>>res;
        
        Trie* root = getNode();
        int n = 3;
        string contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"};
        string s = "geeips";

        for(int i = 0;i < n; ++i){
            insert(root,contact[i]);
        }
        
        string key = "";
        key.empty();
        
        for(int i = 0; s[i] != '\0'; i++){
            key += s[i];
            vector<string>temp = {};
            
            for(int j = 0; j < n; j++){
                if(search(root,key) && search(root,contact[j])){
                    temp.push_back(contact[j]);
                }
            }
            
            if(temp.empty()) res.push_back({"0"});
            else res.push_back(temp);
        }
        
        for(auto i : res){
            for(auto j : i){
                cout << j << " ";
            }
            cout << "\n";
        }

        return 0;
}