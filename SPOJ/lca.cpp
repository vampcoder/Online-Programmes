#include<bits/stdc++.h>

using namespace std;

vector<int>v[1002];
int path[2002] = {-1};
int level[2002] = {-1};
int h[1002] = {-1};
int p = 0;
int child[1002] = {-1};
int seg[8010];

void construct(int ss, int se, int idx){
	if(ss == se){
		seg[idx] = ss;
		return;		
	}
	int mid = (ss+se)/2;
	construct(ss, mid, 2*idx+1);
	construct(mid+1, se, 2*idx+2);
	if(level[seg[2*idx+1]] < level[seg[2*idx+2]]){
		seg[idx] = seg[2*idx+1];
	}else{
		seg[idx] = seg[2*idx+2];
	}
}

int query(int ss, int se, int idx, int q_s, int q_e){
//	cout << ss << " " << se << endl;	
	if(ss > q_e || se < q_s)
		return 2001;
	if(ss >= q_s && q_e >= se){
		return seg[idx];
	}
	int mid = (ss+se)/2;
	int l = query(ss, mid, 2*idx+1, q_s, q_e);
	int r = query(mid+1, se, 2*idx+2, q_s, q_e);
	if(level[r] < level[l]){
		return r;
	}else{
		return l;
	}
}

void dfs(int node, int l){
	if(h[node] == -1)
		h[node] = p;
	path[p] = node;
	level[p++] = l;
	for(vector<int>::iterator it = v[node].begin(); it != v[node].end(); it++){
		dfs(*it, l+1);
		path[p] = node;
		level[p++] = l;		
	}
}

int main()
{
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++){
		int n;
		cin >> n;
		int m, x;
		for(int i = 0; i < n; i++){
			cin >> m;
			for(int j = 0; j < m; j++){
				cin >> x;
				v[i].push_back(x-1);
				child[x-1] = 1;
			}
		}
		int ch = -1;
		for(int i = 0; i < n; i++)
			if(child[i] == -1){
				ch = i;	
				break;
			}
		//cout << ch << endl;
		for(int i = 0; i < 2*n; i++){
			level[i] = -1;
			path[i] = -1;
			h[i] = -1;
			child[i] = -1;
		}
		for(int i = 0; i < 8*n; i++)
			seg[i] = 0;
		p = 0;
		dfs(ch, 0);
		for(int i = 0; i < 2*n-1; i++)
			cout << path[i]+1 << " ";
		cout << endl;
		for(int i = 0; i < 2*n-1; i++)
			cout << level[i] << " ";
		cout << endl;
		for(int i = 0; i < n; i++)
			cout << h[i] << " ";
		cout << endl;				
		construct(0, 2*n-1, 0);
		level[2001] = INT_MAX;
		int q;
		cin >> q;
		int a, b;
		cout << "Case " << k << ":" << endl;
		for(int i = 0; i < q; i++){
			cin >> a >> b;
			a--;
			b--;
			if(h[a] < h[b])
				cout << path[query(0, 2*n-1, 0, h[a], h[b])]+1 << endl;
			else
				cout << path[query(0, 2*n-1, 0, h[b], h[a])]+1 << endl;			
		}
		for(int i = 0; i < 1002; i++)
			v[i].clear();		

	}
}
