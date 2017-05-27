#include <stdio.h>
#include <iostream>

using namespace std;

long long foo(long long A, long long B, long long C, long long D, int t){
    return ((A*(t*t*t)) + (B*(t*t)) + C*(t) + D);
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        long long a,b,c,d, k;
        cin >> a >> b >> c >> d >> k;
       long long cnt = 1;
       bool alive = true;
       while(alive){
           if(foo(a,b,c,d,cnt) > k){
               cout << cnt-1 << endl;
               cnt = 1;
               alive = false;
           }
           cnt++;
       }

    }
    return 0;
}
