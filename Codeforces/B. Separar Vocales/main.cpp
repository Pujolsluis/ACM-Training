#include <iostream>

using namespace std;

bool esVocal(char v){
    if(v == 'A' || v == 'a' || v == 'E' || v == 'e' || v == 'I' || v == 'i'
    || v == 'O' || v == 'o' || v == 'U' || v == 'u') return true;

    return false;
}

bool esMinuscula(char v){
    if(v >= 97 && v <= 122) return true;
    return false;

}

int main()
{
    string s;
    cin >> s;
    string sol = "";
    for(int i=0; i<s.length()-1; i++){
        sol = sol + s[i];
        if(esVocal(s[i]) && esVocal(s[i+1])){
            if((esMinuscula(s[i]) && esMinuscula(s[i+1])) || (!esMinuscula(s[i]) && esMinuscula(s[i+1])) ){
                sol = sol + "h";
            }else if(!esMinuscula(s[i] && !esMinuscula(s[i+1])) || (esMinuscula(s[i]) && !esMinuscula(s[i+1]))){
                sol = sol + "H";
            }
        }
    }
    sol = sol + s[s.length()-1];
    cout << sol << endl;
    return 0;
}
