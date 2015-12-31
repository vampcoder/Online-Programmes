#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif

using namespace std;

long long int read_int()
{
    register char c=gc();
    while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
    long long int ret=0;
    while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
    {
        ret=ret*10+(c-48);//construct the number
        c=gc();
    }
    return ret;
}
long long int freq[1000009][4];
long long int query[1000009][12];
int calc(char c){ //for converting char to number
    if(c == 'c')
        return 0;
    else if(c == 'h')
        return 1;
    else if(c == 'e')
        return 2;
    else if(c == 'f')
        return 3;
}
char convert(int i){ //for converting number to char
    if(i == 0)
        return 'c';
    else if(i == 1)
        return 'h';
    else if(i == 2)
        return 'e';
    else
        return 'f';
}
void c_freq(int len, char arr[]){
    int j;
    for(int i = 0; i < 4; i++)
        freq[0][j] = 0;
    for(int i = 1; i <= len; i++){
        j = calc(arr[i-1]);
        for(int k = 0; k < 4; k++){
            if(k == j)
                freq[i][k] = freq[i-1][k] +1;
            else
                freq[i][k] = freq[i-1][k];
        }
    }
}
char convert2(char ch, int x){ //for converting number to char when first char has been choosen
    if(ch == 'c'){
        if(x == 0)
            return 'h';
        else if(x == 1)
            return 'e';
        else
            return 'f';
    }else if(ch == 'h'){
        if(x == 0)
            return 'c';
        else if(x == 1)
            return 'e';
        else
            return 'f';
    }else if(ch == 'e'){
        if(x == 0)
            return 'c';
        else if(x == 1)
            return 'h';
        else
            return 'f';
    }else if(ch == 'f'){
        if(x == 0)
            return 'c';
        else if(x == 1)
            return 'h';
        else
            return 'e';
    }
}
void c_query(int len, char arr[]){//Construction of Query DP table
    for(int i = 0; i < 12; i++)
        query[0][i] = 0;
    char ch1, ch2, ch3;
    int l,m;
    for(int i = 0; i < 12; i++){
        int a = 0;// For counting number of c, h, e, f appeared so far
        l = i/3;
        m = i%3;
        ch1 = convert(l);
        ch2 = convert2(ch1, m);
        for(int j = 1; j <= len; j++){
            ch3 = arr[j-1];
            if(ch3 == ch1)
                a++;
            if(ch2 == ch3)
                query[j][i] = query[j-1][i] + a;
            else
                query[j][i] = query[j-1][i];
        }
    }
}
//void print(int l){ //for printing DP table and frequency table
//    for(int i = 0; i <= l; i++){
//        for(int j = 0; j < 12; j++)
//            cout << query[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
//    for(int i = 0; i <= l; i++){
//        for(int j = 0; j < 4; j++)
//            cout << freq[i][j] << " ";
//        cout << endl;
//    }
//}
int calc2(int d, char ch){
    if(ch == 'c'){
        if(d == 'h')
            return 0;
        else if(d == 'e')
            return 1;
        else
            return 2;
    }else if(ch == 'h'){
        if(d == 'c')
            return 0;
        else if(d == 'e')
            return 1;
        else
            return 2;
    }else if(ch == 'e'){
        if(d == 'c')
            return 0;
        else if(d == 'h')
            return 1;
        else
            return 2;
    } else if(ch == 'f'){
        if(d == 'c')
            return 0;
        else if(d == 'h')
            return 1;
        else
            return 2;
    }
}
int main()
{
    char arr[1000008];
    scanf("%s", &arr);
    int len = strlen(arr);
    c_query(len, arr);
    c_freq(len, arr);
   // print(len);
    long long int n, a, b;
    char c, d;
    n = read_int();
    while(n--){
        c = gc();
        d = gc();
        d = gc();
        //cout << c << " " << d;
//        scanf("%s", &d);
        a = read_int();
        b = read_int();
        int i = calc(c), j = calc2(d, c);
        int k = calc(d);
        int x = (3*i+j);
        //cout << x << " ";
        long long int ans = query[b][x] - query[a][x];
        //cout << ans <<endl;
        ans -= (freq[a-1][i])*(freq[b][k] - freq[a][k]);
        printf("%lld\n", ans);
    }
}
