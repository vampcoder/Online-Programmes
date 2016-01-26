#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

vector<int> prime;
vector<vector<int > > pfact;
int t, s, d;

class cmpc{
public:
    bool operator() (pi a, pi b){
        return a.second > b.second;
    }
};
void seive(void){
    bool b[1010];
    memset(b, 0, sizeof(b));
    b[1] = true;
    b[0] = true;
    for(int i = 2; i < 1010; i++){
        if(b[i] == true)
            continue;
        for(int j = i+i; j < 1010; j += i){
            b[j] = true;
        }
    }
    for(int i = 0; i < 1010; i++){
        if(b[i])
            continue;
        prime.push_back(i);
    }
}

void prime_factors(void){
    vector<int> temp;
    for(int i = 0; i < 1010; i++){
        pfact.push_back(temp);
    }
    for(int i = 4; i < 1010; i++){
            for(int j = 0; prime[j] < i; j++){
                if(i%prime[j] == 0)
                    pfact[i].push_back(prime[j]);
            }
    }
}

int bfs(){
    priority_queue<pi, vector<pi >, cmpc> pq;

    pi temp = make_pair(s, 0);

    pq.push(temp);
    int cost[1010];
    for(int i = 0; i < 1010; i++){
        cost[i] = INT_MAX;
    }
    cost[s] = 0;
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        int so = temp.first;
        int c = temp.second;
        if(cost[so] < temp.second)
            continue;


        for(int i = pfact[so].size()-1; i >= 0; i--){
            int num = so + pfact[so][i];
            if(num <= d){
                if(cost[num] > c + 1){
                    cost[num] = c+1;
                    pq.push(make_pair(num, c+1));
                }
            }
        }
    }
    if(cost[d] != INT_MAX)
        return cost[d];
    return -1;
}

int main()
{
    seive();
    prime_factors();
  /*  for(int i = 0; i < 10; i++){
        cout << prime[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < pfact[i].size(); j++){
            cout << pfact[i][j] << " ";
        }
        cout << endl;
    } */
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> s >> d;
        cout << "Case " << i << ": " << bfs() << endl;
    }
}
