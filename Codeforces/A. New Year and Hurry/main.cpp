#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int maxMinutes = 240;
    maxMinutes -= k;
    int sol = 0;
    int minutes = 0;
    int i=1;
    for(int i=1; i<=n; i++){
        minutes += i*5;
        if(minutes <= maxMinutes) sol++;
    }
    cout << sol << endl;
    return 0;
}
