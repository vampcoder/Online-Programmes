#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int p = 0, q;
    int m, n, x, y;
    scanf ("%d%d", &m, &n);
    int b[m][10000];
    for (int i = 0; i < n; i++) {
            scanf ("%d%d", &x, &y);
            b[x][y] = 1;
    }
    int j;
    for (int i = 0; i < m; i++) {
        for (j = 0; j < m ; j++) {
            for (int k = 0; k < m; k++) {
                b[i][j] = (b[i][j] || (b[k][j] && b[i][k]));
            }
        }
    }

}
