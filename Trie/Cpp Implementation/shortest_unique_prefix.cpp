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


Trie* buildTrie(const vector<string>vec){
    
    cout << "Building Trie...\n";
    
    Trie* root = __init__();

    for(auto i : vec){
        insertNode(root,i);
    }

    cout << "Built Successfully...\n";
    return root;    
}

bool searchString(Trie* root, string searchKey){
    if(root == NULL)return false;

    Trie* curr = root;
    for(int i = 0; i < searchKey.length(); i++){
        int index = searchKey[i] - 'a';
        
        if(curr->child[index]){
            curr = curr->child[index];
        }
        else return false;
    }
    if(curr->isend)return true;
    return false;
}

bool assertTrie(Trie* root, vector<string>v){
    Trie* temp = root;

    for(auto i : v){
        if(!searchString(temp,i))return false;
    }
    return true;
}

void findPrefixes(Trie* root,const vector<string>v){
    vector<string>res = {};
    Trie* curr;
    string temp = "";
    for(auto i : v){
        curr = root;
        for(int j = 0; i[j] != '\0'; j++){
            int index = i[j] - 'a';
            curr = curr->child[index];
            if(curr->count == 1){
                temp += i[j];
                res.push_back(temp);
                break;
            }
            else{
                temp += i[j];
            }
        }
        if(curr->isend and curr->count > 1)res.push_back(i);
        temp.clear();
    }

    for(auto i : res){
        cout << i << endl;
    }

}

void printVec(vector<string>vec){
    for(auto i : vec){
        cout << i << endl;
    }
    return;
}

int main(){
    vector<string>v = {"zebra", "dog", "duck", "dove","doggy","dozer","bully","bull"};
    Trie* root = buildTrie(v);
    
    if(!assertTrie(root,v)){
        cout << "Trie not built properly.";
        exit(0);
    }
    findPrefixes(root,v);

    system("pause");
    return 0;
}