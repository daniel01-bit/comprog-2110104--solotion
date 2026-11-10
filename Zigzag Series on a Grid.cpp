#include <bits/stdc++.h>
using namespace std;


int cursora(int n, vector<vector<int>> v,vector<pair<int,int>> & c){
    int sum =0;
    int k=0;
    for(int i=0;i<n;i++){
        if(k == (n*n)-1)break;
        if(i%2==0){
            for(int j=0;j<n;j++){
                if(k%2==0){
                    sum -=v[i][j];
                }
                else{
                    sum +=v[i][j];
                }
                c.push_back({i,j});
                k++;

            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                if(k%2==0){
                    sum -=v[i][j];
                }
                else{
                    sum +=v[i][j];
                }
                c.push_back({i,j});
                k++;
            }
        }
    }
    return sum ;
}
int cursorb(int n, vector<vector<int>> v,vector<pair<int,int>> & c){
    int sum = 0;
    int row = 0, col = 0;
    for (int i = 0; i < n * n; i++) {
        c.push_back({row, col});
        
        int val = v[row][col];
        if (val % 2 == 0) {
            sum += val;
            row = (((row + val) % n) + n) % n;
            col = (((col + val + 1) % n) + n) % n;
        } else {
            sum -= val;
            row = (((row + val) % n) + n) % n;
            col = (((col - val - 1) % n) + n) % n;
        }
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n,0)) ;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>v[i][j];
        }
    }
    vector<pair<int,int>> c1,c2;
    int nn ;
    cin>>nn;
    int suma = cursora(n,v,c1) ;
    int sumb =  cursorb(n,v,c2) ;
    int k =0;
    for (int t = 0; t < n * n; ++t) {
        if (c1[t] == c2[t]) {
            int x = c1[t].first;
            int y = c1[t].second;
            if (v[x][y] % 2 == 0) {
                sumb -= v[x][y];
            } else {
                sumb += v[x][y];
            }
            k++;
        }
    }
    if(nn ==1){
        if(suma > sumb){
            cout<<"A "<<suma<<" "<<sumb;
        }
        else if(sumb > suma){
            cout<<"B "<<suma<<" "<<sumb;
        }
        else{
             cout<<"EQUAL "<<suma<<" "<<sumb;
        }
    }
    if(nn ==2){
        cout<<k;

    }
}