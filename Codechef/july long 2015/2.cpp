#include<iostream>
#include<cmath>

using namespace std;
int func(long long x){
    int c = 0;
    while(x%10 == 0)
        x = x/10;
    int p = x%5;
    while(p == 0){
        c++;
        x = x/5;
        p = x%5;
    }
    return c;
}
long long gener[1000000];
int main()
{

    long long final[50];
    gener[0]  = 4;
    final[0] = 4;
    long long curr = 1, prev = 0, j = 1;
    long long i = 1;
    long long num = 1;
    long long x = 8;
    while(i < 500000){
        num *= 10;
        for(long long l = prev; l < curr; l++){
            gener[i++] = (4*num)+gener[l];
            if(gener[i-1]%x == 0){
                final[j++] = gener[i-1];
                x *= 2;
            }
        }
        for(long long l = prev; l < curr; l++){
            gener[i++] = (7*num)+gener[l];
            if(gener[i-1]%x == 0){
                final[j++] = gener[i-1];
                x *= 2;
            }
        }
        prev = curr;
        curr = i;
    }
   // for(i = 0; i < 10; i++)
       // cout << final[i] << " ";
    long long n;
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> x;
        int c = func(x);
        cout << c << " ";
        //cout << c << " ";
        if(c == 0)
            cout << x << endl;
        else if(c < 3)
            cout << x*4 << endl;
        else
            cout << x*(final[c-2]) << endl;
    }
}
