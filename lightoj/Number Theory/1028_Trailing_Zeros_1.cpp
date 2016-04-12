#include<bits/stdc++.h>

using namespace std;

bool arr[1000010];

int prime[1000010];

void func(){
    int k = 0;
    for(int i = 2; i < 1000010; i++){
        if(arr[i] == 0){
            prime[k] = i;
            k++;
            for(int j = i + i; j < 1000010; j += i){
                arr[j] = 1;
            }
        }
    }
}

long long calc(long long q){
    long long ans = 1;
    int l = floor(sqrtl(q));
    for(int i = 0; prime[i] <= l; i++){
        int c = 0;
        while(q%prime[i] == 0){
            c++;
            q /= prime[i];
        }
        ans *= (c+1);
        l = floor(sqrtl(q));
    }
    if(q != 1){
        ans *= 2;
    }
    return ans-1;
}

int main()
{
    int t;
    long long q;
    func();
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%lld", &q);
        printf("Case %d: %lld\n", i, calc(q));
        //cout << "Case " << i << ": " << calc(q) << endl;

    }

}
