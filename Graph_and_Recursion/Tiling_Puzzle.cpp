#include<bits/stdc++.h>

using namespace std;

int main() {
    int n ;
    cin>>n;
    int v[n][n];
    int mem_zero ;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            if(v[i][j] == 0){
                mem_zero = i ;
            }
        }
    }
    int ic =0;
    int a[n-1];
    int k =0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j] != 0){
                a[k] = v[i][j];
                k++;
            }
        }
    }
    for(int i =0;i<k;i++){
        for(int j =i;j<k;j++){
            if(a[i] > a[j]){
                ic++;
            }
        }
    }
    string s ="NO";
    if(n % 2!=0){
        if(ic % 2 ==0){
            s ="YES";
        }
    }
    else{
        if(ic % 2 ==0){
            if(mem_zero % 2 != 0){
                s ="YES";
            }
        }
        else{
             if(mem_zero % 2 == 0){
                s ="YES";
            }
        }
    }
    cout<<s;
}