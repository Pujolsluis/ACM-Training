#include <cstdio>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;


int main()
{
    int R,C;
//    cin >> R >> C;
    scanf("%d %d", &R, &C);
    printf("r: %d c: %d\n", R,C);
    VVC grid(R);
    int cntOfStars = 0;
    for(int i = 0; i < R; i++){
        for(int j=0; j < C; j++){
            char temp;
            //cin >> temp;
            scanf("%c", &temp);
            if(temp == '*') cntOfStars++;
            grid[i].push_back(temp);
        }
    }

/*    for(vector<char> vec : grid){
        for(char v : vec){
            printf("%c", v);
        }
        printf("\n");
    }*/

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("hey");
            printf("%c", grid[i][j]);
        }
    }
    int bestTop = 0;
    int bestLeft = 0;
    bool foundBestTop = false;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(grid[i][j] == '*'){
                bestTop = i+1;
                bestLeft = j+1;
                foundBestTop = true;
                break;
            }
        }
        if(foundBestTop) break;
    }

    int bestBot = 0;
    int bestRight = 0;
    bool foundBestBot = false;
    for(int i = R-1; i >= 0; i--){
        for(int j = C-1; j >= 0; j--){
            if(grid[i][j] == '*'){
                bestBot = i+1;
                bestRight = j+1;
                foundBestBot = true;
                break;
            }
        }
        if(foundBestBot) break;
    }
//    cerr << bestTop << " " << bestLeft << endl;
    int height = (bestBot - bestTop)+1;
    //cerr << "height: " << (bestBot - bestTop)+1 << endl;
    //cerr << bestBot << " " << bestRight << endl;
    int width = (bestRight - bestLeft)+1;
    //cerr << "width: " << (bestRight - bestLeft)+1 << endl;
    if(width != height){
        printf("NO\n");
       // cout << "NO" << endl;
        return 0;
    }
    if(height*width == cntOfStars) printf("YES\n");
    else printf("NO\n");

    return 0;
}
