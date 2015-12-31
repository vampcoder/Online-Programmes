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
    int t;
    t = read_int();
    while(t--){
        int n;
        n = read_int();
        int a[n+7];
        int b[n+7];
        for(int i = 0; i < n; i++){
            a[i] = read_int();
        }
        sort(a, a+n);
        for(int i = 0; i < n ; i++){
            b[i] = read_int();
        }
        sort(b, b+n);
        int j = 0, k = 0;
        while(j <= k && k < n){
            if(a[j] <= b[k]){
                j++;
                k++;
                //cout << "j : " << j << "k : "<< k << endl;
            }else {
                k++;
                //cout<< " k : " << k << endl;
            }
        }
        printf("%d\n", j);
    }
}
