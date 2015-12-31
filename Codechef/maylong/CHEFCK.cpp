#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)

#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
#define MAX 10000002
#define MOD 1000000007
using namespace std;
inline int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
inline ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}

ll A[MAX];
int ST[24][10000002];
int powers2[24];

inline int power2(int a, int b) {
    if (b == 0) return 1;
    ll temp = power2(a,b/2);
    if (b%2 == 1) {
        return (a*temp*temp);
    }
    else return (temp*temp);
}
inline void precalc2() {
    int x = 1;
    repu(i,0,24,1) {
        powers2[i] = x;
	x *= 2;
    }
}
inline int calcLog  (int n) {
        int ans = 0;
        //ll start =1;
        while (n >= 2) {
                n /= 2;
                ans ++;
        }
return ans;
}
inline void pre_handle(int n) {
    int i;
    //ST[0].resize(n);
    for(i=0;i<n;i++) {
        ST[0][i] = (i);
    }
    int k = calcLog(n),j;
    int temp;
    for(i=1;i<=k;i++) {
        //ST[i].resize(n);
        temp = powers2[i-1];
        for(j = 0; j + temp < n; j++)
            ST[i][j] = (A[ST[i-1][j]] < A[ST[i-1][j+temp]]) ? ST[i-1][j] : ST[i-1][j+temp];
    }
}
inline void writeInt (ll n) {
        ll N = n, rev; int count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
}
int main() {
    //cout<<log2(10000000);
    precalc2();
    int n,q,k;
    n = readi(); k = readi(); q =readi();
    ll  a = readl(), b = readl(), c = readl(), d = readl(), e = readl(), f = readl(), r = readl(), s = readl(), t = readl(), m = readl();
    A[0] = readl();

    {
        ll temp = t;
        ll temp2;
        repu(i,1,n,1) {
            temp = (temp*t);
            if (s < temp) temp %= s;
            if (temp <= r) {
                //A[i] = (((a*A[i-1])%m)*A[i-1])%m + (b*A[i-1]) % m + c;
                A[i] = (a*A[i-1] + b);
                A[i] = (A[i]*A[i-1])%m + c;
            }
            else {
                A[i] = (d*A[i-1] + e);
                A[i] = (A[i]*A[i-1])%m + f;
            }
            if (A[i] >= m)
                A[i] %= m;
        }

    }
    //construct(0,n-1,1);
    pre_handle(n);
    ll L1 = readi(),La = readi(),Lc = readi(),Lm = readi(),D1 = readi(),Da = readi(),Dc = readi(),Dm = readi();

    ll sum = 0;
    ll pro = 1;
    ll temp = 0;
    int L,R,p,p2,p3;
    {
        repu(i,0,q,1) {
            L1 = (La*L1) + Lc;
            if (L1 >= Lm)
                L1 %= Lm;
            D1 = (Da*D1) + Dc;
            if (D1 >= Dm)
                D1 %= Dm;
            L = L1+1;
            p3 = L+k-1+D1;
            R = (p3 < n) ? p3 : n;
            p = calcLog(R-L+1);
            p2 = powers2[p];
            temp = (A[ST[p][L-1]] < A[ST[p][R-p2]]) ? A[ST[p][L-1]] : A[ST[p][R-p2]];
            sum += temp;
            pro = pro * temp;
            if (pro >= MOD) pro %= MOD;
        }
    }
    writeInt(sum);
    ps(" ");
    writeInt(pro);
    nl();
    //ST.clear();
return 0;
}

