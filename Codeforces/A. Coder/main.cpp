#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VCC;

int main()
{
    int n;
    cin >> n;
    VCC chessBoard = VCC(n, VC(n, '.'));
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int q=1; q<=n; q++){
            if(i % 2 != 0 && q % 2 != 0){
                chessBoard[i-1][q-1] = 'C';
                cnt++;
            }
            else if(i % 2 == 0 && q % 2 == 0){
                chessBoard[i-1][q-1] = 'C';
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for(int i=0; i<chessBoard.size(); i++){
        for(int q=0; q<chessBoard[i].size(); q++){
        cout << chessBoard[i][q] << " ";
        }
        cout << endl;
    }
}
