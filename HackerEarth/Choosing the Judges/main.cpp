#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long memo[10004][2];
vector<int> judges;
long long go(int n, int adjacent){
    if(n >= judges.size()) return 0;

    if(memo[n][adjacent] > -1) return memo[n][adjacent];
    long long sol1 = 0, sol2 = 0;
    if(!adjacent){
        sol1 += judges[n] + go(n+1, true);
    }
    sol2 += go(n+1, false);

    memo[n][adjacent] = max(sol1,sol2);
    return max(sol1,sol2);

}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        judges.clear();
        memset(memo, -1, sizeof(memo));
        int N;
        cin >> N;
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            judges.push_back(temp);
        }
        cout << "Case " << i+1 << ": "<< go(0,0) << endl;
    }
    return 0;
}
