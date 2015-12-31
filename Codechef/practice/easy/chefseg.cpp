#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
#include<vector>
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

long long int read_int()
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
bool check (long long int k) {
    long long int t = k%2;
        while(t == 0 && k != 1){
            t = k%2;
            k /= 2;
        }
        if(t == 1)
            return false;
        else
            return true;
}
int main(){
    long long int t;
    t= read_int();
    long long int x, k;
    double power, ans, n;
    while(t--){
        x = read_int();
        k = read_int();
        n = (int)log2(k) + 1;
        power = (double)pow(2, n);
        if(check(k)){
            ans = (double)x/(double)power;
        }else{
            ans = (double)(k-(int)log2(k))*x/(double)power;
        }
        printf("%lf\n", ans);
    }
}
