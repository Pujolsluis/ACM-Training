#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> cities;
    for(int i=0; i<n; i++){
        long long temp;
        cin >> temp;
        cities.push_back(temp);
    }
    sort(cities.begin(), cities.end());
    long long minimunDist = 10000000007;
    for(int i=0; i<n-1; i++){
        minimunDist = min(abs(cities[i] - cities[i+1]), minimunDist);
    }
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        if(abs(cities[i] - cities[i+1]) == minimunDist)
            cnt++;
    }
    cout << minimunDist << " " << cnt;
    return 0;
}
