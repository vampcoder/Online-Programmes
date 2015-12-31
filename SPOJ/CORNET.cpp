#include<iostream>
#include<cstdio>
#include<map>
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

int m;
struct node{
    int val;
    int parent;
};
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
struct node cor[200001];
int coun(int x){
    int result, i;
    if(cor[i].val != 0){
        result = cor[i].val;
        i = cor[i].parent;

    }
    while(cor[i].parent != i){
        result += cor[i].parent - i;
    }
    cor[x].parent = i;
    cor[x].val = result;
    return result;
}
void merg(int x, int y){
    cor[x].parent = cor[y].parent;



}
int main()
{
    int t=read_int();
    int n;
    while(t--){
        cin >> n;
        for(int i = 0; i <= n; i++){
            cor[i].parent = i;
            cor[i].val = 0;
        }
        int l, m;
        char = ch1, ch2;
        while(1){
            scanf("%c%c", &ch1, ch2);
            if(ch2 == 'E'){
                scanf("%d", &l);

            }else if(ch2 == 'C'){
                scanf("%d%d", &l, &m);

            }else if(ch2 == 'o')
                break;
        }
    }
}
