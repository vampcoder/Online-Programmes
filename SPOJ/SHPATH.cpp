#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<climits>
#include<queue>

#define ll long long int
#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpi vector< pi >
#define vvpi vector< vpi >
#define ppi pair<int , pi >
#define vppi vector< ppi >
#define qpi priority_queue< pi, vpi, cmpc>
#define qppi priority_queue< ppi, vppi, cmpc>
#define vqpi vector< qpi >

using namespace std;

class cmpc{
	public:
	bool operator() (pi x, pi y){
		return x.second > y.second;
	}
};

int cities;
qpi pq;
qpi pq2;
int dijkstra(vvpi &v, int si, int di, vll &path, vb &visited){
	pi t;
	vpi temp;
	t.first = si;
	t.second = 0;
	pq.push(t);
	while(!pq.empty()){
		pi x = pq.top();
		pq.pop();
		if(visited[x.first])
			continue;
		if(x.first == di)
			break;
		si = x.first;
		visited[x.first] = true;
		int s = v[si].size();
		for(int i = 0; i < s; i++){
			if(!visited[v[si][i].first]){
				pi x1;
				pi y;
				x1 = v[si][i];
				y.first = x1.first;
			if(path[x1.first] > path[x.first]+ (x1.second))
				path[x1.first] = path[x.first] + (x1.second);
			y.second = path[y.first];	
			pq.push(y);	
			}
		}
	}
	return path[di];
}
void print(vvpi v){
	cout << endl << endl;
	for(int i = 0; i <v.size(); i++){
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j].first << " " << v[i][j].second << " : ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int t, neighbours, n_num, cost;
	string str1, str2;
	char s[20];
	map<string, int> m;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d", &cities);
		vvpi v;
		for(int j = 0; j < cities; j++){
			scanf("%s", s);
			str1 = string(s);
			m[str1] = j;
			scanf("%d", &neighbours);
			vpi temp;
			for(int k = 0; k < neighbours; k++){
				scanf("%d%d", &n_num, &cost);
				pi y;
				y.first = n_num-1;
				y.second = cost;
				temp.push_back(y);
			}
			v.push_back(temp);
		}
		int queries;
		char s1[20];
		scanf("%d", &queries);
		while(queries--){
			vll path(cities+5,INT_MAX);
			vb visited(cities+5, false);
			scanf("%s%s", s, s1);
			str1 = string(s);
			str2 = string(s1);
			int si = m[str1];
			path[si] = 0;
			int di = m[str2];
			printf("%d\n",dijkstra(v, si, di, path, visited));
			while(!pq.empty())
				pq.pop();
		}		
	}
}
