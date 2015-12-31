#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int freq[1000007][4];
int query[1000007][12];

void c_freq(int len, char arr[]){
    int j;
    for(int i = 0; i < 4; i++)
        freq[0][j] = 0;
    for(int i = 1; i <= len; i++){
        char ch = arr[i];
        if(ch == 'c')
            j = 0;
        else if(ch == 'h')
            j = 1;
        else if(ch == 'e')
            j = 2;
        else
            j = 3;
        for(int k = 0; k < 4; k++){
            if(k == j)
                freq[i][k] = freq[i-1][k] +1;
            else
                freq[i][k] = freq[i-1][k];
        }
    }
}
void c_query(int len, char arr[]){
    for(int i = 0; i < 12; i++)
        query[0][i] = 0;
        int a[4] = {0};
    for(int i = 0; i < 12; i++){
        if(i < 3){
            for(int j = 1; j <= len; j++){
                if(i == 0){
                    if(arr[j-1] == 'h'){
                        a[1]++;
                        query[i][j] = query[i][j-1] + a[0];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i == 1){
                    if(arr[j-1] == 'e'){
                        a[2]++;
                        query[i][j] = query[i][j-1] + a[0];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i == 2){
                    if(arr[j-1] == 'f'){
                        a[3]++;
                        query[i][j] = query[i][j-1] + a[0];
                    }else
                        query[i][j] = query[i][j-1];
                }
            }
        }else if(i < 6){
            for(int j = 1; j <= len; j++){
                if(i%3 == 0){
                    if(arr[j-1] == 'c'){
                        a[0]++;
                        query[i][j] = query[i][j-1] + a[1];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i%3 == 1){
                    if(arr[j-1] == 'e'){
                        a[2]++;
                        query[i][j] = query[i][j-1] + a[1];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i%3 == 2){
                    if(arr[j-1] == 'f'){
                        a[3]++;
                        query[i][j] = query[i][j-1] + a[1];
                    }else
                        query[i][j] = query[i][j-1];
                }
            }
        }else if(i < 9){
            for(int j = 1; j <= len; j++){
                if(i%3 == 0){
                    if(arr[j-1] == 'c'){
                        a[0]++;
                        query[i][j] = query[i][j-1] + a[2];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i%3 == 1){
                    if(arr[j-1] == 'h'){
                        a[1]++;
                        query[i][j] = query[i][j-1] + a[2];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i%3 == 2){
                    if(arr[j-1] == 'f'){
                        a[3]++;
                        query[i][j] = query[i][j-1] + a[2];
                    }else
                        query[i][j] = query[i][j-1];
                }
            }
        }else{
            for(int j = 1; j <= len; j++){
                if(i%3 == 0){
                    if(arr[j-1] == 'c'){
                        a[0]++;
                        query[i][j] = query[i][j-1] + a[3];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i%3 == 1){
                    if(arr[j-1] == 'h'){
                        a[1]++;
                        query[i][j] = query[i][j-1] + a[3];
                    }else
                        query[i][j] = query[i][j-1];
                }else if(i%3 == 2){
                    if(arr[j-1] == 'e'){
                        a[2]++;
                        query[i][j] = query[i][j-1] + a[3];
                    }else
                        query[i][j] = query[i][j-1];
                }
            }
        }
    }
}
int calc(char c){
    if(c == 'c')
        return 0;
    else if(c == 'h')
        return 1;
    else if(c == 'e')
        return 2;
    else if(c == 'f')
        return 3;
}
void print(int l){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < 12; j++)
            cout << query[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < 4; j++)
            cout << freq[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    char arr[1000008];
    scanf("%s", &arr);
    int len = strlen(arr);
    c_query(len, arr);
    c_freq(len, arr);
    print(len);
    int n, a, b;
    char c, d;
    scanf("%d", &n);
    while(n--){
        cin >> c >> d;
        scanf("%d%d", &a, &b);
        int i = calc(c), j = calc(d);
        int x = 3*i+j;
        int ans = query[b][x] - query[a][x];
        ans -= (freq[a][i])*(freq[b][j] - freq[b][i]);
        cout << ans << endl;
    }
}
