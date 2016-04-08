#include<bits/stdc++.h>

using namespace std;

char text[1000010];
char pat[1000010];
char str[1000010];
int z[1000010] = {0};

void zfunc(){
    int n = strlen(str);
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if (i + z[i] - l > r)
            l = i, r = i + z[i] -1;
    }
}

int main()
{
    scanf("%s", str);
    int l = strlen(str);
    zfunc();
    int zmax = 0;
    int ans = -1;
    for(int i = 1; i < l ;i++){
        if(z[i] == l-i && zmax >= z[i]){
            ans = l-i;
            break;
        }
        zmax = max(zmax, z[i]);
    }
    if(ans == -1){
        printf("Just a legend");
    }else{
        for(int i = 0; i < ans; i++){
            printf("%c", str[i]);
        }
        printf("\n");
    }
}
