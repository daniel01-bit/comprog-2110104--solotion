#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,vector<string>> m;
    string s1;
    while(getline(cin,s1)){
        stringstream ss(s1);
        vector<string> v;
        string val;
        while(ss>>val){
            v.push_back(val);
        }
        if(v[0]=="end")break;
        m[v[0]].push_back(v[1]);
    }
    string f;
    cin>>f;
    set<string> a;
     a.insert(f);
    for(auto x : m[f]){
        a.insert(x);
    }
    for(auto [x,v] : m ){
        for(auto c : v){
            if(c==f){
                a.insert(x);
                a.insert(c);
            }
        }
    }
    set<string> temp ;
    for(auto x : a){
        for(auto in : m[x]){
                temp.insert(in);
        }
    }
    for(auto [x,v] : m ){
        for(auto c : v){
            if(a.count(c)){
                temp.insert(x);
            }
        }
    }
     for(auto x : temp){
        a.insert(x);
    }
    for(auto x : a){
        cout<<x<<" \n";
    }
}