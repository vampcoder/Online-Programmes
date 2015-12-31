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
int main() {
   int t, n, p, q, max1, max_count = 1;
   t = read_int();
   while(t--){
        n = read_int();
        max_count = 1;
        int a[n+7];
        for(int i = 0; i < n; i++){
            a[i] = read_int();
        }
        sort(a, a+n);
        p = a[0];
        q = 1;
        max1 = a[0];
        int i = 1;
        while(i < n){
            if(p == a[i]){
                q++;
            } else {
                q = 1;
                p = a[i];
            }
            if(q > max_count){
                max_count = q;
                max1 = a[i];
            }
            i++;
        }
        printf("%d %d\n", max1, max_count);
   }
}
