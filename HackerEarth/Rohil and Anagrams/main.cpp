#include <iostream>
#include <map>
#include <vector>
using namespace std;


map<string,int> anagrams;
map<string,vector<string> > words;

bool checkIfAnagram(string s){
     map<char,int> letters;
     for(int i=0; i<s.length(); i++){
        letters[s[i]]++;
     }
     for(int i=0; i<words[s].size(); i++){
        for(int j=0; j<words[s][i].length(); j++){
            if(letters.count(words[s][i][j])){
                return false;
            }
        }
     }
     return true;
}

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        const int last = s.length()-1;
        string stemp;
        stemp.push_back(s[0]);
        stemp.push_back(s[last]);
        anagrams[stemp]++;
        words[stemp].push_back(s);
        if(!checkIfAnagram(s)){
            anagrams[stemp+' ']++;
        }
    }
    cout << anagrams.size() << endl;
    return 0;
}
