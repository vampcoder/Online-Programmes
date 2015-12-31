#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
        int n;
        cin >> n;
        string str;
        while(n--){
                cin >> str;
                size_t found = str.find('C');
                if(str[0] == 'R' && found != string::npos && isdigit(str[1])){
                        int row = stoi(str.substr(1, found-1), NULL, 10);
                        int col = stoi(str.substr(found+1), NULL, 10);
                       // cout << row << " " << col << endl;
                        char a[15];
                        int i = 0;
                        while(col > 27){
                                int rem = col%27;
                                col /= 27;
                                a[i++] = rem+65;
                        }
                        a[i] = col+65;
                      	a[i+1] = '\0';
                        cout << a << row << endl;

                }else{
                	int i;
                	for(i = 0; i < str.length(); i++){
                		if(isdigit(str[i]))
                			break;
                	}
                	int j = i-1;
                	int col = 0;
                	int mul = 1;
                	while(j >= 0){
                		int x = str[j]-65;
                		col  = col*27 + x;
                		j--;
                	}
                	cout <<"R" <<str.substr(i) << "C" << col << endl;
                }
        }
}
