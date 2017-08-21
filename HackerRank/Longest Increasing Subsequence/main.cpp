#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//1 5 0 0 8

const int MAX = 1e6+7;
vector<int> numbers;
long long memo[MAX];
long long go(int n, int took){
    if(n >= numbers.size()) return 0;
    if(memo[n] != -1) return memo[n];
    long long res1 = 0, res2 = 0;
    if(numbers[n] > took){
       res1 = 1 + go(n+1, numbers[n]);
    }
    res2 = go(n+1, numbers[took]);
    return memo[n] = max(res1, res2);
}

int main()
{
    int N;
    cin >> N;
    memset(memo, -1, sizeof(memo));
    numbers.push_back(0);
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    cout << go(1, 0) << endl;
    return 0;
}
