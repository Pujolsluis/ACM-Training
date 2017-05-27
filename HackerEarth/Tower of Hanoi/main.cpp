#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAX = 207, INF=-1;
long long memo[MAX][MAX];
int N;
vector<pair<int,int> > disks;
long long go(int n, int last_index){
    if(n < 0) return 0;
    long long res=0;
    if(memo[n][last_index] != INF) return memo[n][last_index];
    if(disks[n].first < disks[last_index].first && disks[n].second < disks[last_index].second){
        res = max(res, go(n-1, n) + disks[n].second);
    }
    res = max(res, go(n-1, last_index));

    memo[n][last_index] = 1LL*res;
    return res;
}

int main()
{
    int T;
    cin >> T;
    for(int z=0; z<T; z++){
        memset(memo, INF, sizeof(memo));
        int quantity;
        cin >> quantity;
        for(int i=0; i<quantity; i++){
            int tempW, tempH;
            cin >> tempW >> tempH;
            disks.push_back(make_pair(tempW, tempH));
        }
        N = disks.size()-1;
        disks.push_back(make_pair(1e9+7,1e9+7));
        sort(disks.begin(), disks.end());
        cout << go(N, N+1) << endl;
        disks.clear();
    }

    return 0;
}
