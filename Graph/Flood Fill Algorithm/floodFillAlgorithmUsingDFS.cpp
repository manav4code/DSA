#include <iostream>
#include <vector>

using namespace std;

void dfs(int r,int c, int initVal, vector<vector<int>> &ans, vector<vector<int>> &img, int drow[], int dcol[], int newVal){

    int n = img.size();
    int m = img[0].size();

    ans[r][c] = newVal;

    for(int i = 0; i < 4; i++){
        int nrow = r + drow[i];
        int ncol = c + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && img[nrow][ncol] == initVal && ans[nrow][ncol] != newVal){
            dfs(nrow,ncol,initVal,ans,img,drow,dcol,newVal);
        }
    }
}

vector<vector<int>> floodFill(pair<int,int> src, vector<vector<int>> &img, int newVal){
    
    vector<vector<int>> ans = img;

    int row = src.first;
    int col = src.second;

    int initVal = img[row][col];
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    dfs(row,col,initVal,ans,img,drow,dcol,newVal);
    return ans;

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

    int newPixelVal = 5;

    // Take any initial pixel and check if algorithm works or not.
    pair<int,int> initPoint = {1,1};

    vector<vector<int>> res = floodFill(initPoint,img,newPixelVal);
    printImage(res);

    return 0;
}