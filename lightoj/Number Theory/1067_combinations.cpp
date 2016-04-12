#include<bits/stdc++.h>

using namespace std;

#define M 1000003

long long fact[1000010];

void func(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 1000010; i++){
        fact[i] = i * fact[i-1];
        if(fact[i] >= M)
            fact[i] %= M;
    }
}

long long power(long long x, long long m){
    if(m == 0){
        return 1;
    }
    long long ans = power(x, m/2)%M;

    if(m % 2 == 0){
        return (ans*ans)%M;
    }else{
        return (ans*ans*x)%M;
    }
}


int main()
{
    int t, n, k;
    func();
    cin >> t;
    for(int i = 1; i<= t; i++){
        cin >> n >> k;
        cout << "Case " << i << ": " << (fact[n] * power(fact[n-k], M-2)*power(fact[k], M-2)%M)%M << endl;
    }
}
