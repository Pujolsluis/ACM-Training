#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

double INF = 1007.00;
double memo[1007][1007];

double go(int R, int G){
    cout << "G: " << G << endl;
    cout << "memo: " << memo[R][G] << endl;
    if(G == 0) return 1;
    if(memo[R][G] != 0) return memo[R][G];
    double sol = 0.00;
    sol = (R/R+G) + (G/R+G) * (G-1/R+G-1) * go(R, G-2);
    cout << "HEY" << endl;
    cout << sol << endl;
    memo[R][G] = sol;
    return sol;

}

int main()
{
    memset(memo, INF, INF-1);
   // int N;
  //  cin >> N;
    int RB,GB;
    cin >> RB >> GB;
    cout << go(RB,GB) << endl;
    return 0;
}
