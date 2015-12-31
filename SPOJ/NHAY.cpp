#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

void Compute_prefix(string & p, int lps[]){
	int m = p.length()+1;
	lps[1] = 0;
	int k = 0;
	for(int q= 2; q < m; q++){
		while(k>0 && p[k] != p[q-1])
			k = lps[k];
		if(p[k] == p[q-1])
			k++;
		lps[q] = k;
	}
}
void KMP_Matcher(string & t, string & p ){
	int m = p.length()+1;
	int n = t.length()+1;
	int lps[m];
	//cout << "1" << endl;
	Compute_prefix(p, lps);
	/*for(int i = 1; i < m; i++)
		cout<<lps[i] << " ";
	cout << endl;
	*/
	//cout << "2" << endl;
	int q = 0;
	int l = 0;
	for(int i = 1; i < n; i++){
		while(q > 0 && p[q] != t[i-1])
			q = lps[q];
		if(p[q] == t[i-1])
			q++;
		if(q == m-1){
            l = 1;
			printf("%d\n", i - m+1);
			q = lps[q];
		}
	}
	if(l == 0){
        printf("\n");
	}
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        string s, t;
        cin >> s >> t;
        KMP_Matcher(t, s);
    }
}
