#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        string a, b, c;
        stack<string> back;
        stack<string> forward;
        cout<<"Case "<<i<<":\n";
        c = "http://www.lightoj.com/";
        for(int j = 1; j >= 1;){
            cin >> a;
            if(j == 1){
                if(a[0] == 'Q'){
                    break;
                }else if(a[0] == 'B'){
                    if(back.empty())
                        cout << "Ignored" << endl;
                    else{
                        cout << back.top() << endl;
                        back.pop();
                        j++;
                        }
                }else if(a[0] == 'V'){
                    back.push(c);
                    cin >>b;
                    j++;
                    cout << b <<endl;
                    while(!forward.empty())
                        forward.pop();
                }else if(a[0] == 'F'){
                    if(forward.empty())
                        cout << "Ignored"<<endl;
                    else{
                        b = forward.top();
                        cout<< b << endl;
                        j++;
                        forward.pop();
                        }
                }
            }else{
                if(a[0] == 'Q'){
                    break;
                }else if(a[0] == 'B'){
                    if(back.empty())
                        cout << "Ignored" << endl;
                    else{
                        forward.push(b);
                        b = back.top();
                        cout << b << endl;
                        back.pop();
                        }
                }else if(a[0] == 'V'){
                    back.push(b);
                    cin >> b;
                    cout << b <<endl;
                    while(!forward.empty())
                        forward.pop();
                }else if(a[0] == 'F'){
                    if(forward.empty())
                        cout << "Ignored"<<endl;
                    else{
                        back.push(b);
                        b = forward.top();
                        cout<< b << endl;
                        forward.pop();
                        }
                }
            }
        }
    }


}
