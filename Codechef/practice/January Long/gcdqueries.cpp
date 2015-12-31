#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
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
    int t;
    t = read_int();
    for(int i = 0; i < t; i++){
        int n, q;
        n = read_int();
        q = read_int();
        int g = 0;
        int a[n+7];
        int prefix[n+7];
        int postfix[n+7];
        int l, r;
        prefix[0] = 0;
        for(int j = 0; j < n; j++) {
            a[j] = read_int();
            if(j == 1){
                prefix[j] = a[j-1];
            }else if(j > 1){
                if(prefix[j-1] == 1){
                    prefix[j] = 1;
                }else{
                    prefix[j] = gcd(prefix[j-1], a[j-1]);
                }
            }
        }
        cout << "prefix ";
        for(int j = 0; j < n; j++){
            cout<< prefix[j] << " ";
        }
        cout << endl;
        cout << "postfix ";

        postfix[n -1] = 0;
        postfix[n-2] = a[n-1];
        for(int j = n-1; j >= 0; j--) {
            if(j < n-2){
                if(postfix[j+ 1] == 1){
                    postfix[j] = 1;
                }else{
                    postfix[j] = gcd(postfix[j+1], a[j+1]);
                }
            }
        }
        for(int j = 0; j < n; j++){
            cout<< postfix[j] << " ";
        }
        cout << endl;
        for(int j = 0; j < q; j++){
            l = read_int() - 1;
            r = read_int() - 1;
            printf("%d\n", gcd(prefix[l], postfix[r]));
        }
    }
    return 0;
}
