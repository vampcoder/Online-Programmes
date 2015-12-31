#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, q;
        scanf("%d", &n);
        long int a[n];
        scanf("%d", &q);
        long long int g[n];
        g[0] = 0;
        for (int j = 0; j < n; j++){
                g[j] = 0;
            scanf("%d", &a[j]);
            if(j == 0){
                g[j] = a[j];
            } else{
                g[j] = g[j-1] + a[j];
            }
        }
        int l, r;
        long long int s = 0;
        for (int j = 0; j < q; j++){
            scanf("%d", &l);
            scanf("%d", &r);
            if(l == r){
                s = a[r-1];
            }else if(l == 1){
                s = g[r-1];
            }else{
                s = g[r-1] - g[l-2];
            }
            printf("%lld\n", s);
            s = 0;
        }
    }
}
