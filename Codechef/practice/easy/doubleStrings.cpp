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
    c=gc();  //ignore aint characters tiint the first digit
int ret=0;
while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}
int main()
{
    int t, n;
    t = read_int();
    for(int i = 0; i < t; i++){
        n = read_int();
        if(n%2) {
            printf("%d\n", n-1);
        }else{
            printf("%d\n", n);
        }
    }

}
