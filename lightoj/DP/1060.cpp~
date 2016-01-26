#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define pii pair<int,int>
#define vi vector<int>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define PI 3.14159265358979323846

#define POS(x) ((x)<0?(-1*(x)):(x))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

#define sz(c) (int)(c.size())
#define all(c) c.begin(), c.end()

using namespace std;

long long fact[25], dem, in, num, temp, tempdem;
int counter[30], n, k;
char ch[30];

int main()
{
    fact[0] = fact[1] = 1;
    for(int i=2 ; i<21 ; i++)
        fact[i] = fact[i-1]*i;

    scanf("%d", &n);
    for(int I = 1; I <= n; I++)
    {
        scanf("%s", ch);
        scanf("%I64d", &in);

        k = strlen(ch);

        for(int i=0 ; i<30 ; i++)
            counter[i] = 0;

        for(int i=0 ; ch[i] != '\0' ; i++)
            counter[ch[i]-'a']++;

        num = fact[k];
        for(int i=0 ; i<26 ; i++)
            num /= fact[counter[i]];

        if(in>num)
        {
            printf("Case %d: Impossible\n", I);
            continue;
        }

        for(int i=0 ; ch[i] != '\0' ; i++)
        {
            k--;
            num = fact[k];
            dem = 1;
            for(int j=0 ; j<26 ; j++)
                dem *= fact[counter[j]];

            int j=0;
            for(j=0 ; j<26 ; j++)
            {
                if(counter[j] == 0)
                    continue;

                tempdem = dem/fact[counter[j]];
                tempdem = tempdem*fact[counter[j]-1];

                temp = num/tempdem;
//printf("** %I64d %I64d\n", num, tempdem);
                if((in-temp)>0)
                {
                    in -= temp;
                    continue;
                }

                else
                {
                    break;
                }
            }

            ch[i] = 'a'+j;
            counter[j]--;


        }

        printf("Case %d: %s\n", I, ch);
    }

	return 0;
}
