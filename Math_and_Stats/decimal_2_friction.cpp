#include<bits/stdc++.h>
using namespace std;
long gcd(long a, long b) {
      if (b == 0) return a;
   return gcd(b, a%b);
}

int main() {
   string a,b,c;
   cin>>a>>b>>c;
   string down1 ;
   for(int i = 0 ;i<c.length();i++){
      down1 += "9";
   }
   string down2;
   for(int i = 0 ;i<b.length();i++){
      down2 +="0";
   }

   int d = stoll(down1+down2);
   int up = stoll(b+c)-stoll(b);
   int sum = stoll(a)*d+up;
   int div = gcd(sum,d);
   cout<< sum/div<<" / "<<d/div;    
}