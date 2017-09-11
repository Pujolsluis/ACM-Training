#include <iostream>

using namespace std;

int main()
{
    int n,d;
    cin >> n >> d;
    int winnings = 0;
    int best = 0;
    for(int i=0; i<d; i++){
        string s;
        cin >> s;
        bool win = false;
        for(int j=0; j<s.length(); j++){
            if(s[j] == '0'){
                win = true;
                //cout << "day: " << j+1 << endl;
                break;
            }
        }
        if(win){
            winnings++;
            if(winnings > best) best = winnings;
        }else{
            winnings = 0;
        }
    }
    cout << best << endl;
    return 0;
}
