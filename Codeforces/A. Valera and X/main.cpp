#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<char> > A(N, vector<char>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char temp;
            cin >> temp;
            A[i][j] = temp;
        }
    }

    return 0;
}
