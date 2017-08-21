#include <iostream>
#include <vector>
using namespace std;

int MAX = 200007;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> temperatures(MAX,0);
    for(int i=0; i<n; i++){
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;
        for(int j=temp1; j<=temp2; j++){
            temperatures[j]++;
        }
    }
    for(int j=0; j<q; j++){
        int result = 0;
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;
        for(int i=temp1; i<=temp2; i++){
            if(temperatures[i] >= k) result++;
        }
        cout << result << endl;
    }
    return 0;
}
