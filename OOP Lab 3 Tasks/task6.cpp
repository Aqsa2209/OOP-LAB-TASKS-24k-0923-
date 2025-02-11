#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> elements;

public:
    Matrix(int r, int c) : rows(r), cols(c), elements(r, vector<int>(c, 0)) {}
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        } else {
            cerr << "Index out of bounds" << endl;
        }
    }
    Matrix add(const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrices cannot be added" << endl;
            return Matrix(0, 0); 
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, elements[i][j] + other.elements[i][j]);
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other) {
        if (cols != other.rows) {
            cerr << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0); 
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += elements[i][k] * other.elements[k][j];
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << elements[i][j] << " ";
            }
            cout << endl; 
        }
    }
};

int main(int argc, char *argv[]) {
    if (argc < 6) {
        cerr << "Please provide dimensions and elements for two matrices." << endl;
        return 1;
    }

    int rows1 = atoi(argv[1]);
    int cols1 = atoi(argv[2]);
    Matrix matrix1(rows1, cols1);

    int index = 3;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            matrix1.setElement(i, j, atoi(argv[index++]));
        }
    }

    int rows2 = atoi(argv[index++]);
    int cols2 = atoi(argv[index++]);
    Matrix matrix2(rows2, cols2);

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            matrix2.setElement(i, j, atoi(argv[index++]));
        }
    }
    cout << "Matrix 1:" << endl;
    matrix1.print();
    cout << "Matrix 2:" << endl;
    matrix2.print();

    cout << "Addition Result:" << endl;
    Matrix additionResult = matrix1.add(matrix2);
    additionResult.print();

    cout << "Multiplication Result:" << endl;
    Matrix multiplicationResult = matrix1.multiply(matrix2);
    multiplicationResult.print();

    return 0;
}
