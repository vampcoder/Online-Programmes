#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    int n;
    int k, p;
    int s = 0, l = 0,imp;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf ("%d%d", &n, &k);
        imp=0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &p);
            if (!(p % 2)){
                    s++;
            }
            else imp++;
        }
        if ((k && s >= k)) {
            printf("YES\n");
        }else if (!k && imp>=1) {
            printf("YES\n");
        }
        else {
            printf ("NO\n");
        }
        l = 0;
        s = 0;
    }
   return 0;
}
