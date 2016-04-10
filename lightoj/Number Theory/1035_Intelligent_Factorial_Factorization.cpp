#include<bits/stdc++.h>

using namespace std;

vector<int> primes;

int arr[110][29];

void seive(){
    bool arr[110] = {0};
    for(int i = 2; i < 110; i++){
        if(arr[i] == 0){
            primes.push_back(i);
            for(int j = i+i; j < 110; j += i){
                arr[j] = 1;
            }
        }
    }
}

void func(){

    memset(arr, 0, sizeof arr);
    for(int i = 2; i < 110; i++){
        int l = primes.size();
        int num = i;
        for(int j = 0; j < l; j++){
            int c = 0;
            while(num != 1 && num%primes[j] == 0){
                c++;
                num /= primes[j];
            }
            arr[i][j] = arr[i-1][j] + c;
        }
    }
}


int main()
{

    seive();
    func();
    int t, n;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        cout << "Case " << i << ": " << n << " = ";
        int l = 0;
        for(int j = 0; j < primes.size(); j++){
            if(primes[j] <= n)
                l = j;
        }
        for(int j = 0; j < primes.size(); j++){
            if(arr[n][j] != 0){
                cout << primes[j] << " (" << arr[n][j] << ")";
                if(l != j){
                    cout << " * ";
                }else{
                    cout << endl;
                }
            }

        }


    }
}
