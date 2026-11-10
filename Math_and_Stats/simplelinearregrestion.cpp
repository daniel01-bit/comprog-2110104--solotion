#include <bits/stdc++.h>
using namespace std;

float m =0;

float findm(vector<pair<float,float>> v ){
    float upr =0,upl1=0,upl2=0,dr=0;
    int n = v.size();
    for(int i=0;i<n;++i){
        upr += v[i].first*v[i].second ;
    }
    for(int i=0;i<n;++i){
        upl1 += v[i].first ;
    }
     for(int i=0;i<n;++i){
        upl2 += v[i].second ;
    }
    for(int i=0;i<n;++i){
        dr += (v[i].first)*(v[i].first) ;
    }
    m = (n*upr - upl1*upl2)/(n*dr-(upl1*upl1));
    return m ;
}
float findb(vector<pair<float,float>> v ){
    float b ;
    int n = v.size();
     float upl1=0,upl2=0;
    for(int i=0;i<n;++i){
        upl2 += v[i].second ;
    }
    for(int i=0;i<n;++i){
        upl1 += v[i].first ;
    }
    b = (upl2-(m*upl1))/n;
    return b ;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<float,float>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    float m = findm(v);
    float b = findb(v);
    m = round(m*1e3)/1e3;
    b = round(b*1e3)/1e3;
    if (m == 0) m = 0;
    if (b == 0) b = 0;

    if (s == "mb") {
        cout << m << "\n" << b << "\n";
    } 
    else if (s == "func") {
    
        if (m == 0) {
            cout << "y = " << b << "\n";
            return 0;
        }

        cout << "y = ";
        if (m == 1) {
            cout << "x";
        } else if (m == -1) {
            cout << "-x";
        } else {
            cout << m << "x";
        }

    
        if (b > 0) {
            cout << " + " << b;
        } else if (b < 0) {
            cout << " - " << abs(b);
        }
        cout << "\n";
    }
}