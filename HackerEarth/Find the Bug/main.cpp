#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int r,c;
    r = c = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char temp;
            cin >> temp;
            if(temp == 'X'){
                r = i;
                c = j;
            }
        }
    }
    cout << r << "," << c << endl;
    return 0;
}
