#include <bits/stdc++.h>
using namespace std;


void solve(int k,tuple<int,string,string>&v, vector<pair<string,int>> p,  vector<int> l ){
    int n = k;
    for(auto x : l){
       if (n == x) {
             n = x + 1;
        } else if (n == x + 1) {
                n = x;
        }
    }
    get<0>(v) = p[n-1].second;
    get<2>(v) = p[n-1].first;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin>>n>>m>>q;
    map<int,tuple<int,string,string>> map;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        map[i+1] = make_tuple(0,s,"");
    }
    vector<pair<string,int>> p(n);
    for(int i=0;i<n;++i){
      cin>>p[i].first>>p[i].second;  
    }
    vector<int> l(m) ;
    for(int i=0;i<m;++i){
        cin>>l[i];
    }
    vector<tuple<int,string,string>> ans ;
    for(auto & [k,v] : map){
        solve(k,v,p,l);
        ans.push_back(v);
    }
    for(auto &[x,y,z] : ans){
       x*=-1;
    }
    sort(ans.begin(),ans.end());
    vector<pair<string,string>> a;
    for(int i=0 ;i<q;++i){
        string s ;
        int n ;
        string name;
        cin>>s;
        if(s=="rank"){
            cin>>n;
            a.push_back({get<1>(ans[n-1]),get<2>(ans[n-1])});
        }
        else if(s=="name"){
            cin>>name;
            for(auto [x,y,z] : ans){
                if(name == y){
                   a.push_back({z,to_string(-x)});
                }
        }
           
        }
    }
    for(auto [x,y] : a){
        cout<<x<<" "<<y<<"\n";
    }

   
} 