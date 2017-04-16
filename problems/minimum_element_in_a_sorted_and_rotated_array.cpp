/*
  Minimum element in a sorted and rotated array <http://www.practice.geeksforgeeks.org/problem-page.php?pid=819>
*/

#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int> a, int li, int hi) {
  if (li == hi) return a[li];

  int mid = (li + hi) / 2;
  if (a[hi] < a[mid]) return find_min(a, mid+1, hi);
  else return find_min(a, li, mid);
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

    cout << find_min(a, 0, a.size()-1) << endl;
  }

  return 0;
}
