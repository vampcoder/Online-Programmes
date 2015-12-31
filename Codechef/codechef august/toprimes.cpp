#include <iostream>
#include <cstdio>

using namespace std;

int hcf(int a, int b){
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int a[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &a[j]);
        }
        int j;
        int r = hcf(a[0], a[1]);
        if(r != 1){
        for (j = 2; j < n; j++){
            r = hcf(r, a[j]);
            if(r == 1){
                break;
                }
            }
        }
        int l = 0;
        if(r == 1){
            printf("%d\n", n);
        }else {
            printf("%d\n", l);
        }
    }
}
