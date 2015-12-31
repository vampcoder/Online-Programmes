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
int visited[11] = {0};
bool calc(int len, int a[], int b[][11], vector<int>& res, int index){
    if(len < 1 && index == n){
        return true;
    }
    int flag = 0;
    bool q = false;
    for(int i = 0; i < 10; i++){
        if(visited[i] != 1 && q == false){
            res[index] = b[index][i];
            q = calc(n-1, a, b, res, index+1, visited);
        }

    }
    return q;
}
int main()
{
    int n = read_int();
    int a[9];
    int b[n][11];
    int j = 0;
    int x;
    for(int i = 0; i < 9; i++){
        x = read_int();
        if(x == 1){
            a[j++] = x;
        }
    }
    if(j != n){
        printf("it seems MSG");
        return 0;
    }
    vector<int> v(n);
    int visited[11] = {0};
    int x;
    for(int i = 0; i < n; i++){
        x = read_int();
        int j;
        for(j = 0; j < x; j++){
            b[i][j] = read_int();
        }
        b[i][j] = -1;
    }
    bool res = calc(n, a, b, v, visited);
    if(res == false){
        printf("it seems MSG");
    }else{
        for(int i = 0; i < v.size(); i++)
            printf("%d ", v[i]);
    }


}
