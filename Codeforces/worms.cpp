#include<iostream>

using namespace std;

int binary_search(int sum[],int arr[], int x, int len){
	int low = 0;
	int high = len-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(x <= sum[mid] && (x > (sum[mid]-arr[mid])))
			return mid+1;
		if(sum[mid] <= x)
			low = mid+1;
		else
			high = mid-1;
	}	
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	int q;
	int sum[n];
	sum[0] = a[0];
	for(int i = 1; i < n; i++)
		sum[i] = sum[i-1]+a[i];
	for(int i = 0; i < m; i++){
		cin >> q;
		cout << binary_search(sum, a, q, n) << endl;	
	}	
}
