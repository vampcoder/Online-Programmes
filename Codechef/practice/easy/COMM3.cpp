#include<iostream>
#include<cstdio>
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
bool close(int dx, int dy, int r) {
  return dx*dx + dy*dy <= r*r;
}
int main() {
    int t= read_int();
    int a,b,c,d,e,f,r;
    while(t--){
        r = read_int();
        a = read_int();
        b = read_int();
        c = read_int();
        d = read_int();
        e = read_int();
        f = read_int();
        int num = 0;
        if (close(a-c,b-d,r)) ++num;
        if (close(a-e,b-f,r)) ++num;
        if (close(c-e,d-f,r)) ++num;

        if(num > 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
