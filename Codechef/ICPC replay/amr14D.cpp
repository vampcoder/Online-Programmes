#include<iostream>
#include<cstdio>
#include<vector>
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
    int t = read_int();
    int z[t], i = 0, u = t;
    while(t--){
        int n = read_int();
        vector<int> a(n+7,0);
        int x, l = 0;
        while(n--){
            x = read_int();
            if(a[x] == 0 && l == 0){
                a[x]++;
            }else{
                l = 1;
            }
        }
        z[i++] = l;
    }
    for(int j = 0; j < u; j++){
        if(z[j] == 1){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}
