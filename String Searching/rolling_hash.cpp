#include <bits/stdc++.h>

using namespace std;

#define B1 2
#define M1 1000000007
#define B2 3
#define M2  2038074743


int main()
{

    char text[100], pat[20];
    cin >> text >> pat;
    const int lt = strlen(text);
    const int lp = strlen(pat);
    int H1[100];
    int H2[100];

    memset(H1, 0, sizeof H1);
    memset(H2, 0, sizeof H2);

    int p = 1;
    for(int i = lp-1; i >= 0; i--){
        H1[0] += text[i]*p;
        p *= B1;
        H1[0] %= M1;
        p %= M1;
    }

    for(int i = 1; i <= lt-lp; i++){
        H1[i] = (H1[i-1]*B1)%M1 - (text[i-1]*p)%M1 + text[i+lp-1];
        H1[i] = H1[i]%M1;
    }
    int patH1 = 0;
    p = 1;
    for(int i = lp-1; i >= 0; i--){
        patH1 += pat[i]*p;
        p *= B1;
        patH1 %= M1;
        p %= M1;
    }

    p = 1;
    for(int i = lp-1; i >= 0; i--){
        H2[0] += text[i]*p;
        p *= B2;
    }

    for(int i = 1; i <= lt-lp; i++){
        H2[i] = (H2[i-1]*B2)%M2 - (text[i-1]*p)%M2 + text[i+lp-1];
        H2[i] = H2[i]%M2;
    }
    int patH2 = 0;
    p = 1;
    for(int i = lp-1; i >= 0; i--){
        patH2 += pat[i]*p;
        p *= B2;
    }


    for(int i = 0; i <= lt-lp; i++){
        if(patH1 == H1[i] && patH2 == H2[i]){
            cout << "Match at :  " << i << endl;
        }
    }
}
