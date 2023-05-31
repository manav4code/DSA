#include <iostream>
#include <queue>
#include <vector>
#include <utility>


using namespace std;

vector<vector<int>> floodFill(int initVal, int newVal, pair<int,int> pixel, vector<vector<int>> img){

    int rows = img.size();
    int cols = img[0].size();

    queue<pair<int,int>>q;
    q.push(pixel);

    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        int r = temp.first;
        int c = temp.second;


        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                // Condition to avoid Diagonal Neighbours. Case where both the offsets are non-zero.
                if(i && j) continue;



                /*
                -> Check for Valid Index else Index Error
                -> Check if the current pixel or any neighbour has initial Value.
                    If yes then update with new value and push to queue. 
                */     
                if(((r+i) >= 0 && (r+i) < rows) && ((c+j) >= 0 && (c+j) < cols) && img[r+i][c+j] == initVal){
                    img[r+i][c+j] = newVal;
                    q.push({r+i,c+j});
                }
            }
        }
    }

    return img;
}

void printImage(vector<vector<int>> img){
    for(auto row : img){
        for(auto pixel : row){
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    vector<vector<int>> img;
    
    img.push_back({1,1,1});
    img.push_back({2,2,0});
    img.push_back({2,2,2});

    printImage(img);

    int initPixelVal = 2;
    int newPixelVal = 3;

    // Take any initial pixel and check if algorithm works or not.
    pair<int,int> initPoint = {1,1};

    vector<vector<int>> res = floodFill(initPixelVal,newPixelVal,initPoint,img);
    printImage(res);

    return 0;
}