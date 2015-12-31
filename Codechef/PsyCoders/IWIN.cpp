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
unsigned char BitsSetTable256[256] = 
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};
int count(int v){
	int c; 
	c = BitsSetTable256[v & 0xff] + 
    	BitsSetTable256[(v >> 8) & 0xff] + 
    	BitsSetTable256[(v >> 16) & 0xff] + 
    	BitsSetTable256[v >> 24];
		
	return c; 
}
struct node{
	int x;
	int one;
};
bool cmpc(struct node a, struct node b){
	if(a.x > b.x)
		return false;
	else
		return true;
}
int main()
{
    int t;
    t = read_int();
    struct node a[15];
    BitsSetTable256[0] = 0;
	for (int i = 0; i < 256; i++){
  		BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
	}
    while(t--){
    	for(int i = 0; i < 15; i++){
    		int x = read_int();
    		a[i].x = x;
    		a[i].one = count(x);
    	}
    	int b = read_int();
    	sort(a, a+15, cmpc);
		int y;
		y = (a[0].x)^(a[1].x);
		for(int i = 2; i < 15; i++){
			y = y^(a[i].x);
		}
		if(count(y) > b)
			printf("YES\n");
		else
			printf("NO\n");
	}	
}
