//============================================================================
// Name        : Bishu.cpp
// Author      : Luis Pujols
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> powers;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		powers.push_back(temp);
	}

	sort(powers.begin(), powers.end());

	vector<long long> prefixSum;

	for(int i = 0; i < n; i++){
		if(i == 0) prefixSum.push_back(powers[i]);
		else prefixSum.push_back(prefixSum[i-1] + powers[i]);
	}

//	for(int v : prefixSum){
//		cerr << v << " ";
//	}
//
//	cerr << endl;

	int Q;
	cin >> Q;
	for(int i = 0; i < Q; i++){
		int temp;
		cin >> temp;
		auto it = upper_bound(powers.begin(), powers.end(), temp);
		if(it == powers.end()){
			cout << powers.size() << " " << prefixSum[n-1] << endl;
		}else{
			int pos = it - powers.begin();
				cout << pos << " " << prefixSum[pos-1] << endl;
		}
	}
	return 0;
}

/*
7
1 2 3 4 5 10 7
3
3
10
2

 */
