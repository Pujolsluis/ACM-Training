//============================================================================
// Name        : Perfect.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
2-SAT using SCC Kosaraju's algorithm

Write the boolean formula as a conjunction of implications (e.g.
(x1->x2) ^ (~x1->x3)), and create a graph whose vertices are xi and ~xi
for all variables xi, and whose edges are the implications. The
formula is satisfiable if and only if no contradiction of the form
xi -> ~xi -> xi arises following a chain of such implications. This
amounts to checking whether xi and ~xi are in the same strongly
connected component, which can be done in linear time.

Building the Graph

The expression (u or v) is equivalent to (~u --> v) and also (~v --> u),
and in fact the 2 equations together capture all the possibilities in the
expression (u or v). Thus build a graph of size 2n (where n is the number
of variables), then for each expression (u or v) construct two directed
edges accordingly. There is a contradiction (unsatisfiable) if, for some
variable x, there is a path from x to ~x AND a path from ~x to x.
Otherwise for the given constraints our expression is satisfiable.

Assign true to variable x if there is no path x -> ~x; otherwise, we can assign
the value false since we know that there is no path ~x -> x
*/

#include <cstdio>
#include <stdexcept>

#include <vector>
#include <stack>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

class TwoSAT {
   int N;          // number of variables, indexed from 1 to N
                   // negation of variable i is indicated as -i
                   // these are mapped to vertexes (i-1)*2 and (i-1)*2 + 1
   VVI G, GT;      // implication graph and its transpose (in adjacency list
                   // form)

   VI assigned;    // assigned true/false value for each "vertex"

   int neg(int u) { return u ^ 1; }

   VI vis, which_scc;
   stack<int> S;
   // Kosaraju's 2 DFS algorithm
   void dfs(const VVI& adj, int u, int comp = -1) {
      vis[u] = 1;
      if (comp >= 0)
         which_scc[u] = comp;
      for(int j = 0; j < (int) adj[u].size(); ++j) {
         int v = adj[u][j];
         if(!vis[v])
            dfs(adj, v, comp);
      }
      if (comp < 0)
         S.push(u);
   }

   static int var2vertex(int x) {
      if (x > 0) return 2*(x-1);
      else       return 2*(-x-1) + 1;
   }
   static int vertex2var(int u) {
      return (u & 1) ? -(u/2+1) : (u/2+1);
   }

public:
   TwoSAT(int _N) : N(_N), G(_N*2), GT(_N*2) { }

   // add x or y clause
   void add_clause(int x, int y) {
      // transform the expresion "x or y" to these two implications:
      //    ~x -> y
      //    ~y -> x
      add_implication(-x, y);
      add_implication(-y, x);
   }

   // single variable clause; this means that this single varialbe must be true
   void add_clause(int x) {
      add_clause(x, x);
   }

   // add x xor y clause
   void add_xor_clause(int x, int y) {
      add_clause(x, y);
      add_clause(-x, -y);
   }

   void add_equiv_clause(int x, int y) {
      add_implication(x, y);
      add_implication(y, x);
   }

   void add_implication(int x, int y) {
      int u = var2vertex(x);
      int v = var2vertex(y);

      G[u].push_back(v);
      GT[v].push_back(u);
   }

   bool process() {
      // 1st DFS
      vis = VI(2*N, 0);
      for(int u = 0; u < 2*N; ++u) {
         if(!vis[u])
            dfs(G, u);
      }

      // 2nd DFS
      vis = VI(2*N, 0);
      which_scc = VI(2*N, -1);
      int ncomp = 0;
      while (!S.empty()) {
         int u = S.top(); S.pop();
         if(!vis[u]) {
            dfs(GT, u, ncomp);
            ncomp++;
         }
      }

      assigned.clear();

      // check if i and -i are in same strongly connected component
      for (int i = 1; i <= N; ++i) {
         int u = var2vertex(i);
         if (which_scc[u] == which_scc[neg(u)]) {
            return false;
         }
      }

      // compute the assigned value for each "vertex"
      assigned = VI(2*N, -1);
      // http://codeforces.com/blog/entry/16205?#comment-342676
      for (int i = 1; i <= N; ++i) {
         int u = var2vertex(i);
         assigned[u] = which_scc[u] > which_scc[neg(u)];
         assigned[neg(u)] = !assigned[u];
      }

      return true;
   }

   int assigned_value(int x) {
      if (x <= 0 || x > N)
         throw out_of_range("Variable is out of range");
      return assigned[ var2vertex(x) ];
   }
};

/*

12 8
1 7
1 6
12 7
12 6
-6 -12
-6 -1
-7 -12
-7 -1

10 13
-9 -9
1 8
1 4
9 8
9 4
2 7
2 5
9 7
9 5
2 -7
2 1
-8 -7
-8 1

3 3
+1 +2
-1 +2
-1 -3

*/

int main(int argc, char *argv[]) {
   int N, M;
//   cin >> N >> M;
   scanf("%d %d", &N, &M);
   TwoSAT sat(N);
   for(int m = 0; m < M; ++m) {
      char c1, c2;
      int x, y;
      scanf("%c%d %c%d", &c1, &x, &c2, &y);
//      cin >> s1 >> s2;
      if(c1 == '-'){
    	  x = -x;
      }

      if(c2 == '-'){
          y = -y;
      }

      sat.add_clause(x, y);
//      cerr << "x: " << x << " y: " << y << endl;
   }

   if (sat.process()) {
//      cout <<  "Satisfiable" << endl;
//	   printf("Satisfiable\n");
	   printf("1\n");
//      for (int i = 1; i <= N; ++i)
//         cerr << i << ": " << sat.assigned_value(i) << endl;
   }
   else
//      cout << "Not satisfiable" << endl;
//	   printf("Not satisfiable\n");
	   printf("0\n");

   return 0;
}




//for(int m = 0; m < M; ++m) {
//     string s1, s2;
//     int x, y;
//     if(s1[0] == '-'){
//   	  x = -(s1[1]-'0');
//     }else{
//   	  x = s1[1]-'0';
//     }
//     if(s2[0] == '-'){
//         	  y = -(s2[1]-'0');
//     }else{
//   	  y = s2[1]-'0';
//     }
//     sat.add_clause(x, y);
//  }
