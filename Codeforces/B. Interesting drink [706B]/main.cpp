#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long const MAX_N = 1000004;
long long fen[MAX_N+1];
void update(int p, int val){
	for (int i = p; i <= MAX_N; i += i & -i)
		fen[i] += val;
}
long long sum(long long p){
	long long ans = 0;
	for (long long i = p; i; i -= i & -i)
		ans += fen[i];
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		update(temp, 1);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		long long temp;
		cin >> temp;
		cout << sum(min(temp, MAX_N)) << endl;
	}
	return 0;
}
