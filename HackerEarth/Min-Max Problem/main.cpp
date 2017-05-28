#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> numbers;
    bool validatenumbers[104];
    memset(validatenumbers, 0, sizeof(validatenumbers));
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
        validatenumbers[temp] = true;
    }
    sort(numbers.begin(), numbers.end());
    int minnumb = numbers[0], maxnumb = numbers[numbers.size()-1];
    for(int i=minnumb; i<maxnumb; i++){
        if(!validatenumbers[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
