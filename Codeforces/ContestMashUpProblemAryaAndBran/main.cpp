#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int candiesGiven = 0;
    int candiesLeft = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        candiesLeft += temp;
        if(candiesLeft > 8){
            candiesGiven += 8;
            candiesLeft -= 8;
        }else{
            candiesGiven += candiesLeft;
            candiesLeft = 0;
        }
        if(candiesGiven >= k){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
