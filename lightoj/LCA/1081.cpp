#include<bits/stdc++.h>

using namespace std;

int a[510][510];
int BIT[510][510];

void create(int i, int j){
    int m = -1;
    int x = i, y = j;
    while(i <= n){
        while(j <= n){
            m = max(m, a[i-1][j-1]);
            j += (j&-j);
        }
        i += (i&-i);
    }
    BIT[x][y] = m;
}

int query(int i, int j, int i1, int j1){
    int m = -1;
    int x = i

}
int main()
{
    int t, n, q;
    cin >> t;
    char s[10];
    scanf("%d", &s);
    for(int i = 1; i <= t; i++){
        cin >> n >> q;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> a[j][k];
            }
        }
    }
}
