#include <iostream>
#include <vector>
using namespace std;

int countSquareSubMatrices(vector<vector<int>>& matrix, int S) {
    int N = matrix.size(); // Size of the matrix
    int count = 0;

    // Iterate over all possible sizes of square sub-matrices
    for (int k = 1; k <= N; ++k) { // k is the size of the square
        // Traverse all top-left corners of k x k sub-matrices
        for (int i = 0; i <= N - k; ++i) {
            for (int j = 0; j <= N - k; ++j) {
                // Calculate the sum of the current k x k sub-matrix
                int sum = 0;
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        sum += matrix[i + x][j + y];
                    }
                }
                // Check if the sum equals S
                if (sum == S) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int N, S;
    cout << "Enter size of matrix (N): ";
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the target sum (S): ";
    cin >> S;

    int result = countSquareSubMatrices(matrix, S);
    cout << "Count of square sub-matrices with sum " << S << " is: " << result << endl;

    return 0;
}
