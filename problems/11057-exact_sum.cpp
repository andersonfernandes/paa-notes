/*
  11057 - Exact Sum <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1998>

  Análise: (Desconsiderando os tempos de pre-processamento dos dados na função main)

  - Função merge_sort: Sejam as chamadas recursivas do merge_sort T(n/2), e a função merge um tempo constante de cn
    temos a seguinte equação de recorrência:
            T(n) = 2T(n/2) + cn

    Resolvendo a equação:
            T(n) = 2(2T(n/4) + cn/2) + cn = 4T(n/4) + 2cn
            T(n) = 4T(n/8) + cn/4) + 2cn = 8T(n/8) + 3cn
            T(n) = 2^k . T(n/2^k) + kcn

    Com n = 2^k, temos T(2^k) = T(2^k/2^k) = T(1)
    Assim: T(n) = 2^k . T(1) + kcn
    Percebe-se que log n = k (base 2), com n = 2^k
          T(n) = 2^(log n) . T(1) + cn(log n)
          T(n) = nc' + nc(log n) (considerando T(1) = c')

    Desconsiderando as constantes temos T(n) = n + n(log n)
    Como n(log n) é maior que n, temos que o big-oh do merge sort é O(n(log n)).

    Desse modo a equação parcial do tempo de execução do algoritmo é: T(n) = n(log n)

  - Função find_elements: Para essa funçãoo temos os seguintes casos
        * Pior caso: Quando o while percorre todo o array.
                     Nesse caso a complexidade é: O(n).
                     Adicionando isso na equação geral temos:
                        T(n) = n(log n) + n

                     Logo a complexidade para esse caso é O(n(log n)).

        * Caso médio: Quando o while percorre metade do array.
                     Nesse caso a complexidade é: O(log n).
                     Adicionando isso na equação geral temos:
                        T(n) = n(log n) + log n

                     Logo a complexidade para esse caso é O(n(log n)).

        * Melhor caso: Quando o while é executado apenas um vez.
                     Nesse caso a complexidade é: O(1).
                     Adicionando isso na equação geral temos:
                        T(n) = n(log n) + O(1)

                     Logo a complexidade para esse caso é O(n(log n)).

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
