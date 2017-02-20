#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef vector< vector<int> > matrix;

void print_matrix(matrix m) {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m.size(); ++j) {
      cout << m[i][j] << "  ";
    }
    cout << endl;
  }
}

void fill_sub(matrix m, matrix &sub, int quadrant) {
  switch (quadrant) {

    case 1:
      for (int i = 0; i < (m.size() / 2); ++i) {
        for (int j = 0; j < (m.size() / 2); ++j) {
          sub[i][j] = m[i][j];
        }
      }
    break;

    case 2:
      for (int i = 0, k = 0; i < (m.size() / 2); ++i, ++k) {
        for (int j = (m.size() / 2), l = 0; j < m.size(); ++j, ++l) {
          sub[k][l] = m[i][j];
        }
      }
    break;

    case 3:
      for (int i = (m.size() / 2), k = 0; i < m.size(); ++i, ++k) {
        for (int j = 0, l = 0; j < (m.size() / 2); ++j, ++l) {
          sub[k][l] = m[i][j];
        }
      }
    break;

    case 4:
      for (int i = (m.size() / 2), k = 0; i < m.size(); ++i, ++k) {
        for (int j = (m.size() / 2), l = 0; j < m.size(); ++j, ++l) {
          sub[k][l] = m[i][j];
        }
      }
    break;

  }
}

void sum(matrix &s, matrix a, matrix b) {
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < a.size(); ++j) {
      s[i][j] = a[i][j] + b[i][j];
    }
  }
}

void sub(matrix &s, matrix a, matrix b) {
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < a.size(); ++j) {
      s[i][j] = a[i][j] - b[i][j];
    }
  }
}

void join_matrix(matrix &c, matrix c1, matrix c2, matrix c3, matrix c4) {
  // Join C1 with C
  for (int i = 0; i < (c.size() / 2); ++i) {
    for (int j = 0; j < (c.size() / 2); ++j) {
      c[i][j] = c1[i][j];
    }
  }

  // Join C2 with C
  for (int i = 0, k = 0; i < (c.size() / 2); ++i, ++k) {
    for (int j = (c.size() / 2), l = 0; j < c.size(); ++j, ++l) {
      c[i][j] = c2[k][l];
    }
  }

  // Join C3 with C
  for (int i = (c.size() / 2), k = 0; i < c.size(); ++i, ++k) {
    for (int j = 0, l = 0; j < (c.size() / 2); ++j, ++l) {
      c[i][j] = c3[k][l];
    }
  }

  // Join C4 with C
  for (int i = (c.size() / 2), k = 0; i < c.size(); ++i, ++k) {
    for (int j = (c.size() / 2), l = 0; j < c.size(); ++j, ++l) {
      c[i][j] = c4[k][l];
    }
  }

}

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

