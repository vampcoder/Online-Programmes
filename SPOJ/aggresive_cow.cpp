#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, c, a[100005];;
bool f(int x){
	int lastpos = a[0], cnt = 1;
	for(int i = 0; i < n; i++){
		if((a[i] - lastpos) >= x){
			if((++cnt) == c)
				return true ;
			lastpos = a[i];
		}
	}
	return false;
}
void print(){
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &c);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
//		print();
		int start = 0, end = a[n-1]-a[0] +1, mid;
		while(end - start > 0){
			mid = (end+start)/2;
			if(f(mid)){
				start = mid+1;
			}else{
				end = mid;
			}
		}
		printf("%d\n",start-1); 	
	}	
}
