#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int k=0; k<T; k++){
        string t1,t2;
        cin >> t1 >> t2;
        bool outputed = false;
        if(t1[5] == t2[5]){
            if(t1[0] == '1' && t1[1] == '2' && t1[5] == 'P' && t2[0] == t1[0] && t2[1] == t1[1]){
                    for(int i=0; i<5; i++){
                    if(t1[i] < t2[i]){
                        cout << "First" << endl;
                        break;
                    }else if(t1[i] > t2[i]){
                        cout << "Second" << endl;
                        break;
                    }
                }
                outputed = true;
            }else if(t1[0] == '1' && t1[1] == '2' && t1[5] == 'P' || t2[0] == '1' && t2[1] == '2' && t2[5] == 'P'){
                if(t1[0] == '1' && t1[1] == '2') cout << "First" << endl;
                else cout << "Second" << endl;
                outputed = true;
             }

            if(!outputed){
                for(int i=0; i<5; i++){
                    if(t1[i] < t2[i]){
                        cout << "First" << endl;
                        break;
                    }else if(t1[i] > t2[i]){
                        cout << "Second" << endl;
                        break;
                    }
                }
            }
        }
        else{
            if(t1[5] < t2[5]){
                cout << "First" << endl;
            }else{
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}
