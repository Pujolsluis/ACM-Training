#include <iostream>

using namespace std;

int main()
{
    string s, s1;
    cin >> s >> s1;
    for(int i=0; i<s1.length()-1; i++){
        if(s1[i] > s1[i+1] && s1[i+1] != '0' || (s1[i] == '0' && i == 0)){
            cout << "WRONG_ANSWER" << endl;
            cout << i << endl;
            return 0;
        }
    }
    if(s1 < s)
        cout << "OK" << endl;
    else
        cout << "WRONG_ANSWER" << endl;
    return 0;
}
