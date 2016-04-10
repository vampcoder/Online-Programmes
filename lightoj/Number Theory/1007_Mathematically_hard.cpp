#include<bits/stdc++.h>

using namespace std;

bool primes[5000010] = {0};
unsigned long long arr[5000010];

void seive(){
    for(int i = 0; i < 5000010; i++)
        arr[i] = i;
    int l = sqrt(5000010);
    for(int i = 2; i < 5000010; i++){
        if(primes[i] == 0){
            arr[i] = i-1;
            for(int j = i+i; j < 5000010; j += i){
                primes[j] = 1;
                arr[j] = arr[j]/i;
                arr[j] *= (i-1);
            }
        }
    }
    arr[1] = 0;
    for(int i = 2; i < 5000001; i++){
        arr[i] = arr[i]*arr[i];
    }
    for(int i = 2; i < 5000001; i++){
        arr[i] += arr[i-1];
    }
}

int main()
{
    seive();
   // eulerToitentSum();
  // cout << "2" << endl;
    int t;
    int a, b;
    cin >> t;
    for(int i = 1; i <= t; i++){
        scanf("%d%d", &a, &b);
        printf("Case %d: %llu\n", i, arr[b]-arr[a-1]);
    }
}
