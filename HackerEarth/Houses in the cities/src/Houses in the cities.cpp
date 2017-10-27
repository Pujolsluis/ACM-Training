//============================================================================
// Name        : Houses.cpp
// Author      : Luis Pujols
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
//	cin >> T;
	for(int i=0; i<T; i++){
		int N;
		scanf("%d", &N);
//		cin >> N;
		vector<long long> cities;
		vector<long long> housesPrefixSum;
		for(int j=0; j<N; j++){
			long long temp;
			scanf("%lld", &temp);
//			cin >> temp;
			if(j == 0){
				cities.push_back(temp);
				housesPrefixSum.push_back(temp);
			}else{
				cities.push_back(temp);
				housesPrefixSum.push_back(housesPrefixSum[j-1] + temp);
			}
		}
//		for(long long v: housesPrefixSum){
//			cerr << v << " ";
//		}
//		cerr << endl;
		int Q;
		scanf("%d", &Q);
//		cin >> Q;
		for(int m = 0; m < Q; m++){
			int l,r;
//			cin >> l >> r;
			scanf("%d %d", &l, &r);
			l--; r--;
			if(l == 0) printf("%lld\n", housesPrefixSum[r]);
//					   cout << housesPrefixSum[r] << endl;
			else printf("%lld\n",  housesPrefixSum[r] - housesPrefixSum[l-1] );
//				 cout << housesPrefixSum[r] - housesPrefixSum[l-1] << endl;
		}
	}
	return 0;
}
