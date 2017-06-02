#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> candles;
    int N;
    cin >> N;
    int best = 0;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        candles[temp]++;
        if(temp > best) best = temp;
    }
    cout << candles[best] << endl;
    return 0;
}
