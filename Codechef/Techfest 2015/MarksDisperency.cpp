#include <iostream>
#include <cstdio>

using namespace std;

/*#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}*/

int main()
{
    int n;
    int x[5][100000];
    int p[5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char ch;
        scanf("%c", &ch);
        int c = (int)(ch-'A');
        scanf("%d", &x[c][p[c]++]);


    }

}
