#include<iostream>
#include<cstdio>

using namespace std;
struct node{
	int val;
	int x;
	int y;
};
int n, a[100005];
struct node seg[400005];

void construct(int seg_start, int seg_end, int index){
	if(seg_start == seg_end){
		seg[index].x = a[seg_start];
		seg[index].y = a[seg_start];
		seg[index].val = 1;
		return;
	}
	int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*index+1);
	construct(mid+1, seg_end, 2*index + 2);
	seg[index].x = seg[2*index+1].x;
	seg[index].y = seg[2*index+2].y;
	seg[index].val = seg[2*index+1].val + seg[2*index+2].val;
	return;
}
int query(int seg_start, int seg_end, int index, int q_start, int q_end){
	if(seg_start < 0 || seg_end >= n)
		return 0;
	if(q_start > seg[index].y || q_end < seg[index].x)
		return 0;
	if(q_start <= seg[index].x && q_end >= seg[index].y){
		return seg[index].val;
	}	
	int mid = (seg_start + seg_end)/2;
	return query(seg_start, mid, 2*index+1, q_start, q_end) + query(mid+1, seg_end, 2*index+2, q_start, q_end);
} 
int main()
{	
	int t, q, l, r;
	scanf("%d", &t);
	for(int j = 1; j <= t; j++){
		scanf("%d%d", &n, &q);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		construct(0, n-1, 0);
		printf("Case %d:\n", j);
		while(q--){
			scanf("%d%d", &l, &r);
			printf("%d\n", query(0, n-1, 0, l, r));
		}
	}
}
