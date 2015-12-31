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
int main()
{
    int t,q ,k,n;
    long long int sum1;
    t = read_int();
    double N, x, y, z;
    while(t--){
        sum1 = 0.0;
        n = read_int();
        int l = 0;
        for(int j = 0; j < n; j++){
            k = read_int();
            sum1 += k;
            if(k == 0){
                l++;
            }
            //z = k - 0.;
            //sum2 += z;
        }
        x = (double)sum1 - (n-l)*0.99999999999999;
        //y = (double)sum1 + N;
        //cout<< "x : " << x << endl;
        if(x <= (double)100.0 && sum1 >= 100){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
       /*cout<< sum1*1.0<< endl;
       x = ((double)((sum1*1.0 -100.0))/n);
        if( x < 1 && x >= 0) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }*/
    }

}
