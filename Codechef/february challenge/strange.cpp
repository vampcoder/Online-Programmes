#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
#define ll long long int
#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define all(c) c.begin(), c.end()

using namespace std;

int m;
int a[10000009];
int F[10000009];
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
long long int read_int1()
{
    register char c=gc();
    while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
    long long int ret=0;
    while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
    {
        ret=ret*10+(c-48);//construct the number
        c=gc();
    }
    return ret;
}
void fac(){
    a[0] = 0;
    a[1] = 1;
    for(long long int i = 2; i < m; i++)
        a[i] = (a[i-1] *i)%m;
}
void f(){
    F[0] = 0;
    for(int i = 1; i <= m; i++){
        F[i] = F[i-1]+ (i*a[i]);
    }
    for(int i = 1; i <= m; i++){
        F[i] += (i*i*(i+1))/2;
    }
}
int main()
{
    int n;
    n = read_int();
    m = read_int();

    long long int x;
    while(n--){
        x = read_int1();

    }
}
