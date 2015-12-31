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


void dfs(int w, int h, vector<char> a[], int m, int n, int& max, bool b[20][20]){
    if(m >= h || m < 0 || n >= w || n < 0 || b[m][n])
            return;
    if(a[m][n] == '#'){
        b[m][n] = true;
        return;
    }
    if(a[m][n] == '.')
        max++;
    //cout << m << " " << n << endl;
    b[m][n] = true;

    dfs(w, h, a, m+1, n, max, b);
    dfs(w, h, a, m, n+1, max, b);
    dfs(w, h, a, m-1, n, max, b);
    dfs(w, h, a, m, n-1, max, b);
}
int main()
{
	int t;
	t = read_int();
	int w, h;
	for(int k = 1; k <= t; k++){
        w = read_int();
        h = read_int();
        vector<char> a[h];
        bool b[20][20];
        char x,y;
        int m, n;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                x = gc();
                b[i][j] = false;
                if(x == '@'){
                    m = i;
                    n = j;
                }
                a[i].push_back(x);
            }
            x = gc();
        }
        int max = 1;
        dfs(w, h, a, m, n, max, b);
        printf("Case %d: %d\n", k, max);
	}
}
