#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    // Constructor to initialize the matrix with given dimensions
    Matrix(int m, int n) : rows(m), cols(n), data(m, vector<double>(n, 0)) {}

    // Function to input matrix values
    void input() {
        cout << "Enter values for a " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    // Overload the * operator to multiply two matrices
    Matrix operator*(const Matrix &other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to print the matrix
    void print() const {
        cout << "Matrix (" << rows << "x" << cols << "):" << endl;
        for (const auto &row : data) {
            for (double val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> m >> n;

    Matrix matA(m, n), matB(n, m), matC(m, m);

    cout << "Input for Matrix A:" << endl;
    matA.input();
    cout << "Input for Matrix B:" << endl;
    matB.input();

    try {
        matC = matA * matB;
        cout << "Matrix A:" << endl;
        matA.print();
        cout << "Matrix B:" << endl;
        matB.print();
        cout << "Matrix C (A * B):" << endl;
        matC.print();
    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
