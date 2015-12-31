#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
#include<vector>
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//typedef pair<int,int> ii;
/*#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())*/
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
#define ll long long int
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
int main(){
    t = read_int();
    set<int> s;
    while(t--){
        int n, k, x;
        n = read_int();
        k = read_int();
        for(int i = 0; i < k; i++){
            x = read_int();
            s.insert(x);
        }
        int l = 1;
        int i;
        for(i = 0; i <= 31; i++){
            if(s.find(l) == s.end()){
                l *= 2;
            }else{
                break;
            }
        }
        int l = pow(2, i-1);
        int r = pow(2,i);

    }
}
