#include <iostream>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    int sol = 0;
    for(int i=0; i<N; i++){
       int temp;
       cin >> temp;
       if(K < temp){
          sol += temp-K;
          K += temp-K;
       }
    }
    cout << sol << endl;
    return 0;
}
