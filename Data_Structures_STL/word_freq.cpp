#include<bits/stdc++.h>

using namespace std;

bool jj(const pair<int,string>& p ,const pair<int,string>& d){
     return make_tuple(-(p.first) , -(int)((p.second).length()) ,(p.second)) < make_tuple(-(d.first) , -(int)((d.second).length()) ,(d.second)) ;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    map<string,int> m ;
     string a ="";
    while(getline(cin,s)){
          if(s=="END")break;
          for(int i=0;i<s.length();++i){
               if(isupper(s[i]) || islower(s[i])){
                    a += tolower(s[i]);
               }
               else{
                    if(a.length() >= 2){
                         m[a]++;
                    }
                     a="";
               }
          }
          if (a.length() >= 2) { 
               m[a]++;
          }
          a="";
    }
    int n ;
    cin>>n;
    vector<pair<int,string>> v;
    for(auto [x,y] : m){
          v.push_back({y,x});
    }
    if (v.empty()) { 
          cout << "No words found\n"; return 0; 
     }
    sort(v.begin(),v.end(),jj);
    int limit = min((int)v.size(), n);
    for(int i =0;i<limit;++i){
          cout<<v[i].second<<": "<<v[i].first<<"\n";
    }

}