#include<bits/stdc++.h>

using namespace std;
typedef pair<string, int> pi;
map<string, int>::iterator it;

string s, e;
map<string, int> m;

char next(char a){
    if(a == 'z')
        a = 'a';
    else
        a = a + 1;
    return a;
}
char prev(char a){
    if(a == 'a')
        a = 'z';
    else
        a = a-1;
    return a;
}

int bfs(){
    if(m.find(s) != m.end() ||  m.find(e) != m.end()){
        return -1;
    }
    if(s == e){
        return 0;
    }
    queue<pi > q;
    pi temp;
    temp.first = s;
    temp.second = 0;
    m[s] = 0;
    q.push(temp);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        string tem = temp.first;


        int cost = temp.second;
        for(int i = 0; i < 3; i++){
            string str = tem;
            str[i] = next(str[i]);
            if(str == e){
                return cost+1;
            }
            it = m.find(str);
            if(it == m.end()){
                temp.first = str;
                temp.second = cost+1;
                m[str] = cost+1;
                q.push(temp);
            }
            str = tem;
            str[i] = prev(str[i]);
            if(str == e)
                return cost+1;
            it = m.find(str);
            if(it == m.end()){
                temp.first = str;
                temp.second = cost+1;
                m[str] = cost+1;
                q.push(temp);
            }
        }

    }
    return -1;
}


int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        m.clear();
        cin >> s >> e;
        int n;
        cin >> n;
        string first, second, third;
        for(int j = 0; j < n; j++){
            cin >> first >> second >> third;
            for(int I = 0; I < first.length(); I++){
                for(int J = 0; J < second.length(); J++){
                    for(int K = 0; K < third.length(); K++){
                        string temp = "";
                        temp += first[I];
                        temp += second[J];
                        temp += third[K];
                  //      cout << temp << " ";
                        m[temp] = -1;
                    }
                }
            }
        }
      //  cout << endl;
        cout << "Case " << i << ": " << bfs() << endl;
    }
}
