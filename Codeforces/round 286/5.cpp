#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;


int main(){
  int t, i, int x;
  map<int> map1;
  set<int> set1;
  int odd = 0, even = 0;
  scanf("%d", &t);
  i = t;
  while(t--){
    scanf("%d", &x);
    if(set1.find(x) == set1.end()){
        set1.insert(x);
        map1[x]++;
    }
  }
  tr(set1){
    if(map1[*it]%2){
        odd++;
    }
  }
  if((odd%2 && (i%2 ==0))||((odd%2 == 0) &&(odd%2))){
    printf("0");
  }else{

  }
}
