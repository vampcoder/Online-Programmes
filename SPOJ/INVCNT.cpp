#include<cstdio>
#include<climits>
using namespace std;

int merge_sort(int a[], int n, int p, int mid, int q){
	int l = mid-p+2;
	int r = q-mid+2;
	int l_temp[l];
	int r_temp[r];
	int x = 0;
	for(int i = p; i <= mid; i++){
		l_temp[x++] = a[i];
	}
	l_temp[x] = INT_MAX;
	x = 0;
	for(int i = mid+1; i <= q; i++){
		r_temp[x++] = a[i];
	}
	r_temp[x] = INT_MAX;
	int i = 0;
	int j = 0;
	int c = 0;
	while(p <= q){
		if(l_temp[i] < r_temp[j]){
			a[p++] = l_temp[i++];
		}else{
			a[p++] = r_temp[j++];
			c +=(mid + 1 - i);
		}
	}
	return c;
}

int merge(int a[], int n, int p, int q){
	if(p < q){
		int mid = (p+q)/2;
		int left = merge(a, n, p, mid);
		int right = merge(a, n, mid+1, q);
		return left+right+merge_sort(a, n, p, mid , q);	
	}else{
		return 0;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}			
		printf("%d\n", merge(a, n, 0, n-1));
	}
}
