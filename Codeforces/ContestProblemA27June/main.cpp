#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int c, v0,v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    vector<int> bookdays(1000000, 0);
    bookdays[0] = v0;
    int sol = 1;
    for(int i=1; i<1000000; i++){
        if(bookdays[i-1] >= c){
            cout << sol << endl;
            return 0;
        }else{
            if(l + (v0+(i*a)) > v1 ){
                bookdays[i] = (bookdays[i-1] - l) + v1;
            }
            bookdays[i] = (bookdays[i-1]-l)+(v0+(i*a));
            sol++;
        }
    }

    return 0;
}
