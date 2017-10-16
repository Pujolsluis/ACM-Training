#include <iostream>
#include <set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        multiset<int> list1,list2;
        int N,M;
        cin >> N >> M;
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            list1.insert(temp);
        }
        for(int j=0; j<M; j++){
            int temp;
            cin >> temp;
            list2.insert(temp);
        }
        int sol = 0;
        if(N > M){
            for(int num : list1){
                if(!list2.count(num)) sol++;
                else list2.erase(list2.find(num));
            }
            sol += list2.size();
        }else{
            for(int num : list2){
                if(!list1.count(num)) sol++;
                else list1.erase(list1.find(num));
            }
            sol += list1.size();
        }
        cout << sol << endl;
    }
    return 0;
}
