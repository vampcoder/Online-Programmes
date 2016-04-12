#include<bits/stdc++.h>

using namespace std;

bool primes[10000001];
int arr[1000000];

void seive()
{
    memset(primes, 0, sizeof primes);
    for(int i = 4; i < 10000001; i+= 2){
        primes[i] = 1;
    }
    int k = 1;
    arr[0] = 2;
    for(int i = 3; i < 10000001; i += 2){
        if(primes[i] == false){
            for(int j = i + i; j < 10000001; j += i){
                primes[j] = true;
            }
            arr[k] = i;
            k++;
        }
    }
}


int main()
{
    int t, q;
    seive();
    cin >> t;
    //for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    for(int i = 1; i <= t; i++){
        cin >> q;
        int ans = 0;
        for(int j = 0; arr[j] <= q/2; j++){
            if(primes[q-arr[j]]==0){
                ans++;
            }
        }
        cout << "Case " << i << ": " << ans << endl;
    }
}
