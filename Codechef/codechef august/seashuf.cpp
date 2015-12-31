#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
void funt(int a[], int x, int y) {
    int t = a[x];
    int i;
    for (i = x; i < y; i++) {
        a[i] = a[i+1];
    }
    a[i] = t;
}
int max1 (int n, int a[]) {
    int x = 0;
    int l;
    for (int i = n/2; i < n ;i++) {
        if(x < a[i]) {
            x = a[i];
            l = i;
        }
    }
   // cout << "max : "<< a[l] << endl;
    return l;
}
int min1 (int n, int a[]) {
    int x = INT_MAX;
    int l;
    for (int i = 0; i < n/2 ;i++) {
        if(x > a[i]) {
            x = a[i];
            l = i;
        }
    }
    return l;
}
void print(int a[], int n) {
for (int i = 0; i < n; i++)
    cout << a[i] << " ";
cout << endl;
}
int main() {
    int n, b, c;
    scanf("%d", &n);
    int a[n];
    int d[100][2];
    int f = 0;
    int l = 0, t ,u;
    int r = 0;
    int x = INT_MAX;
    int s = 0;
    int y = 0;
    int p = n/2;
    for (int i = 0; i < p; i++){
        scanf ("%d", &a[i]);
        l = l + a[i];
        if (x > a[i]) {
            x = a[i];
            t = i;
        }
    }
    for (int i = p; i < n; i++) {
        scanf("%d", &a[i]);
        r += a[i];
        if (y < a[i]) {
            y = a[i];
            u = i;
        }
    }
    cout << l  << "  " << r << endl;
    int o = 0;
    b = l - a[t] + a[n/2];
    s = r - l;
    c =  r - a[n/2] + a[t];
    bool w;
    w = (c - b < s  && s >= 0 && s < 2*n -1);
    while(w && o < 4){
        cout << "b : " << b << " c  : " << c << endl;
        l = b;
        r = c;
        cout << t + 1 << " " << u + 1 << endl;
        funt(a, t, u);
        d[f][0] = t;
        d[f++][1] = u;
        t = min1(n, a);
        u = max1(n, a);
        print(a,n);
        o++;
        b = l - a[t] + a[n/2];
        s = r - l;
        c =  r - a[n/2] + a[t];
        w = (c - b < s  && s >= 0 && s < 2*n -1);

    }
    printf("%d\n", f-1);
    for (int i = 0; i < f-1; i++) {
        printf("%d %d\n", d[i][0] + 1, d[i][1] + 1);
    }
}
