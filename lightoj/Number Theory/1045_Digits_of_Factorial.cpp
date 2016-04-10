#include<bits/stdc++.h>

using namespace std;

long double arr[1000010];

int main()
{
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i < 1000001; i++){
        arr[i] = arr[i-1] + log2(i);
    }
    int t;
    cin >> t;
    int n, b;
    for(int i = 1; i <= t; i++){
        scanf("%d%d", &n, &b);
        printf("Case %d: %0.0Lf\n", i, floor(arr[n]/log2(b) + 1));
    }
}
