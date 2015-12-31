
#include<cstring>
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
int count1(char a){
    if(a == 'A' || a == 'D' || a == 'O' || a == 'P' || a == 'Q' || a == 'R') {
        return 1;
    }else if(a == 'B'){
        return 2;
    }else {
        return 0;
    }

}
int main() {
    int t  ;
    t = read_int();
    char ch;
    int l = 0;
    for(int i = 0; i < t; i++){
        l = 0;
        do{
            ch = gc();
            l += count1(ch);
        }while(ch != '\n');
        printf("%d\n", l);
    }
}
