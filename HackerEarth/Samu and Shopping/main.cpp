#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VII;

int N;
long long MAX = 1e9+7;
VII shops;
long long memo[100007][3];

long long go( int i, int lasti){
if(i >= N) return 0;

if(memo[i][lasti] > 0) return memo[i][lasti];

long long sol1 = MAX, sol2 = MAX, sol3 = MAX;
if(lasti != 0){
   sol1 = shops[i][0] + go(i+1, 0);
}if(lasti != 1){
   sol2 = shops[i][1] + go(i+1, 1);
}if(lasti != 2){
   sol3 = shops[i][2] + go(i+1, 2);
}
long long sol = min(sol1, sol2);
sol = min(sol,sol3);
memo[i][lasti] = sol;
return sol;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        shops = VII(N);
        for(int k=0; k<N; k++){
            for(int j=0; j<3; j++){
                int temp;
                cin >> temp;
                shops[k].push_back(temp);
            }
        }
        memset(memo, 0, sizeof(memo));
        cout << go(0, 3) << endl;
        shops.clear();
    }
    return 0;
}


/*int best = 10007, besti=0;
for(int j=0; j<3; j++){
    if(shops[i][j] < best && j != lasti){
        best = shops[i][j];
        besti = j;
    }
}
int sol = best + go(i+1, besti);
memo[i][lasti] = sol;
*/
