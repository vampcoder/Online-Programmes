#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    int x, y, n1, n2;
    bool a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%ld%ld", &x, &y);
        if (x >= 0){
            if (x % 2 == 0) {
                a = false;
            }else {
                n1 = (x-1)/2;
                a = (y >= (-2*n1) && y <= (2*n1 + 2));
            }
        }else {
                if (x%2 ==0){
                    n1 = x/2;
                    a = (y >= 2*n1  && y <= -2*n1);
            } else {
                a = false;
            }
        }
        if (y % 2 == 0) {
        n2 = y/2;
        if (y <= 0) {
            b = (x >= 2*n2 && x <= 1- 2*n2);
        }else {
            b = (x <= 2*n2-1 && x >= -2*n2);
        }
        }else {
            b = false;
        }
        if (a || b) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
}
