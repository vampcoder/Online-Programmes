
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>

using namespace std;
#define N 30100
#define LN 20

vector<int> v[N];
int genie[N];
int seg[8*N];
int hldSeg[4*N];
int n, a, b, c;
int chainNo, base;
int baseArr[N], chainHead[N], chainIdx[N], posInBase[N];
int depthidx[2*N]; //value of node in depth array
int depth[2*N]; //saving dept of node from root
int di;
int subSize[N];
int edgeNode[N];
int pa[LN][N];
void clearall(int n){
    for(int i = 0; i < n; i++){
        v[i].clear();
        for(int j = 0; j < LN; j++)
            pa[j][i] = -1;
    }
    memset(chainHead, -1, sizeof chainHead);
    chainNo = 0;
    base = 0;
    di = 0;
}

int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void build(int ss, int se, int idx){
    if(ss == se){
        hldSeg[idx] = baseArr[ss];
        return;
    }
    int mid = (ss+ se)/2;
    build(ss, mid, 2*idx+1);
    build(mid+1, se, 2*idx+2);

    hldSeg[idx] = hldSeg[2*idx+1]+ hldSeg[2*idx+2];
}

int query(int ss, int se, int idx, int qs, int qe){
    if(qs > se || qe < ss)
        return 0;

    if(qs <= ss && qe >= se){
        return hldSeg[idx];
    }
    int mid = (ss+se)/2;
    return query(ss, mid, 2*idx+1, qs, qe)+ query(mid+1, se, 2*idx+2, qs, qe);
}

void update(int ss, int se, int idx, int u, int val){
    if(u < ss || u > se)
        return;
    if(ss == se){
        hldSeg[idx] = val;
        return;
    }
    int mid = (ss+se)/2;
    update(ss, mid, 2*idx+1, u, val);
    update(mid+1, se, 2*idx+2, u, val);
    hldSeg[idx] = hldSeg[2*idx+1]+ hldSeg[2*idx+2];
}

int queryChain(int u, int v){
    int uchain, vchain = chainIdx[v], ans = 0;
    while(1){
        uchain = chainIdx[u];
        if(uchain == vchain){
            ans += query(0, base-1, 0, posInBase[v], posInBase[u]);
            return ans;
        }
        ans += query(0, base-1, 0, posInBase[chainHead[uchain]], posInBase[u]);
        u = chainHead[uchain];
        u = pa[0][u];
    }
}

void HLD(int cur, int c, int prev){
    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = cur;
    }
    chainIdx[cur] = chainNo;
    posInBase[cur] = base;
    baseArr[base++] = c; //storing cost of each edge as cost of node

    int sc = -1, temp;
    for(int i = 0; i < v[cur].size(); i++){
        if(v[cur][i] != prev){
            if(sc == -1 || subSize[sc] < subSize[v[cur][i]]){
                sc = v[cur][i];
                temp = genie[v[cur][i]];
            }
        }
    }
    if(sc != -1){
        HLD(sc, temp, cur);
    }

    for(int i = 0; i < v[cur].size(); i++){
        if(v[cur][i] != prev){
            if(v[cur][i] != sc){
                chainNo++;
                HLD(v[cur][i], genie[v[cur][i]], cur);
            }
        }
    }
}

void dfs(int cur, int prev, int d){
    depth[cur] = d;
    subSize[cur] = 1;
    pa[0][cur] = prev;

    for(int i = 0; i < v[cur].size(); i++){
        if(v[cur][i] != prev){
            dfs(v[cur][i], cur, d+1);
            subSize[cur] += subSize[v[cur][i]];
        }
    }
}

int userQuery(int u, int v){
    int lca = LCA(u, v);
    int ans = queryChain(v, lca)+ queryChain(u, lca) - queryChain(lca, lca);
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++){
        scanf("%d", &n);
        clearall(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &genie[i]);
        }
        for(int i = 0; i < n-1; i++){
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(0, -1, 0);
        depth[di] = INT_MAX;
        HLD(0, genie[0], -1);
        build(0, base-1, 0);
        int s;
        int l, r;
        for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
        printf("Case %d:\n", tc+1);
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &s);
            scanf("%d%d", &l, &r);
            if(s == 1){
                update(0, base-1, 0, posInBase[l], r);
            }else{
                printf("%d\n", userQuery(l, r));
            }
        }
    }
}
