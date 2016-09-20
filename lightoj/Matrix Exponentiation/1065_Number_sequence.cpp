#include<bits/stdc++.h>

using namespace std;

int a, b, n ,m, mod;

void prod(int (&arr1)[2][2], int (&arr2)[2][2]){
    int ans[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int temp = 0;
            for(int k = 0; k < 2; k++){
                temp += arr1[i][k]*arr2[k][j];
            }
            temp %= mod;
            ans[i][j] = temp;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arr2[i][j] = ans[i][j];
        }
    }
}



void sqr(int (&arr)[2][2]){
    int arr1[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arr1[i][j] = arr[i][j];
        }
    }
    prod(arr1, arr);
}

void rec(int (&arr)[2][2], int n){
    if(n <= 1){
        return;
    }
    rec(arr, n/2);

    sqr(arr);

    if(n&1){
        int base[2][2] = {{1, 1}, {1, 0}};
        prod(base, arr);
    }
}

int solve(){
    if(n == 0)
        return a;
    if(n == 1)
        return b;
    mod = pow(10, m);
    //print();
    int base[2][2] = {{1, 1}, {1, 0}};
    rec(base, n-1);
    return ((base[0][0]*b + base[0][1]*a)%mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> a >> b >> n >> m;
        cout << "Case " << tc+1 << ": " << solve() << endl;
    }
}
