#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
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

struct arr{
    int x;
    int div;
};

bool cmpc(struct arr x, struct arr y){
    if(x.div < y.div)
        return true;
    else if(x.div == y.div){
        if(x.x > y.x)
            return true;
        else
            false;
    }else
        return false;
}

int main(){
    int t, val;
    struct arr a[1007];
    for(int i = 0; i < 1007; i++){
        a[i].x = i;
        a[i].div = 1;
    }
    for(int i = 2; i < 1007; i++){
        for(int j = i; j < 1007; j =j+i){
            a[j].div++;
        }
    }

    sort(a+1, a+1001, cmpc);
    t = read_int();
    int i = 1;
    while(t--){
        val = read_int();
        printf("Case %d: %d\n",i, a[val].x);
        i++;
    }
}
