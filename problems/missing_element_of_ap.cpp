/*
  Missing element of AP <http://www.practice.geeksforgeeks.org/problem-page.php?pid=896>

  Análise: (Desconsiderando os tempos de pre-processamento dos dados na função main)

  O tempo de execução das chamadas recursivas da função find_missing como T(n/2) e o restante da execução como um tempo constante k,
  temos como equação de recorrência:
          T(n) = T(n/2) + k

  Resolvendo essa equação, temos:
          T(n) = T(n/4 + k) + k = T(n/2^2) + 2k
          T(n) = T(n/8 + k) + 2k = T(n/2^3) + 3k
          T(n) = T(n/2^k) + kC

  Com n = 2^k, temos T(2^k) = T(2^k/2^k) = T(1) (tempo constante)
        T(1) = Ck (tempo costante)
  Percebe-se que log n = k (base 2), com n = 2^k

        T(n) = T(1) + C(log n)

  Desconsiderando as contantes o big-oh do algoritmo é: O(log n).

*/

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
