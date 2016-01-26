#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
int t, n, alp, sx, sy;
char str[12][12];
int visit[12][12];

int bfs(){
	int cost = 0;

    bool flag = true;
	for(int i = 1; i <= alp; i++){
        int tcost = 0;
		memset(visit, -1, sizeof(visit));
		queue<ppi > q;
		ppi temp;
		pi tem;
		tem.first = sx;
		tem.second = sy;
		temp.first = tem;
		temp.second = 0;
		q.push(temp);
		while(!q.empty()){
			temp = q.front();
            q.pop();
            int a[] = {1, -1, 0, 0};
            int b[] = {0, 0, -1, 1};
            tem = temp.first;
            int x = tem.first;
            int y = tem.second;
            int c = temp.second;
            if(visit[x][y] == 1){
                continue;
            }
            visit[x][y] = 1;

            temp.second++;

            for(int j = 0; j < 4; j++){
                int dx = x + a[j];
                int dy = y + b[j];

                if(dx >= 0 && dx < n && dy >= 0 && dy < n && str[dx][dy] != '#'){
                    if(visit[dx][dy] == -1){
                        if(str[dx][dy] == 'A'+i){
                            str[dx][dy] = '.';
                            str[sx][sy] = '.';
                            tcost += temp.second;
                            sx = dx;
                            sy = dy;
                            while(!q.empty())
                                q.pop();
                            break;
                        }else if(str[dx][dy] == '.'){
                            tem.first = dx;
                            tem.second = dy;
                            temp.first = tem;
                            q.push(temp);
                        }
                    }
                }
            }
		}
		if(tcost == 0){
            flag = false;
		}
		cost += tcost;
	}


	if(flag)
        return cost;
    else
        return -1;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			scanf("%s", str[j]);
		}
		alp = -1;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(str[j][k] != '.' && str[j][k] -'A' > alp){
					alp = str[j][k]-'A';
				}
				if(str[j][k]-'A' == 0){
					sx = j;
					sy = k;
				}
			}
		}
		//cout << sx << " " << sy << endl;

		if(alp == 0){
            cout << "Case " << i << ": " << "0" << endl;
            continue;
		}
		int ans = bfs();
		if(ans > 0)
            cout << "Case " << i << ": " << ans << endl;
        else
            cout << "Case " << i << ": Impossible" << endl;
	}
}
