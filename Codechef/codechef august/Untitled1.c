#include <iostream>
#include <cstdio>
#define gc getchar_unlocked;
using namespace std;
int main()
{
    short int T;
    int n;
    int k;
    int a[50];
    int s = 0;
    for (int i = 0; i < T; i++) {
        scanf ("%d%d", &n, &k);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
            if (a[j] % 2) {
                s++;
            }else {
                s = 0;
            }
        }
        if (s == k) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
   return 0;
}
