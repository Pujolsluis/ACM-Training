#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int INF = 1000007;
//int memo[INF];

int diaMax;

int go(int dia, bool fui_ayer){

    if(dia == diaMax)
        return 1;

    int res1, res2, sol;
    res1 = res2 = sol = 0;

    //if(memo[dia] > 0) return memo[dia];

    //no voy
    res1 = go(dia + 1, false);

    if(!fui_ayer){
        //voy
        res2 = go(dia + 1, true);
    }

    sol = res1 + res2;

    //memo[dia] = sol;
    return sol;

}

int main()
{
    //memset(memo, INF, INF);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int temp;
        cin >> temp;
        diaMax = temp;
        cout << go(0,0) << endl;
    }
    return 0;
}
