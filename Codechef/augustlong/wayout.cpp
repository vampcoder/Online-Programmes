#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int n;

long long arr[1000005];

int main(){
    long long t;
    scanf("%lld", &t);
    while(t--){
        long long h;
        scanf("%lld%lld", &n , &h);
        for(i = 0; i <= n; i++){
            arr[i] = 0;
        }
        long long l, r;
        for(long long i = 0; i < n; i++){
            scanf("%lld%lld", &l, &r);
            arr[l] += 1;
            arr[r+1] -= 1;
        }

        for(int i = 1; i <= n; i++){
            arr[i] += arr[i-1];
        }
        long long mini = 0;

        for(long long i = 0; i < h; i++)
            mini += (n-arr[i]);

        for(long long i = h; i <= n; i++){
            mini = min(mini, mini-arr[i]+arr[i-h]);
        }
        cout << mini << endl;
    }
}
