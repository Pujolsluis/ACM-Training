#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        string s;
        cin >> s;
        int cnt=0;
        for(int j=4; j<s.length()-4; j++){
            if(s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'y') cnt++;
        }
        cout << cnt+4 << "/" << s.length() << endl;
    }
    return 0;
}
