/*
  10611 - The Playboy Chimp <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552>

  Análise:
  Na função search estão sendo usados as funções lower_bound e upper_bound da biblioteca do C++, segundo a documentação
  disponível no cplusplus.com, ambas tem tempo de execução O(log n).
  Desse modo a equação parcial do tempo de execução do algoritmo é: T(n) = 2log n
  As funções get_smaller e get_taller tem comportamento semelhante, e possuem os seguintes tempos de execução:
      * Pior caso: Quando o while percorre todo o array.
                   Nesse caso a complexidade é: O(n).
                   Adicionando isso na equação geral temos:
                      T(n) = 2log n + 2n

                   Logo a complexidade para esse caso é O(n).
      * Caso médio: Quando o while percorre metade do array.
                    Nesse caso o tempo de execução é T(n/2), então a complexidade é log n
                    Adicionando isso na equação geral temos:
                      T(n) = 2log n + 2log n = 4log n

                    Logo a complexidade para esse caso é O(log n).

      * Melhor caso: Quando o while não é executado.
                     Nesse caso a complexidade é O(1);
                     Adicionando isso na equação geral temos:
                      T(n) = 2log n + 2O(1)

                     Logo a complexidade para esse caso é O(log n)
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
