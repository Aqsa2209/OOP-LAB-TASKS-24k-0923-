#include <iostream>

using namespace std;

class Matrix {
private:
    double** data;
    int rows;
    int cols;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        if (r < 0 || c < 0) {
            throw invalid_argument("Rows and columns must be non-negative.");
        }
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols]{0};
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix(Matrix&& other) noexcept : data(other.data), rows(other.rows), cols(other.cols) {
        other.data = nullptr;
        other.rows = 0;
        other.cols = 0;
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    double& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Index out of range.");
        }
        return data[r][c];
    }

    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.at(j, i) = data[i][j];
            }
        }
        return transposed;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    Matrix matrix(rows, cols);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix.at(i, j);
        }
    }

    cout << "Original Matrix:" << endl;
    matrix.print();

    Matrix transposed = matrix.transpose();
    cout << "Transposed Matrix:" << endl;
    transposed.print();

    return 0;
}

