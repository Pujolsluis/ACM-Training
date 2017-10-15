#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m && n != 0 && m != 0){

        set<int> jill, jack;

        for(int i=0; i<n; i++){
           int temp;
           cin >> temp;
           jill.insert(temp);
        }

        for(int i=0; i<m; i++){
           int temp;
           cin >> temp;
           jack.insert(temp);

        }

        int cnt = 0;
        set<int>::iterator it = jill.begin();

        for(int v : jill){
            if(jack.count(v)) cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}
