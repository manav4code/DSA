#include<bits/stdc++.h>

using namespace std;

typedef struct Trie{
    bool isend;
    struct Trie* child[26];
}Trie;


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
        if(curr->isend)curr->isend = false;
    }

    curr->isend = true;
    return;
}

bool search(Trie* root, string searchKey){
    if(root == NULL)return false;

    Trie* curr = root;
    for(int i = 0; i < searchKey.length(); i++){
        
        if(curr->isend)return true;
        
        int index = searchKey[i] - 'a';
        
        if(curr->child[index]){
            curr = curr->child[index];
        }
        else return false;
    }
    
    return true;
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>>res;
        
        Trie* root = getNode();
        
        // for(int i = 0;i < n; ++i){
        //     insert(root,contact[i]);
        // }
        
        string key = "";
        
        for(int i = 0; s[i] != '\0'; i++){
            key += s[i];
            vector<string>temp = {};
            insert(root,key);
            for(int j = 0; j < n; j++){
                if(search(root,contact[j])){
                    temp.push_back(contact[j]);
                }
            }
            
            if(temp.empty()) res.push_back({"0"});
            else res.push_back(temp);
        }
        
        return res;
    }

int main(){
    string contact[] = {"geeikistest", "geeksforgeeks", 
        "geeksfortest"};

    int n = 3;

    string s = "geeips";

    vector<vector<string>> res = displayContacts(n,contact,s);

    for(auto i : res){
        for(auto str : i){
            cout << str << " ";
        }
        cout << "\n";
    }

    return 0;
}