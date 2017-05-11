#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> Numbers;
    for(int q=0; q<N; q++){
        int temp;
        cin >> temp;
        Numbers.push_back(temp);
    }
    int best = -1;
    int lastNumb = -1, cnt=0;
    for(int i=0; i<Numbers.size(); i++){
        if(Numbers[i] > lastNumb){
            cnt++;
            lastNumb = Numbers[i];
        }else{
            if(cnt > best){
                best = cnt;
            }
            lastNumb = Numbers[i];
            cnt = 1;
        }
    }
    if(cnt > best) best = cnt;
    cout << best << endl;
    return 0;
}
