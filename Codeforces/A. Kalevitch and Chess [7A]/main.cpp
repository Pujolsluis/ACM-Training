#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC>VCC;

int main()
{
    VCC chessBoard = VCC(8, VC(8,'W'));
    for(int i=0; i<8; i++){
        for(int q=0; q<8; q++){
            char temp;
            cin >> temp;
            chessBoard[i][q] = temp;
        }
    }
    int colsToPaint = 0;
    int rowsToPaint = 0;
    for(int i=0; i<8; i++){
        bool countRow = true;
        for(int j=0; j<8; j++){
            if(chessBoard[i][j] != 'B'){
                countRow = false;
                break;
            }
        }
        if(countRow) rowsToPaint++;
    }
    if(rowsToPaint == 8){
        cout << 8 << endl;
        return 0;
    }
    for(int i=0; i<8; i++){
        bool countCol = true;
        for(int j=0; j<8; j++){
            if(chessBoard[j][i] != 'B') countCol = false;
        }
        if(countCol) colsToPaint++;
    }
    cout << rowsToPaint + colsToPaint << endl;
    return 0;
}
