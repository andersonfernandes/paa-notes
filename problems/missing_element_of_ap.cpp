#include <bits/stdc++.h>
using namespace std;

int find_missing(vector<int> a, int diff) {
  if (a.size() == 1) return a[0] + diff;

  float mid = a.size() / 2;
  float left_diff = (a[mid] - a[0]) / mid;

  if (left_diff != diff) {
    vector<int> next_a(a.begin(), a.begin() + mid);
    return find_missing(next_a, diff);
  } else {
    vector<int> next_a(a.begin() + mid, a.end());
    return find_missing(next_a, diff);
  }
}

int main() {
  int t;
  cin >> t;

  for (; t > 0; --t) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int diff = (a[n-1] - a[0]) / n;

    int missing = find_missing(a, diff);
    printf("%d\n", missing);
  }

  return 0;
}
