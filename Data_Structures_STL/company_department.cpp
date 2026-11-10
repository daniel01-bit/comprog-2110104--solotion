#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,v;
    cin>>n>>v;
    map<string,set<string>> m ;
    for(int i=0;i<n;++i){
        string s,a;
        cin>>s>>a;
        m[a].insert(s);
    }
    for(int i=0;i<v;++i){
        int k;
        string s,a;
        cin>>k;
        if( k == 1){
            cin>>s>>a;
            for(auto & [x,y] : m){
                y.erase(s);
            }
            m[a].insert(s);
        }
        string s1,s2;
        if( k == 2){
            cin>>s1>>s2;
            m[s2];
            for(auto & y : m[s1]){
                m[s2].insert(y);
            }
            m.erase(s1);
        }
    }
    for(auto [x,y] : m){
            cout<<x<<": ";
            for( auto s : y){
                cout<<s<<" ";
            }
            cout<<"\n";
    }
}