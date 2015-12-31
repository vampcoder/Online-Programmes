#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
#include<vector>
#include<cmath>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
#define ll long long int
using namespace std;

int read_int()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
int ret=0;
while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}
int gcd(int a, int b) {
  int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main()
{
    int t = read_int();
    while(t--){
        int a = read_int();
        int b = read_int();
        int g = gcd(a, b);
        int c= a/g;
        int d = b/g;
        double x = (3*c - 2*d);
        if(c/(double)d  > 2/(double)3){
            double p = x/(double)5;
            double z = 0.0;
            //cout << g << endl;
            if((p-floor(p)) == z){
                printf("%d\n", (int)p*g);
            }else{
                printf("-1\n");
            }
        }else if(c/(double)d  < 2/(double)3){
            double p = (-1)*x/(double)5;
            double z = 0.0;
            if((p-floor(p)) == z){
                printf("%d\n", (int)p*g);
            }else{
                printf("-1\n");
            }
        }else{
            printf("0\n");
        }
    }
}
