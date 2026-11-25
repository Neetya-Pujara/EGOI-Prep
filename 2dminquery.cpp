#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<vector<vector<int>>> minGrid(20);
int n;

void init(vector<vector<int>> arr){
    a=arr;
    n = a.size();
    for (int r = 0; r < n; r++) {
        vector<vector<int>> bl;
        minGrid.push_back(bl);
        for (int c = 0; c < n; c++) {
            minGrid[0][r].push_back(a[r][c]);
        }
    }

    for (int len = 1; )
}
int query(int a, int b, int c, int d){

}

int main() {

}