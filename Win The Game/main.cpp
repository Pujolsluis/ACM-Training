#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1007;
double memo[MAX][MAX];

double go(int R, int G){

    if(G <= 0) return 1.00;
    if(memo[R][G] != 0) return memo[R][G];
    double sol = ((R/R+G) + (G/R+G) * (G/R+G-1) * (1 - go(R, G-2)));
    memo[R][G] = sol;
    return sol;
}


int main()
{
    memset(memo, 0, MAX-1);
    cout << memo[1000][1000] << endl;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int R,G;
        cin >> R >> G;
        cout << go(R,G) << endl;
        //cout << (R/R+G) + (G/R+G) * (G/R+G-1) *  << endl;
    }
    return 0;
}
