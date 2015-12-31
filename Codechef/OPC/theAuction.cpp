#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
#include<vector>
#include<map>
#include<cmath>
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//typedef pair<int,int> ii;
/*#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())*/
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
long long int power(long long int l, long long int y){
    long long int x = 1;
    while(y--){
        x *= l;
        if(x > 1000000007){
            x %= 1000000007;
        }
    }
    return x;
}
int main(){
    int t = read_int();
    while(t--){
        int n = read_int();
        if(n < 4){
            printf("%d\n", n);
            continue;
        }
        int x = n%3;
        int div = n/3;
        if(x == 2){
            printf("%d\n", ((long long int)pow((double)3,(double)div)*2)%1000000007);
        }else if(x == 1){
            printf("%d\n", ((long long int)pow((double)3,(double)div-1)*4)%1000000007);
        }else {
            printf("%d\n", ((long long int)pow((double)3,(double)div))%1000000007);
        }
    }
}
