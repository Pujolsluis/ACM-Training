#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    vector<int> numbers;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    bool state[1000007];
    memset(state, 0, sizeof(state));
    for(int i=0; i<numbers.size(); i++){
        if(!state[numbers[i]]){
            cout << numbers[i] << " ";
            state[numbers[i]] = true;
        }
    }
    cout << endl;
    return 0;
}
