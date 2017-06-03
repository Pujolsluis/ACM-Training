#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> triangles;
    for(int i=0; i<N; i++){
        string temp1,temp2,temp3;
        string tempS = "";
        vector<string> sides;
        cin >> temp1 >> temp2 >> temp3;
        sides.push_back(temp1);
        sides.push_back(temp2);
        sides.push_back(temp3);
        sort(sides.begin(), sides.end());
        for(int j=0; j<3; j++){
            tempS += sides[j];
        }
        triangles[tempS]++;
    }
    map<string, int>::iterator it = triangles.begin();
    int sol = 0;
    for(it; it!=triangles.end(); it++){
        if(it->second == 1){
            sol++;
        }
    }
    cout << sol << endl;
    return 0;
}
