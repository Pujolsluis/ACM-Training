#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> coinstack;
int K;
/*
8 2
3 2 2 3 1 1 1 3
*/

/*int go(int i){

    if(i >= coinstack.size()) return 0;
    int sol1 = 0, sol2 = 0;
    if(coinstack[i] <= K){
        sol1 += coinstack[i] + go(i+1);
    }
    sol2 = go(i+1);
    return max(sol1,sol2);
}*/

long long memo[100005][3];
long long dp(int i, bool pickedLast)
{
    if (i >= coinstack.size()) return 0;
    if(memo[i][pickedLast] != -1) return memo[i][pickedLast];
    long long res1 = -1, res2 = -1;
    // lo cojo
    if (coinstack[i] <= K) {
        res1 = coinstack[i] + dp(i + 1, 1);
    }
    // no lo cojo
    if (pickedLast) {
        res2 = 0;
    } else {
        res2 = dp(i + 1, 0);
    }

    return memo[i][pickedLast] = max(res1, res2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
       int N;
       cin >> N >> K;
       for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            coinstack.push_back(temp);
       }
       //cout << go(0) << endl;
       memset(memo, -1, sizeof(memo));
       cout << dp(0, 0) << endl;
       coinstack.clear();
    }
    return 0;
}
