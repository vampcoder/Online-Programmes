//Maximum flow from source to sink using bfs
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<cstdio>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int n;
vii v;

int bfs(int source, int sink){
	queue<int> q;
	q.push(source);
	int from[n];
	int visit[n];
	for(int i = 0; i < n; i++){
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
//		cout << "temp : " << temp << endl;
		for(i = 0; i < n; i++){
		//		cout << v[temp][i] << " " << visit[i] << endl;
			if(v[temp][i] > 0 && visit[i] != 1){
					q.push(i);
					from[i] = temp;
					if(i == sink){
						found_sink = true;
						break;
					}
			}
		}
//		cout << endl;
//		cout << "hi\n";
//		cout << found_sink << endl;
		int m = INT_MAX;
		if(found_sink){
			int y = sink;
			int x;
			while(y != source){
				x = from[y];
				m = min(m, v[x][y]);
				y = x;
			}
//			cout << "hi2" << endl;
			if(m == 0)
					return 0;
			y = sink;
			while(y != source){
			//	cout << y << " ";
				x = from[y];
				v[x][y] -= m;
				v[y][x] -= m;
				y = x;
			}
//			cout << endl;
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
			
	scanf("%d", &n); // no of nodes
	vii r(n);
	int e; //no of edges
	int source, sink;
	cin >> source >> sink;
	scanf("%d", &e);
	for(int i = 0; i < n; i++){
			vi t(n);
			v.push_back(t);
			r.push_back(t);
	}
	for(int j = 0; j < e; j++){	
		scanf("%d%d%d", &x, &y, &c);;
		v[x-1][y-1] += c;
		v[y-1][x-1] += c;
	}
/*	for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
					cout << v[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/
	int ans = 0;
	x = bfs(source-1, sink-1);
	while(x != 0){
/*		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
					cout << v[i][j] << " ";
			cout << endl;
		}
		cout << endl;
*/		ans += x;
//		cout << "x : "<< x << endl;
		x= bfs(source-1, sink-1);
	}
	printf("Case %d: %d\n", k, ans);
	v.clear();
//	cout <<"cleared\n";
	}
}
