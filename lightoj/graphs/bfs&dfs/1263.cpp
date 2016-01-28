#include<bits/stdc++.h>

using namespace std;
int n;
vector<vector<int> > v;
int a[1010];

bool bfs(void){
    int avg = -1;
    int visited[n+1];
    bool ans = true;
    memset(visited, -1, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(visited[i] == -1){
            visited[i] = 1;
            int sum = 0;
            int cnt = 0;
            queue<int> q;
            q.push(i);
            int p = 0;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                sum += a[x];
                cnt++;
                for(int j = 0; j < v[x].size(); j++){
                    if(visited[v[x][j]] == -1){
                        visited[v[x][j]] = 1;
                        q.push(v[x][j]);
                    }
                }
            }
            if(cnt == 1)
                continue;
            if(sum%cnt != 0){
                ans = false;
                break;
            }
            if(avg == -1){
                avg = sum / cnt;
            }else{
                if(avg != sum /cnt){
                    ans = false;
                    break;
                }
            }

        }
    }
    return ans;
}

int main()
{
    int t, m, x, y;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        v.resize(n+1);
        int sum = 0;
        for(int j = 1; j <= n; j++){
            cin >> a[j];
            sum += a[j];
        }
        for(int j = 0; j < m; j++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cout << "Case " << i << ": ";
        if(sum%n != 0){
            cout << "No\n";
            continue;
        }
        if(bfs()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
        v.clear();
    }
}
