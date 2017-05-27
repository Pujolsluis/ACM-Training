#include <iostream>

using namespace std;



int go(int n){
    if(n < 1) return 0;
    int sol = 0;
    if(n == '2' && n == '3' && n == '5' && n == '7'){
        sol = 1 + go(n-1);
    }
    return sol;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int temp;
        cin >> temp;
        cout << go(temp) << endl;

    }
    return 0;
}
