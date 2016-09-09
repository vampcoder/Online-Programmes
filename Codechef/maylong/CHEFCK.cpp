#include<iostream>
#include<cmath>
#include<deque>
#include<algorithm>

using namespace std;

long long int A[10000007];
long long int prepro[10000007];

void sliding_window(long long int n, long long int k)
{
    std::deque<long long int>  Qi(k);
    long long int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Qi.empty()) && A[i] <= A[Qi.back()])
            Qi.pop_back();  
        Qi.push_back(i);
    }
    long long int j = 0;
    for ( ; i < n; ++i)
    {
        prepro[j++] = A[Qi.front()];
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front(); 
        while ( (!Qi.empty()) && A[i] <= A[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    prepro[j++] = A[Qi.front()];
}
int main()
{
	long long int N, K, Q, a, b, c, d, e, f, r, s, t, m;
	long long int L1, La, Lc, Lm, D1, Da, Dc, Dm, L, R;
	cin >> N >> K >> Q;
	cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> A[0];
	cin >> L1 >> La >> Lc >> Lm;
	cin >> D1 >> Da >> Dc >> Dm;
	long long int temp = t;
	for(long long int i = 1; i < N; i++){
		t = (t*temp)%s;
		if(t <= r){
			A[i] = (a*((A[i-1]*A[i-1])%m) + (b*A[i-1])%m + c)%m;
		}else{
			A[i] = (d*((A[i-1]*A[i-1])%m) + (e*A[i-1])%m + f)%m;
		}
	}
/*	for(int i = 0; i < N; i++){
		cout <<  A[i] << " ";
	}
	cout << endl;
*/	sliding_window(N, K);
/*	for(int i = 0; i <= N-K+1; i++){
		cout << prepro[i] << " ";
	}
	cout << endl; 
*/	
	long long int sum = 0;
	long long int mul = 1;
	for(int i = 0; i < Q; i++){
		L1 = ((La*L1)%Lm + Lc)%Lm;
		D1 = ((Da*D1)%Dm + Dc)%Dm;
		L = L1;
		R = min(L + K + D1, N);
		R--;
//		cout << L << " " << R << endl;
		long long int x = min(prepro[L], prepro[R-K+1]);
		sum += x ;
		mul = (mul*x)%1000000007;
	}
	cout << sum << " " << mul << endl;
}

