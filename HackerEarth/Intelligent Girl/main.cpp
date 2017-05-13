#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string s;
const int MAX = 100004;
int memo[MAX];
int go(int n){
    if( n >= s.length()) return 0;

    if(memo[n] > -1) return memo[n];

    int sol = 0;
    if(s[n] % 2 == 0)  sol += 1 + go(n+1);
    else sol = go(n+1);

    memo[n] = sol;
    return sol;

}

int main()
{
    freopen("C:\\Users\\1057385\\Desktop\\test7.txt", "r", stdin);
    memset(memo, -1, sizeof(memo));
    cin >> s;
    go(0);
    for(int i=0; i<s.length(); i++){
        cout << memo[i] << " ";
    }
    cout << endl;
    cout << "Length: " <<  s.length() << endl;
    return 0;
}
