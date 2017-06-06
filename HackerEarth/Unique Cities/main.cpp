#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        map<char,int> cities;
        for(int j=0; j<N; j++){
            string temp;
            cin >> temp;
            cities[temp[0]]++;
        }
        if(cities.size() == N) cout << "YES" << endl;
        else cout << "NO" << endl;
        cities.clear();
    }
    return 0;
}
