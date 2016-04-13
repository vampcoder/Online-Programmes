#include<bits/stdc++.h>

using namespace std;

bool arr[1000010];
int primes[1000010];
int primes1[1000010];

void seive(){
    primes[0] =2;
    int k = 1;
    for(int i = 4; i < 1000010; i+= 2){
        arr[i] = 1;
    }
    for(int i = 3; i < 1010; i+=2){
        if(arr[i] == 0){
            for(int j = i*i; j < 1000010; j += (i+i)){
                arr[j] = 1;
            }
        }
    }
    for(int j = 3; j < 1000010; j++){
        if(arr[j] == 0)
            primes[k++] = j;
    }
}
void seive1(){
    primes[0] =2;
    int k = 1;
    for(int i = 3; i < 1000010; i+=2){
        if(arr[i] == 0){
            for(int j = i+i; j < 1000010; j += (i)){
                arr[j] = 1;
            }
            primes[k++] = i;
        }
    }
}

void func1(){
    for(int i = 0; i < 500000; i++){
        if(primes1[i] == primes[i]){
            continue;
        }else{
            cout << i << " " << primes[i] << " " << primes1[i] << endl;
            break;
        }
    }
}

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
long long power(long long a, long long b){
    if(b == 0){
        return 1;
    }
    long long ans = power(a, b/2);
    if(b&1){
        return ans*ans*a;
    }else{
        return ans*ans;
    }
}
long long func(long long a, long long b, long long l){
    long long hcf = gcd(a, b);
    //cout << hcf << endl;
    long long lcm = a*b/hcf;
    //cout << "lcm " << lcm << " hcf " << hcf << endl;
    int q = sqrtl(l);
    int p = sqrtl(lcm);
    int m = max(p, q);
    long long ans = 1;
    for(int i = 0; primes[i] <= m; i++){

        int div = primes[i];
        int c1 = 0;
        int c2 = 0;
        while(l%div == 0){
            l /= div;
            c1++;
        }
        while(lcm%div == 0){
            lcm /= div;
            c2++;
        }
        if(c1 > c2){
            ans *= power(div, c1);
        }
        q = sqrtl(l);
        p = sqrtl(lcm);
        m = max(p, q);

    }
    if(lcm%l != 0){
        ans *= l;
    }

    return ans;
}


int main()
{
    seive();
    //seive1();
    //func1();
    int t;
    long long a, b, L;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> L;
        if (L%a == 0 && L%b == 0){
            cout << "Case " << i << ": " << func(a, b, L) << endl;
        }else{
            cout << "Case " << i << ": impossible\n";
        }
    }
}
