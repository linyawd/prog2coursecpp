#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix(size_t rows, size_t cols, T defaultValue = T()) : data(rows, std::vector<T>(cols, defaultValue)) {}

    size_t rows() const {
        return data.size();
    }

    size_t cols() const {
        return data.empty() ? 0 : data[0].size();
    }

    std::vector<T>& operator[](size_t row) {
        return data[row];
    }

    const std::vector<T>& operator[](size_t row) const {
        return data[row];
    }

 
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& elem : row) {
                os << elem << " ";
            }
            os << "\n";
        }
        return os;
    }


    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows() != other.rows() || cols() != other.cols()) {
            throw std::invalid_argument("Розміри матриць не збігаються");
        }

        Matrix<T> result(rows(), cols());
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                result[i][j] = data[i][j] + other[i][j];
            }
        }
        return result;
    }


    std::vector<T> operator*(const std::vector<T>& vec) const {
        if (cols() != vec.size()) {
            throw std::invalid_argument("Розмір вектора не відповідає кількості стовпців матриці");
        }

        std::vector<T> result(rows(), T());
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                result[i] += data[i][j] * vec[j];
            }
        }
        return result;
    }


    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols() != other.rows()) {
            throw std::invalid_argument("Кількість стовпців першої матриці не відповідає кількості рядків другої");
        }

        Matrix<T> result(rows(), other.cols());
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = 0; j < other.cols(); ++j) {
                for (size_t k = 0; k < cols(); ++k) {
                    result[i][j] += data[i][k] * other[k][j];
                }
            }
        }
        return result;
    }
};


int main() {

    Matrix<int> mat1(2, 3, 1);
    Matrix<int> mat2(2, 3, 2);

    Matrix<int> sum = mat1 + mat2;
    std::cout << "Сума матриць:\n" << sum << "\n";

    std::vector<int> vec = {1, 2, 3};
    std::vector<int> productVec = mat1 * vec;
    std::cout << "Множення матриці на вектор:\n";
    for (int val : productVec) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    Matrix<int> mat3(3, 2, 1);
    Matrix<int> productMat = mat1 * mat3;
    std::cout << "Множення матриць:\n" << productMat;


    Matrix<float> matFloat(2, 2, 1.5f);
    Matrix<float> matFloatSum = matFloat + matFloat;
    std::cout << "Сума матриць (float):\n" << matFloatSum;

    return 0;
}
