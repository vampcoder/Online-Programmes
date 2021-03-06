// The technique of reducing time complexity discussed in non modified file is implemented here. Here I have used prime number less than 10^6.
// This code has time complexity of n*log(n).


#include <bits/stdc++.h>

using namespace std;

#define B1 2
#define M1 951161
#define B2 3
#define M2 965113

int start = -1, end1 = -1;
char text1[1000010], text2[1000010];


bool check(const int l){
    //cout << "l " << l << endl;
    const int l1 = strlen(text1);
    const int l2 = strlen(text2);

    int m[1000010] = {0};
    int m1[1000010] = {0};

    int h = 0;
    int p = 1;
    int p1 = 1;
    int h2 = 0;

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
    m[h]++;
    m1[h2]++;
    int h1;
    int h3;
    for(int i = 1; i <= l1-l; i++){
        h1 = (h*B1)%M1 - (text1[i-1]*p)%M1 + text1[i+l-1];
        h = h1%M1;
        m[h] += (i+1);

        h3 = (h2*B2)%M2 - (text1[i-1]*p1)%M2 + text1[i+l-1];
        h2 = h3%M2;
        m1[h2] += (i+1);
    }

    p = 1;
    p1 = 1;
    h = 0;
    h2 = 0;

    for(int i = l-1; i >= 0; i--){
        h += (p*text2[i])%M1;
        p *= B1;
        h %= M1;
        p %= M1;

        h2 += (p1*text2[i])%M2;
        p1 *= B2;
        h2 %= M2;
        p1 %= M2;

    }
    if(m[h] != 0 && m[h] == m1[h2]){
        start = 0;
        end1 = l-1;
        return true;
    }

    for(int i = 1; i <= l2-l; i++){
        h1 = (h*B1)%M1 - (text2[i-1]*p)%M1 + text2[i+l-1];
        h = h1%M1;

        h3 = (h2*B2)%M2 - (text2[i-1]*p1)%M2 + text2[i+l-1];
        h2 = h3%M2;
        if(m[h] != 0 && m[h]== m1[h2]){
            start = i;
            end1 = i+l-1;
            return true;
        }
    }
    return false;
}

void binarySearch(){
    int r = min(strlen(text1), strlen(text2));
    int l = 0;
    if(check(r)){
        return;
    }

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

    cin >> text1 >> text2;
    binarySearch();

    if(start == -1 || end1 == -1){
        cout << "No common Substring";
    }else{
        for(int i = start; i <= end1; i++){
            cout << text2[i];
        }
        cout << endl;
    }
    cout << "start " << start << "  end " << end1 << endl;
}
