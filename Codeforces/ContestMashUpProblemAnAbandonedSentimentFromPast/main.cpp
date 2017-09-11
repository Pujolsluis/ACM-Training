#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a,b;
    vector<int> emptySpaces;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
        if(temp == 0) emptySpaces.push_back(i);
    }
    for(int i=0; i<k; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for(int i=0; i<b.size(); i++){
        a[emptySpaces[i]] = b[i];
    }
    for(int i=0; i<a.size()-1; i++){
        if(a[i] > a[i+1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
