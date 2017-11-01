//============================================================================
// Name        : Harry.cpp
// Author      : Luis Pujols
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long llong;

map<llong, llong> bitmask(vector<long long>& elements){
	int K = elements.size();
	cerr << "=============SUBSETS=============" << endl;
	map<llong, llong> sumOfSubsets;
	for(int mask = 0; mask < (1 << K); mask++){
		llong sum = 0;
		for(int i = 0; i < K; i++){
			if(mask & (1 << i)){
				cerr << elements[i] << " ";
				sum += elements[i];
			}
		}
		cerr << endl;
		sumOfSubsets[sum]++;
	}
	return sumOfSubsets;
}


int main() {
	int N;
	long long P;
	cin >> N >> P;

	vector<long long> powers;
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		powers.push_back(temp);
	}

	int mid = (powers.size() + 1) / 2;
	cerr << "mid: " << mid << endl;
	vector<llong> firstHalf, secondHalf;
	for(int i = 0; i < mid; i++){
		firstHalf.push_back(powers[i]);
	}
	for(int j = mid; j < powers.size(); j++){
		secondHalf.push_back(powers[j]);
	}

	cerr << "=========Each side of the array=========" << endl;
	for(int v : firstHalf){
		cerr << v << " ";
	}
	cerr << endl;
	for(int v : secondHalf){
			cerr << v << " ";
	}
	cerr << endl;

	map <long long, long long> firstHalfSum, secondHalfSum;

	firstHalfSum = bitmask(firstHalf);
	secondHalfSum = bitmask(secondHalf);

	cerr << "=========Sum of Subsets=========" << endl;
	for(auto it : firstHalfSum){
		cerr << it.first << " : " << it.second << endl;
	}
	cerr << endl;

	for(auto it : secondHalfSum){
		cerr << it.first << " : " << it.second << endl;
	}
	cerr << endl;


	return 0;
}


/*
4 10
5 4 2 11

4 10
5 3 4 6


5 10
1 4 2 7 8

7 10
5 4 2 7 6 9 1

7 10
10 4 5 1 2 9 30

 */
