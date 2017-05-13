#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char,int> chars;
    for(int i=0; i<s.length(); i++){
        chars[s[i]]++;
    }
    map<char,int>::iterator it = chars.begin();
    bool single = false;
    for(it; it != chars.end(); it++){
        if(it->second == 1 && !single){
            single = true;
        }else if(it->second == 1 && single){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(single) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
