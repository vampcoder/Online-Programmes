#include<iostream>
#include<cstdio>

using namespace std;
int n, a[100005], seg[400];

void construct(int seg_start, int seg_end, int index){
	if(seg_start == seg_end){
		seg[index] = a[seg_start];
		return;
	}
	int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*index+1);
	construct(mid+1, seg_end, 2*index + 2);
	seg[index] = seg[2*index+1] + seg[2*index+2];
	return;
}
int query(int seg_start, int seg_end, int index, int q_start, int q_end){
	if(q_start > seg_end || q_end < seg_start)
		return 0;
	if(q_start <= seg_start && q_end >= seg_end){
		return seg[index];
	}	
	int mid = (seg_start + seg_end)/2;
	return query(seg_start, mid, 2*index+1, q_start, q_end) + query(mid+1, seg_end, 2*index+2, q_start, q_end);
} 
void update(int seg_start, int seg_end, int index, int u_index, int val){
	if(u_index < seg_start || u_index > seg_end)
		return;
	if(seg_start == seg_end){
		seg[index] += val;
		return;
	}
	int mid = (seg_start +seg_end)/2;
	seg[index] += val;
	update(seg_start, mid, 2*index+1, u_index, val);
	update(mid+1, seg_end, 2*index+2, u_index, val);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	construct(0, n-1, 0);
	cout << query(0, n-1, 0, 3 , 6) << "\n";
}
