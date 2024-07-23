#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        // Upper Triangular Matrix U
        for (int k = i; k < n; ++k) {
            double sum = 0;
            for (int j = 0; j < i; ++j)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular Matrix L
        for (int k = i; k < n; ++k) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; ++j)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

void printMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << setw(10) << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<double>> A = {
        {4, 3, 0},
        {3, 7, -1},
        {0, -1, 4}
    };

    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    luDecomposition(A, L, U);

    cout << "Lower Triangular Matrix L:" << endl;
    printMatrix(L);

    cout << "Upper Triangular Matrix U:" << endl;
    printMatrix(U);

    return 0;
}