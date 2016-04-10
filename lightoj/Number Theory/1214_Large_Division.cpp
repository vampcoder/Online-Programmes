#include<bits/stdc++.h>

using namespace std;

char arr[220];
long long po[20];

string check(int div){
    long long int num;
    string yes = "divisible";
    string no = "not divisible";
    char temp[20];
    int len = strlen(arr);

    int rem = 0;
    if(len <= 17){
        //cout << "yes" << endl;
        num = atoll(arr);
        //cout << "num " << num << endl;
        rem = num%div;
        if(rem == 0){
            return yes;
        }else{
            return no;
        }
    }
    int i = 0;

    while(i < len){
        int s;
        if(rem == 0){
            s = 0;
        }else{
            s = floor(log10(rem)) + 1;
        }
        int j = 0;
        while(s+j < 17 && i < len){
            temp[j] = arr[i];
            j++;
            i++;
        }
        temp[j] = '\0';
        num = atoll(temp);
        num += rem*po[j];
        rem = num%div;
    }
    if(rem == 0){
        return yes;
    }else{
        return no;
    }
}


int main()
{
    po[0] = 1;
    for(int i = 1; i < 19; i++){
        po[i] = 10*po[i-1];
    }
    int t, div;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> arr >> div;
        if(arr[0] == '-'){
            strcpy(arr, arr+1);
        }
        if(div < 0){
            div *= -1;
        }
        //cout << arr << endl;
        string s = check(div);
        //cout << s << endl;
        cout << "Case " << i << ": " << s << endl;

    }
}
