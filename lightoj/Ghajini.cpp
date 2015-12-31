#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;
struct node{
	int x;
	int y;
};
int n, a[100007];
struct node seg[400007];

void construct(int seg_start, int seg_end, int index){
	if(seg_start == seg_end){
		seg[index].x = a[seg_start];
		seg[index].y = a[seg_start];
		return;
	}
	int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*index+1);
	construct(mid+1, seg_end, 2*index + 2);
	seg[index].x = min(seg[2*index+1].x , seg[2*index+2].x);
	seg[index].y = max(seg[2*index+1].y , seg[2*index+2].y);
	return;
}
struct node query(int seg_start, int seg_end, int index, int q_start, int q_end){
	if(q_start > seg_end || q_end < seg_start){
		struct node f;
		f.x = INT_MAX;
		f.y = INT_MIN;
		return f;
	}
	if(q_start <= seg_start && q_end >= seg_end){
		return seg[index];
	}	
	int mid = (seg_start + seg_end)/2;
	struct node f;
	struct node left =  query(seg_start, mid, 2*index+1, q_start, q_end);
	struct node right =  query(mid+1, seg_end, 2*index+2, q_start, q_end);
	f.x = min(left.x, right.x);
	f.y = max(left.y, right.y);
	return f;
} 
int query_f(int d){
	if(d == 1)
		return 0;
	int i = 0, j = d-1;
	struct node f;
	int m = 0;
	while(j < n){
		f = query(0, n-1, 0, i, j);
		m = max(m, abs(f.x-f.y));
		i++;
		j++;
	}
	return m;
}
int main()
{	
	int t,d;
	scanf("%d", &t);
	for(int j = 0; j < t; j++){
		scanf("%d%d", &n, &d);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		construct(0, n-1, 0);
		printf("Case %d: %d\n", j+1, query_f(d));
	}
}
