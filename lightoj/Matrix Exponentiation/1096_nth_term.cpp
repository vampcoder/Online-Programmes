#include<bits/stdc++.h>

using namespace std;

int a, b, c ,n, mod=10007;

void prod(int (&arr1)[4][4], int (&arr2)[4][4]){
    int ans[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int temp = 0;
            for(int k = 0; k < 4; k++){
                temp = (temp + arr1[i][k]*arr2[k][j])%mod;
            }
            ans[i][j] = temp;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            arr2[i][j] = ans[i][j];
        }
    }
}



void sqr(int (&arr)[4][4]){
    int arr1[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            arr1[i][j] = arr[i][j];
        }
    }
    prod(arr1, arr);
}

void rec(int (&arr)[4][4], int n){
    if(n <= 1){
        return;
    }
    rec(arr, n/2);

    sqr(arr);

    if(n&1){
        int base[4][4] = {{a, 0, b, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}};
        prod(base, arr);
    }
}

void print(int arr[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int solve(){
    if(n <= 2)
        return 0;

    int base[4][4] = {{a, 0, b, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}};
    rec(base, n-2);
    //print (base);
    return ((c*base[0][3])%mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> n >> a >> b >> c;
        cout << "Case " << tc+1 << ": " << solve() << endl;
    }
}
