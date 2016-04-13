#include<bits/stdc++.h>

using namespace std;

int arr[1000010];
long long sum[1000010];

void precalc(){

    for(int i = 0; i < 1000010; i++){
        int a = 5;
        int c = 0;
        while(i/a > 0){
            c += i/a;
            a *= 5;
        }
        arr[i] = c;
    }
}
int find_zeros(int x){
    int c = 0;
    while(x % 5 != 0){
        x /= 5;
        c++;
    }
    return c;
}

long long query(int n, int r, int p, int q){
    return sum[n]-sum[r]-sum[n-r] + q*find_zeros(p);
}


int main()
{
    precalc();
    int t, n, r, p, q;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> r >> p >> q;
        cout << "Case " << i << ": " << query(n, r, p, q) << endl;


    }

}
