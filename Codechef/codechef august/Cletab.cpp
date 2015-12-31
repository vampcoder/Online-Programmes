#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, m, n;
    int a[401];
    int c[401];
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d%d", &n, &m);
        for (int j = 0; j <=400; j++) {
            a[j] = 0;
            c[j] = 0;
        }
        int b[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[j]);
            c[b[j]] += 1;
        }
        int k = 0, l = 0, p;
        for (int j = 0; j < m; j++){
            if(l == n) {
                //cout << "b[j] : " << b[j] << endl;
                if (a[b[j]] > 0) {
                  //  cout << "a[b[j]]: "<< a[b[j]]<< endl;
                  ;
                }else{
                    p = j;
                    int r = 0, s;
                    s = c[b[j]];
                    int ab[n];

                    while (p >= 0 && c[b[p]] != 0) {
                        if (s > c[b[p]]) {
                            s = c[b[p]];
                            r = p;
                        }
                        p--;
                    }
                    if (p == -1) {
                        a[b[r]] = 0;
                        c[b[j]] += 1;
                    }else {
                        c[b[j]] -= 1;
                        c[b[p]] = -1;

                    }
                    a[b[j]] += 1;
                    k++;
                }
            }else{
                c[b[j]] -= 1;
                if (a[b[j]] > 0) {
                   ;
                }else {
                    l++;
                    k++;
                }
                a[b[j]] += 1;
                //cout<<"k2 :" << k<<endl;
            }
        }
        printf("%d\n", k);
    }
}
