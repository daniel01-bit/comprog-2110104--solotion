#include <bits/stdc++.h>
using namespace std;


struct student {
    string id ;
    double grade;
    int act ;
    int fin ;
};

bool compareQ(student a, student b){
    if(a.grade != b.grade) return a.grade > b.grade;
    if(a.fin != b.fin) return a.fin < b.fin ;
    return a.id < b.id ;
}
bool compareWQ(student a, student b){
    if(a.grade != b.grade) return a.grade > b.grade;
    if(a.act != b.act) return a.act > b.act ;
    return a.id < b.id ;
}

bool compareUQ(student a, student b){
    if(a.id != b.id)return a.id < b.id ;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    vector<student> Q,W,UQ;
    while(cin>>s){
        if(s=="END")break;
        double g;
        int act,fin;
        cin>>g>>act>>fin;
        if(g >= 3.75 && fin < 300000){
            Q.push_back({s,g,act,fin});
        }
        else if(g >= 3.50 && act >= 100){
            W.push_back({s,g,act,fin});

        }
        else{
            UQ.push_back({s,g,act,fin});
        }
    }
    sort(Q.begin(),Q.end(),compareQ);
    sort(W.begin(),W.end(),compareWQ);
    sort(UQ.begin(),UQ.end(),compareUQ);

    if(!Q.empty()){
        cout<<"Qualified\n";
        for(auto [id,g,act,fin] : Q){
            cout<<id<<"\n";
        }
    }
    if(!W.empty()){
        cout<<"Waiting List\n";
        for(auto [id,g,act,fin] : W){
            cout<<id<<"\n";
        }
    }
    if(!UQ.empty()){
        cout<<"Unqualified\n";
        for(auto [id,g,act,fin] : UQ){
            cout<<id<<"\n";
        }
    }
}