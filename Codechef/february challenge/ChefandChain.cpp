#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
#define ll long long int
#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define all(c) c.begin(), c.end()

using namespace std;

int read_int()
{
    register char c=gc();
    while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
    int ret=0;
    while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
    {
        ret=ret*10+(c-48);//construct the number
        c=gc();
    }
    return ret;
}
char change(char ch){
    if(ch == '+')
        return '-';
    else
        return '+';
}
int main()
{
    int t = read_int();
    while(t--){
        char a[100000];
        scanf("%s", &a);
        int count, c1 = 0, c2 = 0;
        char ch = '-';
        for(int i = 0; i < strlen(a); i++){
            if(a[i] != ch)
                c1++;
            ch = change(ch);
        }
        ch = '+';
        for(int i = 0; i < strlen(a); i++){
            if(a[i] != ch)
                c2++;
            ch = change(ch);
        }
        printf("%d\n", min(c1,c2));
    }
}
