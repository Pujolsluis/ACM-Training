#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int difletters = 0;
    map<char,int> letters;
    for(int i=0; i<s.length(); i++){
        letters[s[i]]++;
    }
    difletters = letters.size();
    if(difletters >= k){
        cout << 0 << endl;
        return 0;
    }
    map<char,int>::iterator it = letters.begin();
    int newchanges = 0;
    for(it; it != letters.end(); it++){
        int amount = it->second;
        while(amount > 1){
            difletters++;
            newchanges++;
            amount--;
            if(difletters >= k){
                cout << newchanges << endl;
                return 0;
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
