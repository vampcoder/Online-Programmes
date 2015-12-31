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

int main()
{
    int t;
    t = read_int();
    while(t--){
    	int x = 0;
    	int m[26];
    	for(int i = 0; i < 26; i++)
    		m[i] = 0;
    	char ch = gc();
    	while(ch != '\n'){
    		if(ch >=65 && ch <= 90)
    			m[ch-65] += 1;
    		else if(ch >= 97 && ch <= 122)
    			m[ch-97] += 1;
    		ch = gc();
    	}
    	int j = 0;
		for(int i = 0; i < 26; i++){
			if(x <= m[i]){
				x = m[i];
				j = i;
			}
		}
		printf("%c\n", j+97);	
	}	
}
