#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
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

int main()
{
    int t;
    t = read_int();
    while(t--){
    	double a, b, c;
    	scanf("%lf%lf%lf", &a, &b, &c);
    	double s = (a+b+c)/2;
    	double A, B, C;
    	A = a + b - s;
    	B = a + c - s;
    	C = b + c - s;
    	double mul = a*b*c;
    	double sqt = 4*sqrt(s*A*B*C);
    	printf("%0.2f\n", mul/sqt);
	}
}
