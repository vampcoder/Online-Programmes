#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

#define pb push_back

vvi g;
int t, k, n, m;
int people[1002];
int c[1002];
int visit[1002];

int bfs(){
    for(int i = 1 ;i <= n; i++){
        if(people[i] == 1){
            memset(visit, 0, sizeof(visit));
            queue<int> q;
            q.push(i);
            c[i]++;
            visit[i] = 1;
            while(!q.empty()){
                int x = q.front();
                q.pop();

                for(int j = 0; j < g[x].size(); j++){
                    int y = g[x][j];
                    if(visit[y] == 0){
                        visit[y] = 1;
                        c[y]++;
                        q.push(y);
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      //  cout << c[i] << " ";
        if(c[i] == k)
            cnt++;
    }
    //cout << endl;
    return cnt;
}

int main()
{
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){

        memset(people, 0, sizeof(people));
        memset(c, 0, sizeof(c));
        scanf("%d%d%d", &k, &n, &m);
        int p;
        for(int j = 0; j < k; j++){
            scanf("%d", &p);
            people[p] = 1;
        }
        for(int j = 0; j <= n; j++){
            vi temp;
            g.pb(temp);
        }
        int x, y;
        for(int j = 0; j < m; j++){
            scanf("%d%d", &x, &y);
            g[x].pb(y);
        }
        printf("Case %d: %d\n", i, bfs());
        g.clear();
	}
}
