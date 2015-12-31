#include<iostream>
#define M 1000000007

using namespace std;

struct node{
	int num;
	int mul;
	int add;
};

struct node segment[400010];

int arr[100005];

void create(int seg_start, int seg_end, int idx){
	if(seg_start <= seg_end){
		if(seg_start == seg_end){
			segment[idx].num = arr[seg_start];
			segment[idx].mul = 1;
			segment[idx].add = 0;
		}
		int mid = (seg_start+seg_end)/2;
		create(seg_start, mid, 2*idx+1);
		create(mid+1, seg_end, 2*idx+2);
		segment[idx].num = segment[2*idx+1].num + segment[2*idx+2].num;
		segment[idx].mul = 1;
		segment[idx].add = 0;
	}
}
void update(int seg_start, int seg_end, int idx, int q_start, int q_end, int type,  int val){
	


}

int query(int seg_start, int seg_end, int idx, int q_start, int q_end){
	if(q_start > seg_end || q_end < seg_start)
			return 0;
	int v = segment[idx].num;
	if(segment[idx].mul ! = 1 && segment[idx].add != 0){
		v *= segment[idx].mul;
		int add = segment[idx].add*segment[idx].mul;
		if(q_start != q_end){
			segment[2*idx+1].mul *= segment[idx].mul;
			segment[2*idx+2].mul *= segment[idx].mul;
		}
		segment[idx].num = v+add;
		segment[idx].mul = 1;
		segment[idx].add = 0;
	}else if(segment[idx].add != 0){
		v += segment[idx].add;
		if(q_start != q_end){
			segment[2*idx+1].add += segment[idx].add;
			segment[2*idx+1].add += segment[idx].add;
		}
		segment[idx].num = v;
		segment[idx].add = 0;
		}
	}else if(){


	}
	if(q_start <= seg_start && q_end >= seg_end){
		return seg[idx].num;
	}
	int mid = (seg_start+seg_end)/2;
	return query(seg_start, mid, 2*idx+1, q_start, q_end)+ query(seg_start, mid, 2*idx+2, q_start, q_end);
}
int main()
{
	int n, q, x;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int q, x, y, v;
	create(0, n-1, 0);
	for(int i = 0; i < n; i++){
		cin >> q >> x >> y;
		if(q == 4){
			cout << query(0, n-1, 0, x-1, y-1);
		}else{
			cin >> v;
			update(0, n-1, 0, x-1, y-1, q, v);
		}
	}
}
