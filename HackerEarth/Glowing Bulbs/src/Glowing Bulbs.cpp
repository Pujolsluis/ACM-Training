//============================================================================
// Name        : Glowing.cpp
// Author      : Luis Pujols
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>

using namespace std;


long long bitmask(long long M, vector<int>& primesOn){
	long long cnt = 0;
	long long K = primesOn.size();
	for(int mask = 1; mask < (1 << K); mask++){
		long long fact = 1;
		long long bitsOn = 0;
		for(int i = 0; i < K; i++){
			if(mask & (1 << i)){
				fact *= primesOn[i];
				bitsOn++;
			}
		}
		if(bitsOn % 2 != 0){
			cnt += M/fact;
		}else{
			cnt -= M/fact;
		}
	}

	return cnt;
}



long long binary_search_simple(long long lo, long long hi,
	vector<int>& primesOn, long long K) {
   long long res = -1; // remains -1 if no argument is good
   while (lo <= hi) {
	  long long mid = lo + (hi - lo) / 2;
	  long long resFunc = bitmask(mid, primesOn);
	  if (resFunc > K) {
	     hi = mid - 1;
      }
	  else if (resFunc < K) {
		 lo = mid + 1;
      } else {
         hi = mid - 1;
         res = mid;
      }
   }
   return res;
}




int main() {
	int T;
	cin >> T;
	for(int m = 0; m < T; m++){
		string s;
		cin >> s;
		vector<int> primesOn;
		set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '1' && primes.count(i+1)){
				primesOn.push_back(i+1);
			}
		}

		long long K;
		cin >> K;
		cout << binary_search_simple(1, 1e18, primesOn, K) << endl;
//		cout << bitmask(18, primesOn) << endl;
	}
	return 0;
}

/*
3
0110000000000000000000000000000000000000
5
0010000000000000000000000000000000000000
5
0100000000100000001000100000101000001000
16807

1
0110000000000000000000000000000000000000
5

1
0010000000000000000000000000000000000000
5

1
0100000000100000001000100000101000001000
16807
 */
