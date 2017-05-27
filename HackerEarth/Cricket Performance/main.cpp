#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<int> cricketPerformance;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        cricketPerformance.push_back(temp);
    }
    int best = 0;
    int consistency = 0;
    for(int i=0; i<cricketPerformance.size(); i++){
        if(cricketPerformance[i] >= 0){
            consistency += cricketPerformance[i];
            if(consistency > best) best = consistency;
        }else if(cricketPerformance[i] < 0 && consistency + cricketPerformance[i] >= 0){
                consistency += cricketPerformance[i];
        }else{
            consistency = 0;
        }
    }
    cout << best << endl;
    return 0;
}
