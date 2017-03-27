#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cities;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        cities.push_back(temp);
    }
    sort(cities.begin(), cities.end());
    int minimunDist = 1e9;
    for(int i=0; i<n-1; i++){
        minimunDist = min(abs(cities[i+1] - cities[i]), minimunDist);
    }
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        if(abs(cities[i+1] - cities[i] == minimunDist))
            cnt++;
    }
    cout << minimunDist << " " << cnt;
    return 0;
}
