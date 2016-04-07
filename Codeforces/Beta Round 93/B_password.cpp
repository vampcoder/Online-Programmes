#include <bits/stdc++.h>

using namespace std;

#define B1 2
#define M1 951161
#define B2 3
#define M2 965113

int start = -1, end1 = -1;
char text[1000010];
char text1[1000010], text2[1000010], text3[1000010];
int m[1000010] = {0};
int m1[1000010] = {0};
bool test1[1000010] = {0};
bool test2[1000010] = {0};


bool check(const int l){
    cout << "l " << l << endl;
    //cout << "l " << l << endl;
    const int l1 = strlen(text1);
    const int l2 = strlen(text2);
    const int l3 = strlen(text3);
    memset(m, 0, sizeof m);
    memset(m1, 0, sizeof m1);


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

    h = 0;
    p = 1;
    h1 = 0;
    p1 = 1;
    for(int i = l-1; i >= 0; i--){
        h += p*text2[i];
        p *= B1;
        h %= M1;
        p %= M1;

        h2 += p1*text2[i];
        p1 *= B2;
        h2 %= M2;
        p1 %= M2;

    }
    int H = h;
    int H2 = h2;
    bool flag = false;
    cout << m[h] << " " << m1[h2] << " " << h << " " << h2 << endl;
    if(m[h] != m1[h2]){
        return false;
    }else{
        flag = true;
    }
    h = 0;
    p = 1;
    h2 = 0;
    p1 = 1;
    cout << "l3 :" << l3   << " " << l <<  endl;
    int i = l3-1;
    for(; i >= l3-l; i--){
        h += p*text3[i];
        p *= B1;
        h %= M1;
        p %= M1;

        h2 += p1*text3[i];
        p1 *= B2;
        h2 %= M2;
        p1 %= M2;
    }
    if(h == H && h2 == H2){
        if(l != 0){
            start = l3-l;
            end1 = l3-1;
        }
        return true;
    }

    return flag;
}

void binarySearch(){
    int r = min(strlen(text1),min(strlen(text2),strlen(text3)));
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

    cin >> text;
    int l = strlen(text);


    strncpy(text1, text+1, l-2); //infix
    cout << text1 << endl;
    strncpy(text2, text, l-1); //prefix
    cout << text2 << endl;
    strncpy(text3, text+1, l-1); //suffix
    cout << text3 << endl;



    binarySearch();

    if(start == -1 || end1 == -1){
        cout << "No common Substring";
    }else{
        for(int i = start; i <= end1; i++){
            cout << text3[i];
        }
        cout << endl;
    }
    cout << "start " << start << "  end " << end1 << endl;

}
