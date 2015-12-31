#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int heap_size;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m;
        //cin >> n>> m;
        scanf("%d", &n);
        scanf("%d", &m);
        int a[n];
        int *y;
        y = a;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
            //cin >> a[j];
        }
        int b[m][2];
        for (int j = 0; j < m; j++) {
            //cin >> b[j][0] >> b[j][1];
            scanf("%d", &b[j][0]);
            scanf("%d", &b[j][1]);
        }
        cout << "input done" << endl;
        int *p = NULL;
        int c, d;
        for (int j = m-1; j > 0; j--) {
            p = find(a, a+n, b[j][1]);
            cout << "*p " << *p << endl;
            c = (int)(p-y);
            p = find(a, a+n, b[j][0]);
            d = (int)(p - y);
            cout << "c " << c << " d " << d << " *p " << *p << endl;
            qsort(p, (c-d), sizeof(int), cmpfunc);
        }
        int x = a[0];
        x++;
        for (int j = 1; j < n; j++) {
            if (x == a[i]) {
                x++;
                printf("Impossible\n");
                break;
            }
        }
        if (x == a[n-1]) {
            printf("Possible");
        }
    }
}
