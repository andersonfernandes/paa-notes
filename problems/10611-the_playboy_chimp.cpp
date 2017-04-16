/*
  10611 - The Playboy Chimp <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552>
*/

#include <bits/stdc++.h>
using namespace std;

int smaller, taller;

int get_taller(vector<int> ladies, int h, int mid) {
  while (ladies[mid] <= h){
    ++mid;

    if (mid >= ladies.size()) return -1;
  }

  return mid;
}

int get_smaller(vector<int> ladies, int h, int mid) {
  while (ladies[mid] >= h){
    --mid;

    if (mid < 0) return -1;
  }

  return mid;
}

void search(vector<int> ladies, int h) {
  vector<int>::iterator sit = lower_bound(ladies.begin(), ladies.end(), h);
  vector<int>::iterator tit = upper_bound(ladies.begin(), ladies.end(), h);

  int si = distance(ladies.begin(), sit);
  int ti = distance(ladies.begin(), tit);

  smaller = get_smaller(ladies, h, si);
  taller = get_taller(ladies, h, ti);
}

int main() {
  int n, qs;
  cin >> n;
  vector<int> ladies(n);

  for (int i = 0; i < n; ++i) {
    cin >> ladies[i];
  }

  cin >> qs;

  for (; qs > 0; --qs) {
    int q;
    cin >> q;

    search(ladies, q);

    if (smaller == -1) cout << "X ";
    else cout << ladies[smaller] << " ";

    if (taller == -1) cout << "X";
    else cout << ladies[taller];

    cout << endl;
  }

  return 0;
}
