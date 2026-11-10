#include <bits/stdc++.h>
using namespace std;


int main(){

   int n,m;
   cin>>n>>m;
   multiset<int> power ;
   for(int i=0;i<n;++i){
        int a;
        cin>>a;
        power.insert(a);
   }
   vector<pair<string,string>> ans ;
   for(int i=0;i<m;++i){
        string op;
        cin>>op;
        if(op=="INTERCEPT"){
            int f,max;
            cin>>f>>max;
            int x = *power.lower_bound(f);
            if(*power.lower_bound(f)-f >= f-*prev(power.lower_bound(f))){
                x = *prev(power.lower_bound(f));
            }
            int diff = x - f;
            if(abs(diff) <= max){
                ans.push_back({to_string(x),to_string(abs(diff))});
                power.erase(power.find(x));
            }
            else{
                ans.push_back({"MISSED",""});
            }
        }
        if(op=="SUPPLY"){
            int a;
            cin>>a;
            power.insert(a);

        }
   }
   for(auto [x,y] : ans){
        cout<<x<<" "<<y<<"\n";
   }
}