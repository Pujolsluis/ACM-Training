#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> tophalf, belowhalf;
    int imparesTop = 0, imparesBottom = 0;
    vector<int> imparesTopV, imparesBotV;
    for(int i=0; i<n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        tophalf.push_back(temp1);
        belowhalf.push_back(temp2);
        if(belowhalf % 2 == 0 && tophalf % 2 != 0){
            imparesTop++;
            imparesTopV.push_back(i);
        }
        else if(tophalf % 2 == 0 && belowhalf % 2 != 0){
            imparesBottom++;
            imparesBotV.push_back(i);
        }
    }
    if(imparesTop == 0 && imparesBottom == 0 || imparesTop % 2 == 0 && imparesBottom % 2 == 0){
        cout << 0 << endl;
        return 0;
    }


    return 0;
}
