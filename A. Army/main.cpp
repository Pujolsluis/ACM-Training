#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> rankYears;
    for(int i=0; i<N-1; i++){
        int temp;
        cin >> temp;
        rankYears.push_back(temp);
    }
    int A,B;
    cin >> A >> B;
    A--;
    B--;
    int sol = 0;
    for(int i=A; i<B; i++){
        sol += rankYears[i];
    }
    cout << sol << endl;
    return 0;
}
