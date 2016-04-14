#include<bits/stdc++.h>

using namespace std;

long long M = 1000000007;


bool arr[1000010];
int primes[1000010];

void seive(){
    primes[0] =2;
    int k = 1;
    for(int i = 4; i < 500010; i+= 2){
        arr[i] = 1;
    }
    for(int i = 3; i < 1010; i+=2){
        if(arr[i] == 0){
            for(int j = i*i; j < 500000; j += (i+i)){
                arr[j] = 1;
            }
        }
    }
    for(int j = 3; j < 500000; j++){
        if(arr[j] == 0)
            primes[k++] = j;
    }
}

long long calc_pow(long long a, long long b){
    if(b == 0)
        return 1;
    long long ans = calc_pow(a, b/2);
    ans = (ans * ans + M)%M;
    if(b&1){
        return (ans * a + M)%M;
    }else{
        return (ans + M)%M;
    }
}

long long funct(long long a, long long r, long long n){
    return (((a*(calc_pow(r, n+1)-1 + M))%M)*(calc_pow(r-1, M-2)))%M;
}

long long int query(long long n, long long m){
    long long r = sqrtl(n);
    long long ans = 1;
    for(int i = 0; primes[i] <= r; i++){
        long long c = 0;
        while(n%primes[i] == 0){
            c++;
            n /= primes[i];
        }
        r = sqrtl(n);
        if(c != 0){
            ans = (ans * funct(1, primes[i], c*m))%M;
        }
    }

    if(n != 1){
        ans  = (ans * funct(1, n, m))%M;
    }
    return ans;
}

int main()
{
    seive();
    long long t, n ,m;
    scanf("%lld", &t);
    for(int i = 1; i <= t; i++){
        scanf("%lld%lld", &n, &m);
        printf("Case %d: %lld\n", i, query(n, m));
    }
}
