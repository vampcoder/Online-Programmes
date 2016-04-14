#include<bits/stdc++.h>

using namespace std;

int arr1[1000010];
int arr2[1000010];

void precalc(){

    for(int i = 0; i < 1000010; i++){
        int a = 5;
        int c1 = 0;
        int c2 = 0;
        while(a <= i){
            c1 += i/a;
            a *= 5;
        }
        arr1[i] = c1;
        a = 2;
        while(a <= i){
            c2 += i/a;
            a *= 2;
        }
        arr2[i] = c2;
    }
}
int find_zeros(int x, int no, int q){
    long long c = 0;
    int x1 = x;
    while(x % 5 == 0){
        x /= 5;
        c++;
    }
    long long no5 = c;
    no5 *= q;
    c = 0;
    x = x1;
    while(x % 2 == 0){
        x /= 2;
        c++;
    }
    c *= q;
    return min(no5, no+c);
}


long long query(int n, int r, int p, int q){
    int no5 = arr1[n]-arr1[r]-arr1[n-r];
    int no2 = arr2[n]-arr2[r]-arr2[n-r];
    int ans = no5;
    ans += find_zeros(p, no2-no5, q);
    return ans;
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
