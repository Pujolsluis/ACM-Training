#include <iostream>
#include <vector>
using namespace std;

int L,R;
long long memo[2][1e5+7];
vector<int> A,B;
int go(int type, int i){
    if(i > R) return 0;
    int sol = 0;
    if(type == 1){
        if(i%2 != 0){
            sol += A[i] + go(type, i+1);
        }else{
            sol += B[i] + go(type, i+1);
        }
    }else{
        if(i%2 != 0){
            sol += B[i] + go(type, i+1);
        }else{
            sol += A[i] + go(type, i+1);
        }
    }


}

int main()
{
    int N,Q;
    cin >> N >> Q;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    for(int i=0; i<Q; i++){
        int type;
        cin >> type >> L >> R;

    }
    return 0;
}
