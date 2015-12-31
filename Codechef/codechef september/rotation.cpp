#include <iostream>
#include <cstdio>

using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    int a[x];
    for(int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }
    char l, s;
    int m, i = 0;
    for(int j = 0; j < y; j++){
        scanf("%c", &s);
        scanf("%c", &l);
        scanf("%d", &m);
        if (l == 'R'){
            printf("%d\n", a[(i+m-1)%x]);
        }else if( l == 'C') {
            i = (i + m)%x;
        }else if(l == 'A'){
            i = (x - m + i) % x;
        }
    }
}
