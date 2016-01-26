#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef vector<pi > vpi;

int m, n;
char g[12][12];
vpi s;
int c[12][12];
int tc[12][12];
int visited[12][12];
int cnt[12][12];

            int a[] = {1, 1, 2, 2, -1, -1, -2, -2};
            int b[] = {2, -2, 1, -1, 2, -2, 1, -1};

void dfs(int x, int y, int d, int step, queue<ppi > &q, int cost){

    if(d >= step)
        return;

    ppi temp;
    pi tem;

    for(int i = 0; i < 8; i++){
        int x2 = x + a[i];
        int y2 = y + b[i];
        if(x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && c[x2][y2] > cost+1){
            c[x2][y2] = cost;
            tem.first = x2;
            tem.second = y2;
            temp.first = tem;
            temp.second = cost+1;
            if(d == step-1)
        		q.push(temp);
            dfs(x2, y2, d+1, step, q, cost);
        }
    }
}

int bfs(){
    memset(tc, 0, sizeof(tc));
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < s.size(); i++){
        memset(visited, -1, sizeof(visited));
        for(int j = 0; j < m; j++){
            for(int l = 0; l < n; l++)
                c[j][l] = INT_MAX;
        }

        ppi temp;
        pi tem = s[i];

        int cost = 0;

        temp.first = tem;
        temp.second = cost;

        queue <ppi > q;

        int step = g[tem.first][tem.second] -'0';
        q.push(temp);

        c[tem.first][tem.second] = 0;

        while(!q.empty()){
            temp = q.front();
            q.pop();

            tem = temp.first;

            int x = tem.first;
            int y = tem.second;
            if(visited[x][y] != -1)
                continue;
            visited[x][y] = 1;

            cost = (temp.second + step -1)/step;
            c[x][y] = cost;
            temp.second++;

            for(int j = 0; j < 8; j++){
                int x2 = x + a[j];
                int y2 = y + b[j];
                if(x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && visited[x2][y2] == -1){
                        tem.first = x2;
                        tem.second = y2;
                        temp.first = tem;
                        q.push(temp);
                }
            }
     //       if(c[x][y] < cost)
       //         continue;
       //     c[x][y] = cost;
           // int x1 = x, y1 = y;

           // dfs(x, y, 0, step, q, cost);
        }

        for(int j = 0; j < m; j++){
            for(int l = 0; l < n; l++){
                if(c[j][l] != INT_MAX){
                    tc[j][l] += c[j][l];
                    cnt[j][l]++;
                }
            }
        }
        /*for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << visited[i][j];
        cout << endl;
    }
    cout << endl;*/
    }
    int k = s.size();
  /*  cout << k << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << cnt[i][j] << " ";
        cout << endl;
    }
    cout << endl;
*/
    int ans = INT_MAX;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(cnt[i][j] == k){
                ans = min(ans, tc[i][j]);
            }
        }
    }
    if(ans == INT_MAX){
        return -1;
    }else{
        return ans;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        s.clear();
        cin >> m >> n;

        for(int j = 0; j < m; j++){
            cin >> g[j];
        }

        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                if(g[j][k] != '.'){
                    pi temp;
                    temp.first = j;
                    temp.second = k;
                    s.push_back(temp);
                }
            }
        }



   //     for(int j = 0; j < s.size(); j++)
     //       cout << s[j].first << " " << s[j].second <<   " \n ";
     //   cout << endl;
        cout << "Case " << i << ": " << bfs() << endl;
    }
}
