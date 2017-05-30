#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> numbers;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    int n1=0,n2=1,n3=2;
    long long cnt1=0,cnt2=0,cnt3=0;
    while(n1 < numbers.size()){
        if(n1 < numbers.size()){
            cnt1 += numbers[n1];
            n1+=3;
        }if(n2 < numbers.size()){
            cnt2 += numbers[n2];
            n2+=3;
        }if(n3 < numbers.size()){
            cnt3 += numbers[n3];
            n3+=3;
        }
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    return 0;
}
