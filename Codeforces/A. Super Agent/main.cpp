#include <iostream>

using namespace std;

int main()
{
    char matrix[4][4];
    for(int i=0; i<3; i++){
        for(int q=0; q<3; q++){
            char temp;
            cin >> temp;
            matrix[i][q] = temp;
        }
    }
    for(int i=0; i<3; i++){
        if(matrix[0][i] == 'X' && matrix[2][2-i] != 'X'){
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i=0; i<3; i++){
        if(matrix[0][i] != 'X' && matrix[2][2-i] == 'X'){
            cout << "NO" << endl;
            return 0;
        }
    }

    if((matrix[1][0] == 'X' && matrix[1][2] != 'X') || (matrix[1][2] == 'X' && matrix[1][0] != 'X')){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
