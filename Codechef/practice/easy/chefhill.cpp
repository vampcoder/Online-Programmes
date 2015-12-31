#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

int read_int()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore all characters till the first digit
int ret=0;
while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}
     int *A,size;
          int x = (int)(ceil(log2(N)))+1;
          size = 2*(int)pow(2,x);
        A = new int[size];
     void initialize(int node, int start,
                         int end, T *array)
     {

          if (start==end)
             A[node] = array[start];
          else
          {
              int mid = (start+end)/2;
              initialize(2*node+1,start,mid,array);
              initialize(2*node+2,mid+1,end,array);
              A[node] = max(A[2*node+1], A[2*node+2]);
              /*if (array[A[2*node]]<=
                     array[A[2*node+1]])
                 A[node] = A[2 * node];
              else
                  A[node] = A[2 * node + 1];
          */}
     }
     int query(int node, int start,int end, int i, int j, int *array)
     {
         int id1,id2;
         if (i>end || j<start)
            return -1;

         if (start>=i && end<=j)
            return A[node];

         int mid = (start+end)/2;
         id1 = query(2*node+1,start,mid,i,j,array);
         id2 = query(2*node+2,mid+1,end,i,j,array);

         //if (id1==-1)
           // return id2;
         //if (id2==-1)
           // return id1;

         return(max(id1,id2));
     }
};
int main()
{
    int i,j,N;
    int A[100007];
    scanf("%d",&N);
    for (i=0;i<N;i++)
        scanf("%d",&A[i]);

    SegmentTree<int> s(N);
    s.initialize(0,0,N-1,A);
    for(int k = 0; k < s.size; k++){
        cout << s.A[k] << " ";
    }
    cout << endl;
    int k = read_int();
    while (k--){
        scanf("%d%d",&i,&j);
        int x = A[s.query(0,0,N-1,i,j-2,A)];
        cout << x<< endl;
        if(x <= A[i]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
