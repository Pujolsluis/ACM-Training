#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> properties;
    vector<long long> prefixSum(n);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        properties.push_back(temp);
        if(i==0) prefixSum[i] = temp;
        else prefixSum[i] = prefixSum[i-1] + temp;
    }
    /*for(int i=0; i<prefixSum.size(); i++){
        cout << prefixSum[i] << " ";
    }
    cout << endl;*/
    long long best = prefixSum[prefixSum.size()-1];
    for(int i=0; i<n; i++){
        long long newCalculation = prefixSum[i]*(prefixSum[prefixSum.size()-1]-prefixSum[i]);
        if( newCalculation > best)
            best = newCalculation;
    }
    for(int i=n-1; i>1; i--){
        long long newCalculation = (prefixSum[i]-prefixSum[i-1])*prefixSum[i-1];
        if( newCalculation > best)
            best = newCalculation;
    }
    cout << best << endl;
    return 0;
}
