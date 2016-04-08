#include<bits/stdc++.h>

using namespace std;

char text[1000010];
char pat[1000010];
char str[1000010];
int z[1000010] = {0};

void zfunc(){
    int lp = strlen(pat);
    int count = 0;
    bool flag = true;
    char ch;
    int j = 0;
    scanf("%c", &ch);

    while(1){
        while(ch != '\0' && ch != '\n' && j < lp+2){
            str[j + lp + 1] = ch;
            j++;
            scanf("%c", &ch);
        }
        str[j] = '\0';
        int n = strlen(str);
        int mark = 0;
        for(int i = lp+1, l = lp, r = lp; i < n; i++){
            if(i <= r)
                z[i] = min(r-i+1, z[i-l]);
            while(i + z[i] < n && str[z[i]] == str[i + z[i]])
                ++z[i];
            if (i + z[i] - l > r)
                l = i, r = i + z[i] -1;
            if(z[i] == lp){
                flag = false;
                cout << count << endl;
                mark = i;
            }
        }

        if(ch == '\0' || ch == '\n')
            break;
    }
    if(flag)
        cout << endl;
}

int main()
{
    int t, l;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        scanf("%s", pat);
        strcpy(str, pat);
        int l = strlen(str);
        str[l] = '$';
        str[l+1] = '\0';
        zfunc();
    }
}
