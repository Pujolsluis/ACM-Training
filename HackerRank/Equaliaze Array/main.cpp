#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    map<int,int> numbers;
    int best = 0;
    int bestID = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        numbers[temp]++;
        if(numbers[temp] > best){
            bestID = temp;
            best = numbers[temp];
        }
    }
    int sum = 0;
    map<int,int>::iterator it = numbers.begin();
    for(it; it != numbers.end(); it++){
        if(it->first != bestID) sum += it->second;
    }
    cout << sum << endl;
    return 0;
}
