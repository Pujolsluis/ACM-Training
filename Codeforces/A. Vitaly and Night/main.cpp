#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<= m; j++){
            int temp;
            int temp2;
            cin >> temp >> temp2;
            if(temp || temp2) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
