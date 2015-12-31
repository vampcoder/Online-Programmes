#include<iostream>
#include<cstdio>

using namespace std;
int sum(int n, int a[n], int x){
    int k = 0;
    for(int i = 0; i < n; i++){
        k  = k + ((a[i] + x)%10);
    }
    return k;
}
int func1(int n, int a[n]){
    int k = sum(n, a, 0);
    int p;
    int x;
    for(i = 1; i < 10; i++){
        p = sum(n, a, i);
        if(k < p){
            k = p;
            x = i;
        }
    }
}

main(){
    int n;
    scanf("%d", &n);
    char ch;
    int a[n + 1];
    int i = 0;
    do{
        scanf("%c", &ch);
        if(ch >='0' && ch <= '9'){
            a[i] = ch - 48;
            i++;
        }
    }while(ch != '\n');
}
