#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long llong;
typedef vector<llong> VI;
typedef vector<VI> VVI;

const int MOD = 1000000007;

VVI matrix_multiply(const VVI& A, const VVI& B) {
   const int N = A.size();
   const int M = B.empty() ? 0 : B[0].size();
   const int K = A.empty() ? 0 : A[0].size();
   if (K != int(B.size())) return VVI();
   VVI R(N, VI(M));
   for (llong i = 0; i < N; ++i) {
      for (llong k = 0; k < K; ++k) {
         // Note: loops k and j are inverted to improve performance due to cache
         for (llong j = 0; j < M; ++j) {
            R[i][j] = (R[i][j] + (llong(A[i][k]) * B[k][j])) % MOD;
         }
      }
   }
   return R;
}

VVI matrix_identity(const llong N) {
   VVI R(N, VI(N, 0));
   for (llong i = 0; i < N; ++i)
      R[i][i] = 1;
   return R;
}

VVI matrix_power(VVI A, llong k) {
   const int N = A.size();
   VVI R = matrix_identity(N);
   while (k > 0) {
      if (k & 1) {
         R = matrix_multiply(R, A);
         --k;
      }
      k >>= 1;
      if (k <= 0) break;
      A = matrix_multiply(A, A);
   }
   return R;
}



int main()
{
    long long T,N;
    cin >> T;

    // Fibonacci
    VVI A(2, VI(2));
    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 0;

    for (long long i = 0; i < T; i++) {
      cin >> N;
      VVI Ak = matrix_power(A, N+1);
      printf("%d\n", (Ak[0][0] * 1 + Ak[0][1] * 0) % MOD);
    }

    return 0;
}
