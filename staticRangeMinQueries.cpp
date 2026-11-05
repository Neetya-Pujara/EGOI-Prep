#include <bits/stdc++.h>
using namespace std;
//solution uses sparse table; question is template sparse table prob.

int main() {
    //input
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> pw(20);
    pw[0]=1;
    for (int i = 1; i < 20; i++) pw[i]=pw[i-1]*2;
    //make sparse table
    vector<vector<int>> minGrid;
    vector<int> blank;
    minGrid.push_back(blank);
    for(int i = 0; i < n; i++) minGrid[0].push_back(arr[i]);
    for (int len = 1; pw[len] <= n; len++) {
        vector<int> bl;
        minGrid.push_back(bl);
        for (int st = 0; st+pw[len]<=n; st++) {
            int half=len-1;
            minGrid[len].push_back(min(minGrid[half][st], minGrid[half][st+pw[half]]));
        }
    }

    for (int i = 0; i < q; i++) {
        int a,b; cin >> a >> b;
        a--; b--;
        int needed=__bit_width(b-a+1)-1;
        cout << min(minGrid[needed][a],minGrid[needed][b-pw[needed]+1]) << endl;
    }
}