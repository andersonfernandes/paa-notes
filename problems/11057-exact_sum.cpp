/*
  11057 - Exact Sum <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1998>
*/

#include <bits/stdc++.h>
using namespace std;

int ans_i = 0, ans_j = INT_MAX;

vector<int> merge_sort(const vector<int> &data) {
  if (data.size() <= 1) {
    return data;
  }

  int middle = data.size() / 2;
  vector<int> left(data.begin(), data.begin()+middle);
  vector<int> right(data.begin()+middle, data.end());

  left = merge_sort(left);
  right = merge_sort(right);

  vector<int> result(data.size());

  merge(left.begin(), left.end(),
        right.begin(), right.end(),
        result.begin());

  return result;
}

void find_elements(vector<int> books, int li, int hi, int m) {
  while (li < hi) {
    int sum = books[li] + books[hi];

    if (sum == m && (hi - li) < (ans_j - ans_i)) {
      ans_i = li;
      ans_j = hi;

      ++li; --hi;
    } else if (sum < m) {
      ++li;
    } else if (sum > m) {
      --hi;
    }
  }
}

int main() {
  int n, m;

  while (cin >> n) {
    vector<int> books(n);

    for (int i = 0; i < n; ++i) {
      cin >> books[i];
    }

    cin >> m;

    books = merge_sort(books);
    find_elements(books, 0, n-1, m);

    printf("Peter should buy books whose prices are %d and %d.\n\n", books[ans_i], books[ans_j]);
    ans_i = 0, ans_j = INT_MAX;
  }

  return 0;
}
