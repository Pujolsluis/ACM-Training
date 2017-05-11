#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    vector<int> Numbers;
    int best = -1;
    int lastNumb = -1, cnt=0;
    for(int i=0; i<Numbers.size(); i++){
        if(Numbers[i] > lastNumb){
            cnt++;
            lastNumb = Numbers[i];
        }else{
            if(cnt > best){
                best = cnt;
                cnt = 0;
            }
            lastNumb = Numbers[i];
        }
    }
    cout << best << endl;
    return 0;
}
