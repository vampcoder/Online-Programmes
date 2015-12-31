#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int a[n];
        int h[100005] = {0};
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int x, p = -1;
        int c = 0;
        for(int i = 1; i < n-1; i++){
            if(a[i] != a[i-1]){
                if(p == i-1){

                }else{

                }
            }


        }

    }
}
