#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> patients, vacc;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        patients.push_back(temp);
    }
    for(int j=0; j<N; j++){
        int temp;
        cin >> temp;
        vacc.push_back(temp);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            if(patients[j] > patients[j+1]){
                int temp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = temp;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            if(vacc[j] > vacc[j+1]){
                int temp = vacc[j];
                vacc[j] = vacc[j+1];
                vacc[j+1] = temp;
            }
        }
    }
    for(int i=0; i<N; i++){
        if(vacc[i] < patients[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
