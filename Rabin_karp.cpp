#include <bits/stdc++.h>

using namespace std;

#define B 2
#define M 1000000007


int main()
{

    char text[100], pat[20];
    cin >> text >> pat;
    const int lt = strlen(text);
    const int lp = strlen(pat);
    int H[100];

    memset(H, 0, sizeof H);
    int p = 1;
    for(int i = lp-1; i >= 0; i--){
        H[0] += text[i]*p;
        p *= B;
    }

    for(int i = 1; i < lt-lp; i++){
        H[i] = H[i-1]*B - text[i-1]*p + text[i+lp-1];
        H[i] = H[i]%M;
    }
    int patH = 0;
    p = 1;
    for(int i = lp-1; i >= 0; i--){
        patH += pat[i]*p;
        p *= B;
    }

    for(int i = 0; i < lt-lp; i++){
        if(patH == H[i]){
            cout << "Match at :  " << i << endl;
        }
    }
}
