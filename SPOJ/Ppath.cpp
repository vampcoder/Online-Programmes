#include<cmath>
#include <iostream>
#include<queue>
#include<cstring>

using namespace std;

int prime[10004] = {0};
int arr_to_num(int arr[]){
	int temp = 0;
	for(int i = 0; i < 4; i++){
		temp = temp*10 + arr[i]; 
	}
	return temp;
}
void num_to_arr(int arr[], int num){
	for(int i = 3; i >= 0; i--){
		arr[i] = num%10;
		num /= 10;
	}	
}
void seive(){
	prime[1] = 1;
	for(int i = 2; i < 100; i++){
		if(prime[i] == 0){
			for(int j = i*i; j < 10000; j += i){
				if(j%i == 0){
					prime[j] = 1;
				}
			}
		}
	}
}
int main() {
	seive();
//	for(int i = 0; i < 100; i++)
//		if(prime[i] == 0)
//			cout << i << " ";
//	cout << endl;
	int t, a, b;
	cin >> t;
	while(t--){
		int dist[10009];
	//	int parent[10009];
		memset(dist, -1, sizeof(dist));
		
		queue<int> q;
		cin >> a >> b;
		if(a == b){
			cout << "0\n";
		}else{
			dist[a] = 0;
		//	parent[a] = 0;
			q.push(a);
			while(!q.empty()){
				int num = q.front();
				q.pop();
				int arr[4];
				for(int i = 0; i < 4; i++){
					num_to_arr(arr, num);
					for(int j = 0; j <= 9; j++){
						arr[i] = j;
						int number = arr_to_num(arr);
						if(prime[number] == 0 && dist[number] == -1 && number >= 1000){
							dist[number] = dist[num] + 1;
		//					parent[number] = num;
							q.push(number);
						}
					}
				}	
			}
//			for(int i = 1000; i < 10000; i++)
//				if(dist[i] != -1)
//					cout << i << " " << dist[i] << endl;
			cout << dist[b] << endl;				
		}
	}
}
