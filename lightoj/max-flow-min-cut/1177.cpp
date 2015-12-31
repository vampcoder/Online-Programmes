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
	int from[2*n];
	int visit[2*n];
	for(int i = 0; i < 2*n; i++){
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
		for(i = 0; i < 2*n; i++){
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
		int e; //no of edges
		scanf("%d", &e);
//		int source, sink;
	//	cin >> source >> sink;
		for(int i = 0; i < 2*n; i++){
				vi t(2*n);
				v.push_back(t);
	//			r.push_back(t);
		}
		int capacity;
		for(int i = 1; i <= n-2; i++){
			scanf("%d",&capacity);
			v[i][n+i] += capacity;
			v[n+i][i] += capacity;
		}
		v[0][n] += INT_MAX;
		v[n][0] += INT_MAX;
		v[n-1][2*n-1] += INT_MAX;
		v[2*n-1][n-1] += INT_MAX;
		
//		scanf("%d", &e);
		for(int j = 0; j < e; j++){	
			scanf("%d%d%d", &x, &y, &c);
				v[n+x-1][y-1] += c;
				v[n+y-1][x-1] += c;
		}
//	cout << endl;
		int b, d;
	/*	scanf("%d%d", &b, &d);
		for(int i = 0; i < b; i++){
			scanf("%d", &x);
			v[0][x] = INT_MAX;
		}
		for(int i = 0; i < d; i++){
			scanf("%d", &x);
			v[n+x][2*n+1] = INT_MAX;
			
		}*/
/*		for(int i = 0; i <2*n; i++){
				for(int j = 0; j < 2*n; j++)
						cout << v[i][j] << " ";
			cout << endl;
		}
*/		int ans = 0;
		x = bfs(n, n-1);
		while(x != 0){
/*		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
					cout << v[i][j] << " ";
			cout << endl;
		}
		cout << endl;
*/			ans += x;
//		cout << "x : "<< x << endl;
			x= bfs(n, n-1);
		}
		printf("Case %d: %d\n", k, ans);
		v.clear();
	//	cout <<"cleared\n";
	}
}
