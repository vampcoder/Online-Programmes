
#include<cstring>
#include<iostream>
#include<cstdio>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

int read_int()
{
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
    int n, k, m, l = 0;
    n = read_int();
    k = read_int();
    for(int i = 0; i < n; i++){
        m = read_int();
        if(!(m%k)){
            l++;
        }
    }
    printf("%d\n", l);
}
