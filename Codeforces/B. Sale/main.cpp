#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> TvOnSale;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        TvOnSale.push_back(temp);
    }
    sort(TvOnSale.begin(), TvOnSale.end());
    int sol = 0;
    for(int i=0; i<M; i++){
        if(TvOnSale[i] < 0) sol += abs(TvOnSale[i]);
    }
    cout << sol << endl;
    return 0;
}
