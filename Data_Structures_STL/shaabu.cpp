#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    deque<pair<string ,int>> s,l ;
    deque<string> seat,walk ;
    for(int i=0;i<k;++i){
        string s2;
        cin>>s2;
        string s1;
        int p;
        if(s2 == "ARRIVE" ){
            cin>>s1>>p;
            if(p>=3){
                if (m > 0) {
                    seat.push_back(s1);
                    m--;
                } else if (l.size() < 3) { 
                    l.push_back({s1, p});
                } else {                  
                    walk.push_back(s1);
                }
            }
            else{
                if (n > 0) {
                    seat.push_back(s1);
                    n--;
                } else if (s.size() < 3) {
                    s.push_back({s1, p});
                } else {
                    walk.push_back(s1);
                }
            }
        }
        else if(s2 == "LEAVE" ){
            cin>>s1;
            if(s1 == "L"){
                l.pop_front();
                m++;
            }
            if(s1 == "S"){
                s.pop_front();
                n++;
            }
        }
        if( n > 0 && !s.empty()){
            seat.push_back((s.front()).first);
            s.pop_front();
            n--;
        }
        if( m > 0  && !l.empty()){
            seat.push_back((l.front()).first);
            l.pop_front();
            m--;
        }
    }
    cout<<"Seated: ";
    for(int i=0;i<seat.size();++i){
        cout<<seat[i]<<" ";
    }
    cout<<"Quene S: ";
   for(int i=0;i<s.size();++i){
        cout<<s[i].first<<" ";
    }
     cout<<"Quene L: ";
    for(int i=0;i<l.size();++i){
        cout<<l[i].first<<" ";
    }
    cout<<"Walked Away: ";
    for(int i=0;i<walk.size();++i){
        cout<<walk[i]<<" ";
    }
} 