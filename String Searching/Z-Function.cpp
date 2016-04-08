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
    cin >> text >> pat;
    strcpy(str, pat);
    int l = strlen(str);
    str[l] = '$';
    str[l+1] = '\0';
    strcpy(str+l+1, text);
    zfunc();
    l = strlen(str);
    int l1 = strlen(pat);
    for(int i = 0; i < l ;i++)
        if(z[i] == l1)
            cout << i-l1-1 << " ";
    cout << endl;
}
