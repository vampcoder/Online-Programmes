#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

int read_int() {
    register char c=gc();
    while(c<'0'||c>'9')
        c=gc();  //ignore all characters till the first digit
    int ret=0;
    while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
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
int main() {
    int t = read_int();
    int g;

    while(t--){
        int n = read_int();
        int a[n];
        g = 0;
        for(int i = 0; i < n; i++){
            a[i] = read_int();
            if(g == 1){
                continue;
            }
            if(i > 1){
                g = gcd(g, a[i]);
            }else if(i == 1){
                g = gcd(a[0], a[1]);
            }
        }
       // cout << "g : " << g << endl;
            for(int i = 0; i < n - 1; i++){
                printf("%d ",a[i]/g);
            }
            printf("%d\n", a[n-1]/g);
            /*
            for(int i = 0; i < n - 1; i++){
            printf("%d ",a[i]);
            }
            printf("%d\n", a[n-1]);
        }*/
    }
}
