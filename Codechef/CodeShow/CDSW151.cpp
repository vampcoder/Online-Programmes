#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
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

long long int arr[100010], ans[100010];

int main()
{
    long long int t,n,z,i,k,m,pos;

    t = read_int();
    while (t--) {
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));
        n = read_int();
        z = read_int();

        for (i = 0; i < n; i++) {
            arr[i] = read_int();
        }
        ans[0] = 0;
        for (i = 0; i < z; i++) {
            ans[0] = ans[0] ^ arr[i];
        }
        k = 1;
        m = ans[0];
        pos = 0;
        for (i = z; i < n; i++) {
            ans[k] = ans[k-1] ^ arr[i-z] ^ arr[i];

            if (ans[k] <= m) {
                pos = k;
                m = ans[k];
            }
            k++;
        }
        printf("%lld\n", pos+1);
    }
    return 0;
}
