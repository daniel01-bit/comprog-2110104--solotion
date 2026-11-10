#include <bits/stdc++.h>
using namespace std;



int way(int col, int rol, int n, const vector<vector<int>>& a){
    if (col >= n || rol >= n) return 0;
    if(a[col][rol] ==1){
        return 0;
    }
    if(col == n-1 && rol == n-1){
        return 1;
    }
   return way(col+1,rol,n,a) +  way(col,rol+1,n, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n ;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0)) ;
    for(int i =0;i<n;++i){
         for(int j =0;j<n;++j){
            cin>>a[i][j];
        }
    }

    cout<<way(0, 0, n, a);

  
} 