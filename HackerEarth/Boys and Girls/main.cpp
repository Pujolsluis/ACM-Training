#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int B,G;
        int N;
        cin >> N;
        cin >> B >> G;
        if((B<G && G-B > 1)|| (G<B && B-G > 1)){
            cout << "Little Jhool wins!" << endl;
        }else{
            cout << "The teacher wins!" << endl;
        }
    }
    return 0;
}
