#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        long long n,k,x,d;
        cin >> n >> k >> x >> d;
        long long sum = 0;
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            sum += max(k, ((x * temp)/100));
        }
        if(sum > d){
            cout << "upfront" << endl;
        }else{
            cout << "fee" << endl;
        }
    }
    return 0;
}
