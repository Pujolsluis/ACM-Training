#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = -1;
const int MAX = 1e4+7;
long long memo[MAX];
vector<int> numbers;
int K;

long long go(int i){
    if(i >= numbers.size()) return 0;

    if(memo[i] != INF) return memo[i];

    long long result1=0, result2=0;
    result1 = numbers[i] + go(i+K+1);
    result2 = go(i+1);

    memo[i] = max(result1,result2);
    return max(result1, result2);
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N >> K;
        memset(memo, INF, sizeof(memo));
        for(int i=0; i<N; i++){
            int temp;
            cin >> temp;
            numbers.push_back(temp);
        }
        cout << go(0) << endl;
        numbers.clear();
    }
    return 0;
}
