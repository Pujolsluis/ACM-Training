#include <iostream>

using namespace std;

int main()
{
    string X;
    long long K;
    cin >> X >> K;
    long long index = 0;
    while(K>0){
        if(X[index] != '9'){
            X[index] = '9';
            K--;
        }
        index++;
    }
    cout << X << endl;
    return 0;
}
