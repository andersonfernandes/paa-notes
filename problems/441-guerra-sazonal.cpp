/*
   441 - Guerra sazonals <https://www.thehuxley.com/problem/441>
*/

#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_Y 25
#define MAX_X 26

typedef pair<int, int> ii;
typedef vector< vector<bool> > b_matrix; 

char image[MAX_Y][MAX_X];
int adj_y[] = {-1,-1,-1,0,1,1,1,0};
int adj_x[] = {-1,0,1,1,1,0,-1,-1};

b_matrix visited;
int dim;
int n_comp;

void dfs(ii s, int comp) {
  visited[s.first][s.second] = true;

  for (int i = 0; i < 8; i++) {
    int ny = s.first + adj_y[i];
    int nx = s.second + adj_x[i];

    if (ny >= 0 && ny < dim && nx >=0 && nx < dim && image[ny][nx] == '1') {
      if (!visited[ny][nx]) dfs(ii(ny, nx), comp);
    } 
  }

}

int main() {
  int c = 1;

  while (cin >> dim) {
    n_comp = 0;
    visited = b_matrix(dim, vector<bool>(dim, false));

    for (int i = 0; i < dim; i++) {
      cin >> image[i]; 
    }

    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
        if (!visited[i][j] && image[i][j] == '1') dfs(ii(i, j), ++n_comp);
      }      
    }

    cout << "Image number " << c++ << " contains " << n_comp << " war eagles." << endl;
  }

  return 0;
}
