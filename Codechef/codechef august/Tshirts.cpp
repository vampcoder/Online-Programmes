#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long fact[100];
bool f[100];
long facto(int x) {
    if (x == 1){
          //  cout << "1" << endl;
    return 1;
    }
    if (f[x]) {
        //cout << "2\n";
        return (long)fact[x];
    } else {
        f[x] = true;
    //cout << "3\n";
        fact[x] = x * facto(x-1);
        return fact[x];
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 2; i <100; i++){
        f[i] = false;
    }
    int n, k;
    char c;
    char a[10][100];
    int b[100];
    int i = 0, j = 0, d = 1, e = 0;
    while (i < t) {
        scanf("%d", &n);
        int x[n];
        j = 0;
        while (j < n) {
            k = 0;
            do{
                scanf("%d%c", &a[j][k], &c);
                k++;
            }while (c != '\n');
            x[j] = k;
            e += k;
            j++;
        }
        cout << e << endl;
        int h;
        int l = 0;
        for (h = 0; h < n; h++) {
            for (j = 0; j < strlen(a[h]); j++) {
                for (int s = j+1; s < n; s++) {
                    l = count(a[s], a[s] + 9, a[h][j]);
                    d *= l;
                }
            }
        }
        cout << d << endl;
        cout << "hi" << endl;
        long p = facto(e)/((facto(e - n))*((facto (n))));
        printf("%ld", p/d);
        i++;
        j = 0, d = 1, e = 0;
    }
}
