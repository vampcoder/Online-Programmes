#include<iostream>
#include<cmath>

using namespace std;
int M[100006][20];
int A[100006];
int RMQ(int i, int j){
	int k = log2(j-i+1);
	int k2 = (1 << k);
	if(A[M[i][k]] <= A[M[j-k2+1][k]]){
		return M[i][k];
	}else{
		return M[j-k2+1][k];
	}
}
void compute_sparse(int N){
      int i, j;
      for (i = 0; i < N; i++)
          M[i][0] = i;
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	compute_sparse(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; 1<<j < n; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
	int q, a, b;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		cout << A[RMQ(a, b)] << endl;
	}
}
