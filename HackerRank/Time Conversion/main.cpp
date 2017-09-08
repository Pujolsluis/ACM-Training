#include <bits/stdc++.h>

using namespace std;

int times[14] = {13,14,15,16,17,18,19,20,21,22,23,24};

string timeConversion(string s) {
    string sol = "";
    int temp;
    temp = 10*(s[0]-'0');
    temp += s[1]-'0';
    if(s[s.length()-2] == 'P' && temp != 12){
        temp--;
        temp = times[temp];
        stringstream ss;
        ss << temp;
        sol += ss.str();
        for(int i=2; i<s.length()-2; i++){
            sol += s[i];
        }
    }else{
       if(s[s.length()-2] == 'A' && (s[0] == '1' && s[1] == '2')){
          sol += "00";
          for(int i=2; i<s.length()-2; i++){
            sol += s[i];
       }
       }else{
           for(int i=0; i<s.length()-2; i++){
                sol += s[i];
           }
       }
    }
    return sol;
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}
