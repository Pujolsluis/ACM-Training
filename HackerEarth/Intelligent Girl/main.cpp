#include <iostream>
#include <string.h>
using namespace std;

string s;
int memo[10004];
int go(int n){
    n--;
    if(memo[n] >= 0) return memo[n];
    int result = 0;
    for(int i=n; i<s.length(); i++){
        if((s[i] - '0') % 2 == 0) result++;
    }

}

int main()
{
    memset(memo, -1, 10004);
    cin >> s;

    return 0;
}
