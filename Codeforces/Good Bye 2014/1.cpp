#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int t;
    int x;
    scanf("%d%d", &t, &x);
    int a[t+7];
    int b[t+7];
    int p;
    int j;

    for(int i = 0; i < t-1; i++){
        scanf("%d", &a[i]);
    }
    p = a[0];
    j = p;
    while(p != x && p < x){
        p += a[j] + j;
        j = p;
    }
    if(p == x) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }
}
