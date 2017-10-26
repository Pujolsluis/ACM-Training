#include <cstdio>
#include <set>

using namespace std;

memo[N+4];
fact(int n){

}

int main()
{
    set<long long> even, uneven;
    int Q;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        char query;
        scanf("%c", &query);
        if(query == 'q'){



        }else if(query == 'i'){
            int numb;
            scanf("%d", &numb);
            if(numb % 2 == 0) even.insert(numb);
            else uneven.insert(numb);
        }else{
            int numb;
            scanf("%d", &numb);
            if(numb % 2 == 0) even.remove(numb);
            else uneven.remove(numb);
        }
    }
    return 0;
}
