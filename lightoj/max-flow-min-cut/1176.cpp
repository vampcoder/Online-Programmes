//Maximum flow from source to sink using bfs
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<map>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int n, e;
vii v;

int bfs(int source, int sink){
	queue<int> q;
	q.push(source);
	int from[e+8];
	int visit[e+8];
	for(int i = 0; i < e+8; i++){
		visit[i] = -1;
		from[i] = -1;
	}
	from[source] = source;
	while(!q.empty()){
		int temp = q.front();
		visit[temp] = 1;
		q.pop();
		bool found_sink = false;
		int i;
		for(i = 0; i < e+8; i++){
			if(v[temp][i] > 0 && visit[i] != 1){
					q.push(i);
					from[i] = temp;
					if(i == sink){
						found_sink = true;
						break;
					}
			}
		}
		int m = INT_MAX;
		if(found_sink){
			int y = sink;
			int x;
			while(y != source){
				x = from[y];
				m = min(m, v[x][y]);
				y = x;
			}
			if(m == 0)
					return 0;
			y = sink;
			while(y != source){
				x = from[y];
				v[x][y] -= m;
				v[y][x] += m;
				y = x;
			}
			return m;
		}
	}
	return 0;
}

int main()
{
	int t, x, y, c;
	cin >> t;
	for(int k = 1; k <= t; k++){
		map<string, int> m;
		m["XS"] = 1;
		m["S"] = 2;
		m["M"] = 3;
		m["L"] = 4;
		m["XL"] = 5;
		m["XXL"] = 6;
		scanf("%d", &n); // no of colors
//		int e; //no of contestants
		scanf("%d", &e);
		for(int i = 0; i < e+8; i++){
				vi t(e+8);
				v.push_back(t);
		}

		char a[5], b[5]; 
		for(int i = 1; i <= e; i++)
				v[0][i] += 1;
		for(int i = 1; i <= e; i++){
			scanf("%s%s",&a, &b);
			v[i][e+m[a]] += 1;
			v[i][e+m[b]] += 1;
		}
		
		for(int j = e+1; j < e+7; j++){
			v[j][e+7] += n;
		}
/*		for(int i = 0; i <e+8; i++){
				for(int j = 0; j < e+8; j++)
						cout << v[i][j] << " ";
			cout << endl;
		}
		*/
		int ans = 0;
		x = bfs(0, e+7);
		while(x != 0){
/*		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
					cout << v[i][j] << " ";
			cout << endl;
		}
		cout << endl;
*/			ans += x;
//		cout << "x : "<< x << endl;
			x= bfs(0, e+7);
		}
		if(ans == e){
			printf("Case %d: YES\n", k);
		}else{
			printf("Case %d: NO\n", k);
		}
		v.clear();
	//	cout <<"cleared\n";
	}
}
