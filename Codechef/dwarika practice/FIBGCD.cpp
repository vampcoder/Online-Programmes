#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

int read_int() {
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
int gcd(int a, int b) {
  int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long int read_int1() {
    register char c=gc();
    while(c<'0'||c>'9')
        c=gc();  //ignore all characters till the first digit
    long long int ret=0;
    while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
    {
    ret=ret*10+(c-48);//construct the number
    c=gc();
    }
    return ret;
}
int arr[1000007];
int main() {
    int t = read_int();
    int x = 1000000007;
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < 1000007; i++){
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] = arr[i] % x;
    }
    int a, b, p;
    while(t--){
    a = read_int();
    b = read_int();
    p = gcd(a, b);
    printf("%d\n", arr[p]);
    }

}
