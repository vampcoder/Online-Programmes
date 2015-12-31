#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
#define ll long long int

using namespace std;

int read_int()
{
    register char c=gc();
    while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
    int ret=0;
    while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
    {
        ret=ret*10+(c-48);//construct the number
        c=gc();
    }
    return ret;
}


int construct_full(int ss, int se, int *v, int* segment_tree,int si) {
	if(ss == se){
		segment_tree[si] = v[ss];
		return segment_tree[si];
	}
	int mid = ss+(se-ss)/2;
	segment_tree[si] = construct_full(ss, mid, v, segment_tree, 2*si+1) + construct_full(mid+1, se, v, segment_tree, 2*si+2);
	return segment_tree[si];
}
int* construct(int n, int *v){
	int *segment_tree;
        int x = ceil(log2(n));
        int p = 2*((int)pow(2,x)-1);
	segment_tree = new int[p];
	int l = construct_full(0, n-1, v, segment_tree, 0); 
//	for(int i = 0; i < p; i++) {
//		cout << segment_tree[i] << " ";
//	}	
//	cout << endl;

	return segment_tree;
}
int Util_query(int *segment_tree,int ss, int se, int qs, int qe, int index) {
	if(qs <= ss &&qe >= se)
		return segment_tree[index];
	if(se < qs || ss > qe)
		return 0;
	int mid = ss+(se-ss)/2;
	return Util_query(segment_tree, ss, mid, qs, qe, 2*index+1) + Util_query(segment_tree, mid+1, se, qs, qe, 2*index+2);
}
int query(int * segment_tree, int n, int qs, int qe) {
	if(qs < 0 || qe > n-1 || qs > qe)
		return -1;
	return Util_query(segment_tree,0,  n-1, qs, qe, 0);
}
void UpdateUtil(int * segment_tree, int ss, int se, int i, int diff, int index){
	if(i < ss || i > se)
		return;
	segment_tree[index] += diff;
       	if(se != ss) {
		int mid = ss + (se-ss)/2;
		UpdateUtil(segment_tree, ss, mid, i, diff, 2*index+1);
		UpdateUtil(segment_tree, mid+1, se, i, diff, 2*index+2);	
	}
}
void Update(int * v, int *segment_tree, int n, int l, int r, int new_val) {

	if(l < 0 || r > n) {
		return;
	}
	for(int i = l; i <= r; i++){
		v[i] = v[i]+ new_val;
		UpdateUtil(segment_tree, 0, n-1, i, new_val, 0);
	}
}
int main()
{
	int t;
	t = read_int();
	while(t--){
		int n = read_int();
		int u = read_int();
		int v[n];
		for(int i = 0; i < n; i++)
			v[i] = 0;
		int *segment_tree = construct(n, v);
		int l, r, k;
		while(u--){
			l = read_int();
			r = read_int();
			k = read_int();
			Update(v, segment_tree, n, l+1, r+1, k);
		}
		int m = read_int();
		while(m--){
			int mf = read_int();
			printf("%d\n", query(segment_tree, n, mf, mf));
		}
	}
}
