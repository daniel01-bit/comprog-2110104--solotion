#include<bits/stdc++.h>

using namespace std;


int dfs(vector<string>& v,int r,int c,int n,int m){
     if (r < 0 || r >= n || c < 0 || c >= m || v[r][c] == '0') { 
          return 0; 
     }
     v[r][c] ='0';
     int size =1;

     size+= dfs(v,r-1,c,n,m);
     size+= dfs(v,r+1,c,n,m);
     size+= dfs(v,r,c-1,n,m);
     size+= dfs(v,r,c+1,n,m);

     return size;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int n,m;
     cin>>n>>m;
     vector<string> v;
     for(int i=0;i<n;++i){
          string s;
          cin>>s;
          v.push_back(s);
     }
     int isc = 0; 
     int mx = 0;
     for(int i=0;i<n;++i){
          for(int j=0;j<m;++j){
               if(v[i][j] =='1'){
                    isc++;
                    int curr = dfs(v,i,j,n,m);
                    mx =max(curr ,mx);
               }
          }
     }
     cout<<"Islands : "<<isc<<"\n";
     cout<<"Largest island size : "<<mx<<"\n";
}