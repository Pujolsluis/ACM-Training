#include <iostream>
#include <map>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    for(int i=2; i<=n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        map<char,int> primeLetters;
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            primeLetters[s[j]]++;
        }
        map<char,int>::iterator it = primeLetters.begin();
        bool success = true;
        for(it; it != primeLetters.end(); it++){
            if(!isPrime(it->second)){
                success = false;
                break;
            }
        }
        if(success && isPrime(primeLetters.size())) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
