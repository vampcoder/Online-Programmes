#include<iostream>
#include<cstdio>
#include<map>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif

using namespace std;

int read_int()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore all characters till the first digit
int ret=0;
while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}

int main() {
    int t, n;
    cin >> n;
    while(t--){
        cin >> n;
        int count1 = 0;
        int a[1007] = {0};
        while(n--){
            int x;
            cin >> x;
            if(a[x]){
                count1++;
            }else{
                a[x]++;
            }
        }
        cout << count1 << endl;
    }
}
