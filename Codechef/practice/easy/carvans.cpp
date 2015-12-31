#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
//#define tr(a) for(typeof(a) it = a.begin(); it != a.end(); it++)
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

int gcd(int a, int b) {
  int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int i = 0;
		int b;
        scanf("%d", &b);
		char a[255];

		char ch = gc();
		ch = gc();
		while(ch != '\n'){
			a[i++] = ch;
			//cout << ch << " ";
			ch = gc();
		}
		a[i] = '\0';
       // printf("\n%s\n", a);
        if(b == 0){
            printf("%s\n", a);
            continue;
        }
		i = 1;
		int x = a[0]-48;
		while(a[i] != '\0'){
			x = (x*10+(a[i]-48))%b;
			i++;
		}
		printf("%d\n", gcd(b,x));
	}
}
