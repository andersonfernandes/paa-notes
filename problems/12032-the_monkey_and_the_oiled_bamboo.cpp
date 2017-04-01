/*
  12032 - The Monkey and the Oiled Bamboo <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183>
*/

#include <bits/stdc++.h>
using namespace std;

bool simulate_jump(vector<int> rungs, int k) {
  for (int i = 0; i < rungs.size()-1; ++i) {
    int diff = rungs[i+1] - rungs[i];

    if (k < diff) return false;
    if (k == diff) return --k;
  }

  return true;
}

int main() {
  int t, n;

  cin >> t;

  for (int tc = 1; t > 0; --t, ++tc) {
    cin >> n;
    vector<int> rungs(n+1);

    for (int i = 1; i <= n; ++i) {
      cin >> rungs[i];
    }
    rungs[0] = 0;

    int k = 0;

    for (int i = n; i > 0; --i) {
      int diff = rungs[i] - rungs[i-1];

      if (diff >= k) k = diff;
    }

    if (!simulate_jump(rungs, k)) ++k;

    printf("Case %d: %d\n", tc, k);
  }

}
