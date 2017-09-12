#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int player1, player2;
    player1 = player2 = 0;
    for(int i=0; i<n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if(temp1 > temp2) player1++;
        else if(temp1 < temp2) player2++;
    }
    if(player1>player2) cout << "Mishka" << endl;
    else if(player1 < player2) cout << "Chris" << endl;
    else cout << "Friendship is magic!^^" << endl;
    return 0;
}
