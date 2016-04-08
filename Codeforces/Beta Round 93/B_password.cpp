#include <bits/stdc++.h>

using namespace std;

#define B1 2
#define M1 951161
#define B2 3
#define M2 965113

int start = -1, end1 = -1;
char text[1000010];
char text1[1000010], text2[1000010], text3[1000010];



bool check(const int l){
    //cout << "l " << l << endl;
    //cout << "l " << l << endl;
    const int l1 = strlen(text1);
    const int l2 = strlen(text2);
    const int l3 = strlen(text3);


    int h = 0;
    int p = 1;
    int p1 = 1;
    int h2 = 0;

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

    int H = h, H1 = h2;
    h = 0, h2 = 0, p = 1, p1 = 1;
    //if(l == 9)
       // cout << H << " " << H1 << endl;
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
    if(h == H && h2 == H1 && h != 0 && h2 != 0){
        start = 0;
        end1 = l-1;
        return true;
    }

    int h1;
    int h3;

    for(int i = 1; i <= l1-l; i++){
        h1 = ((h*B1) - (text1[i-1]*p) + M1)%M1 + text1[i+l-1];
        h = (h1 + M1)%M1;

        h3 = ((h2*B2) - (text1[i-1]*p1) + M2)%M2 + text1[i+l-1];
        h2 = (h3+M2)%M2;
        //if(i == 2)
         //   cout << "h " << h << " " << h2 << endl;
        if(h == H && h2 == H1 && h != 0 && h2 != 0){
            start = i;
            end1 = i+l-1;
            return true;
        }
    }
    return false;


}

void binarySearch(){

    int l1 = strlen(text1);
    int l2 = strlen(text2);
    int l3 = strlen(text3);

    int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    int p1 = 1, p2 = 1, p3 = 1, p4 = 1;

    vector<int> v;

    for (int i = 0; i < l2; i++){
        h1 += p1*text2[i];
        h3 =  B1*h3 + text3[l2-i-1];
        p1 *= B1;
        h1 %= M1;
        h3 %= M1;
        p1 %= M1;

        h2 += p2*text2[i];
        h4 = B2 * h4 + text3[l2-i-1];
        p2 *= B2;
        h2 %= M2;
        h4 %= M2;
        p2 %= M2;

        if(h1 == h3 && h2 == h4){
            v.push_back(i+1);
         //   cout << i << " ";
        }

    }
    if(v.size() == 0)
        return;
    //cout << endl;

    sort(v.begin(), v.end());
    int r = v.size()-1;
    int l = 0;
    if(check(v[r])){
        return;
    }

    while (l <= r){
        int m = l + (r-l)/2;
        if (check(v[m]))
            l = m + 1;
        else
            r = m - 1;
    }
}

int main()
{

    scanf("%s", text);
    int l = strlen(text);
    if(l < 3){
        printf("Just a legend\n");
        return 0;
    }

    strncpy(text1, text+1, l-2); //infix
    //cout << text1 << endl;
    strncpy(text2, text, l-1); //prefix
    //cout << text2 << endl;
    strncpy(text3, text+1, l-1); //suffix
    //cout << text3 << endl;

    binarySearch();

    if(start == -1 || end1 == -1){
        cout << "Just a legend" << endl;
    }else{
        for(int i = start; i <= end1; i++){
            cout << text3[i];
        }
        cout << endl;
    }
    //cout << "start " << start << "  end " << end1 << endl;

}
