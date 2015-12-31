#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    int w[n+7];
    int b[m + 7];
    int c[m + n + 7] = {0};
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
        c[m + n - 1- i] = w[i];
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
}
