/*
  Count the Zeros <http://www.practice.geeksforgeeks.org/problem-page.php?pid=897>
*/

#include <bits/stdc++.h>
using namespace std;

int zeros_count(vector<int> a, int li, int hi) {
  if (li == hi) return !a[li];

  if (a[li] == 0) return (hi+1) - li;

  int mid = (li + hi) / 2;
  if (a[mid] == 0) return ((hi + 1) - (mid)) + zeros_count(a, li, mid-1);
  else return zeros_count(a, mid+1, hi);
}

int main() {
  int t;
  cin >> t;

  for(; t > 0; --t) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    cout << zeros_count(a, 0, a.size()-1) << endl;
  }

  return 0;
}
