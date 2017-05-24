#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int best = 0;
    string bestPlayer;
    map<string,int> gameScore;
    vector<vector <string> > winners(1e6+7);
    for(int i=0; i<N; i++){
        int tempScore;
        string tempPlayer;
        cin >> tempPlayer >> tempScore;
        gameScore[tempPlayer]+= tempScore;
        if(gameScore[tempPlayer] > best){
            best = gameScore[tempPlayer];
            bestPlayer = tempPlayer;
            winners[gameScore].push
        }
    }
    cout << bestPlayer << endl;
    return 0;
}
