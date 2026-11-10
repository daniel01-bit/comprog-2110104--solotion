#include <bits/stdc++.h>
using namespace std;


struct  selectX{
    double p;
    string s[4];
    string n ;

    bool operator<(const selectX& other) const {
        if (p != other.p) {
            return p > other.p;
        }
        return n < other.n;
    }
    
};



int main() {
   int n ;
   cin>>n;
   map<string,int> m;
   for(int i=0;i<n;++i){
     string s; int ss;
     cin>>s>>ss;
     m[s] =ss;
   }
   int mm;
   cin>>mm;
   vector<selectX> v(mm);
   for(int i=0;i<mm;++i){
        cin>>v[i].n>>v[i].p>>v[i].s[0]>>v[i].s[1]>>v[i].s[2]>>v[i].s[3];
    }
    vector<pair<string,string>> a;
   sort(v.begin(),v.end());
   for(auto [p,s,n] : v){
        for(int i=0;i<4;++i){
            if(m[s[i]] !=0){
                m[s[i]]--;
                a.push_back({n,s[i]});
                break;
            }
        }
   }
   sort(a.begin(),a.end());
    for(auto [v1,v2] : a){
            cout<<v1<<" "<<v2<<"\n";
        
    }
  
}