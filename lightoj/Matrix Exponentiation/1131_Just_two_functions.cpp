#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a1, b1, c1, a2, b2, c2, n, M;
ll f0, f1, f2, g0, g1, g2, q;
ll mul[6];

void prod(ll (&arr1)[6][6], ll (&arr2)[6][6]){
    ll ans[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            ll temp = 0;
            for(int k = 0; k < 6; k++){
                temp = (temp + arr1[i][k]*arr2[k][j])%M;
            }
            ans[i][j] = temp;
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            arr2[i][j] = ans[i][j];
        }
    }
}



void sqr(ll (&arr)[6][6]){
    ll arr1[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            arr1[i][j] = arr[i][j];
        }
    }
    prod(arr1, arr);
}

void rec(ll (&arr)[6][6], ll n){
    if(n <= 1){
        return;
    }
    rec(arr, n/2);

    sqr(arr);

    if(n&1){
        ll base[6][6] = {{a1, b1, 0, 0, 0, c1},
                        {1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0},
                        {0, 0, c2, a2, b2, 0},
                        {0, 0, 0, 1, 0 ,0},
                        {0, 0, 0, 0, 1, 0}};
        prod(base, arr);
    }
}

void print(ll arr[6][6]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void solve(){
    if(n == 0)
        cout << f0%M << " " << g0%M << endl;
    if(n == 1)
        cout << f1%M << " " << g1%M << endl;
    if(n == 2)
        cout << f2%M << " " << g2%M << endl;
    if(n <= 2)
        return;

    ll base[6][6] = {{a1, b1, 0, 0, 0, c1},
                        {1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0},
                        {0, 0, c2, a2, b2, 0},
                        {0, 0, 0, 1, 0 ,0},
                        {0, 0, 0, 0, 1, 0}};
    rec(base, n-2);
    ll g = 0, f = 0;
    for(int i = 0; i < 6; i++){
        f += base[0][i]*mul[i];
        g += base[3][i]*mul[i];
        f%=M;
        g%=M;
    }
    cout << f << " " << g << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;

    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> a1 >> b1 >> c1;
        cin >> a2 >> b2 >> c2;
        cin >> f0 >> f1 >> f2;
        cin >> g0 >> g1 >> g2;
        cin >> M;
        cin >> q;
        mul[0] = f2, mul[1] = f1, mul[2] = f0;
        mul[3] = g2, mul[4] = g1, mul[5] = g0;
        cout << "Case " << tc+1 << ":" << endl;
        while(q--){
            cin >> n;
            solve();
        }
    }
}
