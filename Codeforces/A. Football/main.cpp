#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string,int> Teams;
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        Teams[temp]++;
    }
    int best = 0;
    string bestTeam;
    map<string,int>::iterator it = Teams.begin();
    for(it; it != Teams.end(); it++){
        if(it->second > best){
            bestTeam = it->first;
            best = it->second;
        }
    }
    cout << bestTeam << endl;
    return 0;
}
