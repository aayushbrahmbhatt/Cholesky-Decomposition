#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
int L[100][100];
void Cholesky_decomp(int mat[][MAX], int size) {
    //For Understanding the algorithm better please reffer to our project report
    memset(L, 0, sizeof(L));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            int sum = 0;
            if (j == i)
            {
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(mat[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (L[i][k] * L[j][k]);
                L[i][j] = (mat[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int mat[n][MAX];
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Cholesky_decomp(mat, n);
    //Printing L matrix
    cout << "'L' Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    //Printing transpose of L matrix
    cout << endl;
    cout << "Transpose of 'L' Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << L[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
