#include<cstring>
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
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

long long int read_int1()
{
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
int main() {
   char a[2007][67];
   char ch1;
   int i = 0, j = 0;
   ch1 = gc();
   do{
    do{
        a[i][j++] = ch1;
        ch1 = gc();
    }while(ch1 != '\n');
    j = 0;
    i++;
    ch1 = gc();
   }while(ch1 != '\n');
   for(int k = 0; k < i; k++){
        int t = 0;
        for(int l = 0; l < strlen(a[k]); l++){
            if(a[k][l] == '/' && t == 0){
                if(a[k][l+1] == '/'){
                    t = 1;
                    printf("//");
                    l++;
                }else{
                    printf("/");
                }
            }else if(a[k][l] == '-' && t == 0){
                if(a[k][l+1] == '>'){
                    printf(".");
                    l++;
                }else{
                    printf("-");
                }
            } else{
                    printf("%c", a[k][l]);
            }
        }
        printf("\n");
   }

}
