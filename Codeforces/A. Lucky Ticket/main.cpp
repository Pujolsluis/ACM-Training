#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int mid = N/2;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<S.length(); i++){
        if(S[i] != '4' && S[i] != '7'){
            cout << "NO" << endl;
            return 0;
        }
        if(i<mid){
            cnt1 += S[i] - '0';
        }else{
            cnt2 += S[i] - '0';
        }
    }
    if(cnt1 == cnt2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
