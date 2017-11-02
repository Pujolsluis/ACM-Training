//============================================================================
// Name        : Harry.cpp
// Author      : Luis Pujols
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
//#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long llong;

map<llong, llong> bitmask(vector<long long>& elements){
	int K = elements.size();
//	cerr << "=============SUBSETS=============" << endl;
	map<llong, llong> sumOfSubsets;
	for(int mask = 0; mask < (1 << K); mask++){
		llong sum = 0;
		for(int i = 0; i < K; i++){
			if(mask & (1 << i)){
//				cerr << elements[i] << " ";
				sum += elements[i];
			}
		}
//		cerr << endl;
		sumOfSubsets[sum]++;
	}
	return sumOfSubsets;
}


int main() {
	long long N;
	long long P;
//	cin >> N >> P;
	scanf("%lld %lld", &N, &P);

	vector<long long> powers;
	for(int i = 0; i < N; i++){
		long long temp;
//		cin >> temp;
		scanf("%lld", &temp);
		powers.push_back(temp);
	}

	int mid = (powers.size() + 1) / 2;
//	cerr << "mid: " << mid << endl;
	vector<llong> firstHalf, secondHalf;
	for(int i = 0; i < mid; i++){
		firstHalf.push_back(powers[i]);
	}
	for(int j = mid; j < powers.size(); j++){
		secondHalf.push_back(powers[j]);
	}

//	cerr << "=========Each side of the array=========" << endl;
//	for(int v : firstHalf){
//		cerr << v << " ";
//	}
//	cerr << endl;
//	for(int v : secondHalf){
//			cerr << v << " ";
//	}
//	cerr << endl;

	map <long long, long long> firstHalfSum, secondHalfSum;

	firstHalfSum = bitmask(firstHalf);
	secondHalfSum = bitmask(secondHalf);

//	cerr << "=========Sum of Subsets=========" << endl;
//	for(auto it : firstHalfSum){
//		cerr << it.first << " : " << it.second << endl;
//	}
//	cerr << endl;
//
//	for(auto it : secondHalfSum){
//		cerr << it.first << " : " << it.second << endl;
//	}
//	cerr << endl;


//	Making Prefix Sum first half
	vector<long long> prefixSumOfFirstHalf;
	vector<long long> keysFirst;

	bool firstElement = true;

	int idx = 0;

	for(auto it : firstHalfSum){
		keysFirst.push_back(it.first);
		if( firstElement ){
			firstElement = false;
			prefixSumOfFirstHalf.push_back(it.second);
		} else {
			prefixSumOfFirstHalf
				.push_back(prefixSumOfFirstHalf[idx-1] + it.second);
		}
		idx++;
	}

//	cerr << "========= KeysOfFirstHalf =========" << endl;
//	for(long long v : keysFirst){
//		cerr << v << " ";
//	}
//	cerr << endl;
//
//	cerr << "========= prefixSumOfFirstHalf =========" << endl;
//	for(long long v : prefixSumOfFirstHalf){
//		cerr << v << " ";
//	}
//	cerr << endl;

	llong sol = 0;
	for(auto it : secondHalfSum){
		if( it.first > P ) break;
		else {
//			cerr << "number of second half: " << it.first << endl;

			auto it2 = upper_bound(keysFirst.begin(), keysFirst.end(), P - it.first);
//			cerr << "(P-1) - it.first: " << (P-1) - it.first << endl;
//			cerr << "upper bound of (P-1) - it.first: " << *it2 << endl;
//			for( auto it3 = keysFirst.begin(); it3 != it2; it3++){
//				if ( !(it.first == 0 && *it3 == 0) ) {
//					cerr << *it3 << ", ";
//				}
//			}
//			cerr << endl;
			int pos = it2 - keysFirst.begin();
			if( pos > 0){
				pos--;
				sol += prefixSumOfFirstHalf[pos] * it.second;
			}
//			cerr << "prefixSumOfFirstHalf: " << prefixSumOfFirstHalf[pos] << endl;
			if(it.first == 0) sol--;
//			cerr << "sol: " << sol << endl;
		}
	}
//	cerr << endl;

//	cout << sol << endl;
	printf("%lld\n", sol);

	return 0;
}


/*
5 10
1 4 2 7 8

4 10
5 3 4 6

4 10
5 3 5 6


5 10
1 4 2 7 8

7 10
5 4 2 7 6 9 1

7 10
10 4 5 1 2 9 30

 */
