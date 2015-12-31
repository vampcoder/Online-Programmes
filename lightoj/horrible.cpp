#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int n, a[100005], seg[400005], lazy[400005];

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
	int mid = (seg_start + seg_end)/2;
	if(lazy[index] != 0){
		seg[index] += lazy[index];
		if(seg_start != seg_end){
			lazy[2*index+1] = (lazy[index]/(seg_end-seg_start+1))*(mid-seg_start+1);
			lazy[2*index+2] = (lazy[index]/(seg_end-seg_start+1))*(seg_end-mid);
		}
		lazy[index] = 0;
	}
	if(q_start > seg_end || q_end < seg_start)
		return 0;
	if(q_start <= seg_start && q_end >= seg_end){
		return seg[index];
	}	
	return query(seg_start, mid, 2*index+1, q_start, q_end) + query(mid+1, seg_end, 2*index+2, q_start, q_end);
} 
void update(int seg_start, int seg_end, int index, int u_sindex, int u_eindex, int val){
	int mid = (seg_start +seg_end)/2;
	if(lazy[index] != 0){
		seg[index] += lazy[index];
		if(seg_start != seg_end){
			lazy[2*index+1] = (lazy[index]/(seg_end-seg_start+1))*(mid-seg_start+1);
			lazy[2*index+2] = (lazy[index]/(seg_end-seg_start+1))*(seg_end-mid);
		}
		lazy[index] = 0;
	}
	if(u_eindex < seg_start || u_sindex > seg_end)
		return;
	if(seg_start >= u_sindex && seg_end <= u_eindex){
		seg[index] += val*(seg_end-seg_start+1);
		if(seg_start != seg_end){
			lazy[2*index+1] += val*(mid-seg_start+1);
			lazy[2*index+2] += val*(seg_end-mid);
		}
		return;
	}
	seg[index] += val*(u_eindex - u_sindex +1);
	update(seg_start, mid, 2*index+1, u_sindex, u_eindex, val);
	update(mid+1, seg_end, 2*index+2, u_sindex, u_eindex, val);
}
void print(int arr[]){
	for(int i = 0; i < 4*n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
void p(){
	for(int i = 0; i < 4*n; i++)
		cout << i << " ";
	cout << endl;
}
int main()
{	
	int t, q, r, x, y, v;
	scanf("%d", &t);
	for(int j = 0; j < t; j++){
		scanf("%d%d", &n, &q);
		for(int i = 0; i < 4*n; i++){
			lazy[i] = 0;
			seg[i] = 0;
		}
//		memset(seg, 0, sizeof(seg));
//		memset(lazy, 0, sizeof(lazy));
		printf("Case %d:\n", j+1);
//		p();
		while(q--){
			scanf("%d%d%d", &r, &x, &y);
			if(r == 0){
				scanf("%d", &v);
				update(0, n-1, 0, x, y, v);
				print(seg);
				print(lazy);
			}else{
				printf("%d\n", query(0, n-1, 0, x, y));
				print(seg);
				print(lazy);
			}
		}
	}
}