void strassen(matrix &c, matrix a, matrix b) {
  if (a.size() > 2) {
    int size = a.size() / 2;

    matrix a1(size, vector<int>(size));
    matrix a2(size, vector<int>(size));
    matrix a3(size, vector<int>(size));
    matrix a4(size, vector<int>(size));

    fill_sub(a, a1, 1);
    fill_sub(a, a2, 2);
    fill_sub(a, a3, 3);
    fill_sub(a, a4, 4);

    matrix b1(size, vector<int>(size));
    matrix b2(size, vector<int>(size));
    matrix b3(size, vector<int>(size));
    matrix b4(size, vector<int>(size));

    fill_sub(b, b1, 1);
    fill_sub(b, b2, 2);
    fill_sub(b, b3, 3);
    fill_sub(b, b4, 4);

    matrix p1(size,  vector<int>(size));
    matrix p2(size,  vector<int>(size));
    matrix p3(size,  vector<int>(size));
    matrix p4(size,  vector<int>(size));
    matrix p5(size,  vector<int>(size));
    matrix p6(size,  vector<int>(size));
    matrix p7(size,  vector<int>(size));

    // P1 Calculus
    matrix p1_aux_a(size,  vector<int>(size));
    matrix p1_aux_b(size,  vector<int>(size));

    strassen(p1_aux_a, a1, b2);
    strassen(p1_aux_b, a1, b4);
    sub(p1, p1_aux_a, p1_aux_b);

    // P2 Calculus
    matrix p2_aux_a(size,  vector<int>(size));
    matrix p2_aux_b(size,  vector<int>(size));

    strassen(p2_aux_a, a1, b4);
    strassen(p2_aux_b, a2, b4);
    sum(p2, p2_aux_a, p2_aux_b);

    // P3 Calculus
    matrix p3_aux_a(size,  vector<int>(size));
    matrix p3_aux_b(size,  vector<int>(size));

    strassen(p3_aux_a, a3, b1);
    strassen(p3_aux_b, a4, b1);
    sum(p3, p3_aux_a, p3_aux_b);

    // P4 Calculus
    matrix p4_aux_a(size,  vector<int>(size));
    matrix p4_aux_b(size,  vector<int>(size));

    strassen(p4_aux_a, a4, b3);
    strassen(p4_aux_b, a4, b1);
    sub(p4, p4_aux_a, p4_aux_b);

    // P5 Calculus
    matrix p5_aux_a(size,  vector<int>(size));
    matrix p5_aux_b(size,  vector<int>(size));
    matrix p5_aux_c(size,  vector<int>(size));
    matrix p5_aux_d(size,  vector<int>(size));

    strassen(p5_aux_a, a1, b1);
    strassen(p5_aux_b, a1, b4);
    strassen(p5_aux_c, a4, b1);
    strassen(p5_aux_d, a4, b4);
    sum(p5, p5_aux_a, p5_aux_b);
    sum(p5, p5, p5_aux_c);
    sum(p5, p5, p5_aux_d);

    // P6 Calculus
    matrix p6_aux_a(size,  vector<int>(size));
    matrix p6_aux_b(size,  vector<int>(size));
    matrix p6_aux_c(size,  vector<int>(size));
    matrix p6_aux_d(size,  vector<int>(size));

    strassen(p6_aux_a, a2, b3);
    strassen(p6_aux_b, a2, b4);
    strassen(p6_aux_c, a4, b3);
    strassen(p6_aux_d, a4, b4);
    sum(p6, p6_aux_a, p6_aux_b);
    sub(p6, p6, p6_aux_c);
    sub(p6, p6, p6_aux_d);

    // P6 Calculus
    matrix p7_aux_a(size,  vector<int>(size));
    matrix p7_aux_b(size,  vector<int>(size));
    matrix p7_aux_c(size,  vector<int>(size));
    matrix p7_aux_d(size,  vector<int>(size));

    strassen(p7_aux_a, a1, b1);
    strassen(p7_aux_b, a1, b2);
    strassen(p7_aux_c, a3, b1);
    strassen(p7_aux_d, a3, b2);
    sum(p7, p7_aux_a, p7_aux_b);
    sub(p7, p7, p7_aux_c);
    sub(p7, p7, p7_aux_d);

    matrix c1(size, vector<int>(size));
    matrix c2(size, vector<int>(size));
    matrix c3(size, vector<int>(size));
    matrix c4(size, vector<int>(size));

    // C1 Calculus
    sum(c1, p5, p4);
    sub(c1, c1, p2);
    sum(c1, c1, p6);

    // C2 Calculus
    sum(c2, p1, p2);

    // C3 Calculus
    sum(c3, p3, p4);

    // C4 Calculus
    sum(c4, p5, p1);
    sub(c4, c1, p3);
    sub(c4, c1, p7);

    join_matrix(c, c1, c2, c3, c4);
  } else {
    strassen_base(a, b, c);
  }
}

int main() {
  int n, e;

  cin >> n;
  cin >> e;

  matrix a(n, vector<int>(n));
  matrix c(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  strassen(c, a, a);
  print_matrix(c);

  return 0;
}
