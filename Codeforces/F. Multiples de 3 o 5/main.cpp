#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<=n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    if(a == b) cout << n/a << endl;
    else if(isPrime(a) && isPrime(b)){
        cout << ((n/a) + (n/b)) - ((n/a)/b) << endl;
    }else{
        cout << (((n/a) + (n/b)) - ((n/a)/b))-1 << endl;
    }
    return 0;
}
