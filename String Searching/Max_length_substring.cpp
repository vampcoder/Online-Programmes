#include <bits/stdc++.h>

using namespace std;

#define B1 2
#define M1 1000000007
#define B2 3
#define M2 2038074743

set<pair<long long , long long> > s;

int len = 0;
char text1[1000010];


bool check(const int l){
    cout << "l " << l << endl;
    const int l1 = strlen(text1);
    const int l2 = strlen(text2);


    long long h = 0;
    long long p = 1;
    long long p1 = 1;
    long long h2 = 0;

    for(int i = l-1; i >= 0; i--){
        h += p*text1[i];
        p *= B1;
        h %= M1;
        p %= M1;

        h2 += p1*text1[i];
        p1 *= B2;
        h2 %= M2;
        p1 %= M2;

    }
    s.insert(make_pair(h, h2));

    long long h1;
    long long h3;
    for(int i = 1; i <= l1-l; i++){
        h1 = ((h*B1)%M1 - (text1[i-1]*p)%M1 + M1)%M1 + text1[i+l-1];
        h = h1%M1;

        h3 = ((h2*B2)%M2 - (text1[i-1]*p1)%M2 + M2)%M2 + text1[i+l-1];
        h2 = h3%M2;

        if(s.find(make_pair(h, h2)) != s.end()){
            return true;
        }else{
            s.insert(make_pair(h, h2));
        }
    }

    return false;
}

void binarySearch(){
    int r = strlen(text1);
    int l = 0;

    while (l <= r){
        int m = l + (r-l)/2;
        if (check(m))
            l = m + 1;
        else
            r = m - 1;
    }
}

int main()
{

    cin >> text1;
    //strcpy(text2, text1);
    binarySearch();
    cout << len<< endl;
}
