#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long pos = 1;
    long long ans = 0;
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        if(temp < pos){
            ans += (n-pos) + temp;
            pos = temp;
        }else{
            ans += temp - pos;
            pos = temp;
        }
    }
    cout << ans << endl;
    return 0;
}
