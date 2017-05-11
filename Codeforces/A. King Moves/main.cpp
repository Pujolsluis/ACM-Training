#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char c = s[1];
    char d = s[0];
    if(c == '1' && d == 'a' || c == '1' && d == 'h' || c == '8' && d == 'a' || c == '8' && d == 'h'){
        cout << 3 << endl;
        return 0;
    }else if(d == 'h' || d == 'a' || c == '1' || c == '8'){
        cout << 5 << endl;
        return 0;
    }
    cout << 8 << endl;
    return 0;
}
