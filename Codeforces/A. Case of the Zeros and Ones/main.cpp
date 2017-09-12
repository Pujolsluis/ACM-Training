#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeros=0,ones=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0') zeros++;
        else ones++;
    }
    if(zeros>ones){
        cout << zeros-ones << endl;
    }else{
        cout << ones-zeros << endl;
    }
    return 0;
}
