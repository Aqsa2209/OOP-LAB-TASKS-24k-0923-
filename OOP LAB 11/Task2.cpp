#include <iostream>
#include <stdexcept>

using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException: Matrix dimensions do not match for the operation.";
    }
};

template<typename T>
class Matrix {
private:
    size_t rows, cols;
    T** data;

    void allocateMemory() {
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i)
            data[i] = new T[cols]();
    }

    void deallocateMemory() {
        for (size_t i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void copyDataFrom(const Matrix<T>& other) {
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        allocateMemory();
    }

    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        copyDataFrom(other);
    }

    Matrix& operator=(const Matrix<T>& other) {
        if (this == &other) return *this;
        deallocateMemory();
        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        copyDataFrom(other);
        return *this;
    }

    ~Matrix() {
        deallocateMemory();
    }

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols)
            throw out_of_range("Matrix access out of bounds.");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols)
            throw out_of_range("Matrix access out of bounds.");
        return data[r][c];
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();

        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];

        return result;
    }

    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

// Example usage
int main() {
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A.at(0, 0) = 1; A.at(0, 1) = 2;
    A.at(1, 0) = 3; A.at(1, 1) = 4;

    B.at(0, 0) = 5; B.at(0, 1) = 6;
    B.at(1, 0) = 7; B.at(1, 1) = 8;

    try {
        Matrix<int> C = A + B;
        cout << "A + B =\n";
        C.display();

        Matrix<int> D = A * B;
        cout << "A * B =\n";
        D.display();
    } catch (const DimensionMismatchException& e) {
        cout << e.what() << endl;
    }

    return 0;
}

