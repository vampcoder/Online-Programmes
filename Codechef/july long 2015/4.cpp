#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<limits.h>
int b[1000007],v[1000007], l[1000005],r[1000005],w[1000005],mini[1000005];
int ans[100005][1005];
int mine(int p,int q){
    return (p>q?p:q);
}
int main()
{
    long long int t;
    scanf ("%lld",&t);
    while(t--)
    {
    	long long int n,k,m,i,j=0,ne=0;
    	int sum=0;
        scanf ("%lld%lld%lld",&n,&k,&m);
        int a[n];
        long long int y=0,p;
        j=0;
        sum=0;
        for (i=0;i<n;i++){
            scanf ("%d",&a[i]);
            sum+=a[i];
            if (a[i]<0){
                b[j]=-a[i];
                v[j]=i;
                j++;
            }
        }
        ne=j;
        for (i=0;i<m;i++)
            mini[i]=INT_MAX;
        j=0;
        for (i=0;i<m;i++){
            scanf ("%d%d%d",&l[i],&r[i],&w[i]);
            for (j=l[i]-1;j<=r[i]-1;j++){
                if (w[i]<mini[j])
                    mini[j]=w[i];
            }
        }
        int wt[ne];
        for (i=0;i<ne;i++){
            wt[i]=mini[v[i]];
        }
        long long int z;
        for (i=0;i<=ne;i++){
            for (z=0;z<=k;z++){
                if (i==0 || z==0)
                    ans[i][z]=0;
                else if (wt[i-1]<=z){
                    ans[i][z]=mine((b[i-1] + ans[i-1][z-wt[i-1]]) ,ans[i-1][z]);
                }else
                    ans[i][z]=ans[i-1][z];
            }
        }
        sum+=(ans[ne][k]);
        printf ("%d\n",abs(sum));
    }
    return 0;
}
