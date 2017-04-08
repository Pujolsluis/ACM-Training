#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> housesQ;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        housesQ.push_back(temp);
    }

    return 0;
}
