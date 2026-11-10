#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    map<string,tuple<int,int,int>> m ;
    vector<tuple<string,int,int,string>> v;
    map<string,int> c ;
    for(int i=0;i<n;++i){
        string name,art;
        int price;
        cin>>name>>art>>price;
        v.push_back(make_tuple(art,i,price,name));
        m[name] ={0,0,0};
        c[art]++;
    }
    sort(v.begin(),v.end());
    int max =0;
    int count =0;
    string winner ="" ;
    for(auto [art,i,price,name] : v){
        if(price >= 100){
            if(price > max){
                if(name == winner){
                      get<2>(m[name])++; 
                }
                else{
                    max = price ;
                    winner = name ;
                }
            }
            else{
                get<2>(m[name])++; 
            }
        }
        else{
            get<2>(m[name])++; 
        }
        count++;
         if(count == c[art]){
            get<0>(m[winner]) += max ;
            count = 0;
            max =0 ;
            get<1>(m[winner])++;
            winner = "";
            
        }
    }
    vector<tuple<int,int,int,string>> a;
    for( auto [name,t] : m){
        a.push_back(make_tuple(-get<0>(t),-get<1>(t),get<2>(t),name));
    }
    if (a.empty()) {
        cout << "NO WINNER\n";
        return 0;
    }
    sort(a.begin(),a.end());
    for(auto [price,item,spam,name] : a){
        if(item != 0){
        cout<<name<<" "<<-price<<" "<<-item<<" "<<spam<<"\n";
        }
    }

}