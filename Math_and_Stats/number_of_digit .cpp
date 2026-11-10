#include <bits/stdc++.h>

using namespace std;

long long check(long long x){
    long long sum =1;
    long long st =1;
    long long length =1;
    while(st <= x){
        long long end = st*10-1;
        long long currentend = min(x,end);
        sum += (currentend - st +1)*length;
        length++;
        st *=10;
    }
    return sum;
}
int main() {
    long long m,n;
    cin>>m>>n;
    long long sum = check(n);
    long long sum2 =(m>0)? check(m-1) : 0 ;
    cout << sum - sum2 ;
}