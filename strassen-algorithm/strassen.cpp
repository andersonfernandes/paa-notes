#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef vector< vector<int> > matrix;

/*
  Receives two 2x2 matrix and applies the strassen algorithm
*/
void strassen_base(matrix a, matrix b, matrix &c) {
  int m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  int m2 = b[0][0] * (a[1][0] + a[1][1]);
  int m3 = a[0][0] * (b[0][1] - b[1][1]);
  int m4 = a[1][1] * (b[1][0] - b[0][0]);
  int m5 = b[1][1] * (a[0][0] + a[0][1]);
  int m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
  int m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

  c[0][0] = m1 + m4 - m5 + m7;
  c[0][1] = m3 + m5;
  c[1][0] = m2 + m4;
  c[1][1] = m1 - m2 + m3  + m6;
}

int main() {
  matrix a(2, vector<int>(2));
  matrix b(2, vector<int>(2));
  matrix c(2, vector<int>(2));

  a[0][0] = 1; a[0][1] = 3;
  a[1][0] = 7; a[1][1] = 5;

  b[0][0] = 6; b[0][1] = 8;
  b[1][0] = 4; b[1][1] = 2;

  strassen_base(a, b, c);

  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      cout << c[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}
