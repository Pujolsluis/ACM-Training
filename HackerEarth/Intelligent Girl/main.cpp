#include <iostream>
#include <string.h>
using namespace std;

string s;
const int MAX = 10000004;
int memo[MAX];
int go(int n){
    if( n == s.length()) return 0;

    if(memo[n] > -1) return memo[n];

    int sol = 0;
    if(s[n] % 2 == 0)  sol += 1 + go(n+1);
    else sol = go(n+1);

    memo[n] = sol;
    return sol;

}

int main()
{
    memset(memo, -1, MAX);
    cin >> s;
    cout << s.length() << endl;
    for(int i=0; i<s.length(); i++){
        cout << go(i) << " ";
    }
    cout << endl;
    return 0;
}
