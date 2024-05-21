#include <iostream>
#include <vector>

using namespace std;
/*
12. Определить АТД Матрица, обеспечивающий метод [i,j] для доступа к элементам матрицы. В конструкторе задаются размеры матрицы.
Определить операцию *. Выполнить возведение матрицы N×N из целых чисел 0 и 1 в степень K по модулю 2: A^K (mod2).
Для возведения матрицы в степень использовать метод уменьшения размера задачи в 2 раза.
*/
template <typename T>
class Matrix {
    int n, m;
    vector<vector<T>> matrix;
public:
    Matrix(int n, int m) : n(n), m(m), matrix(n) {
        for (int i = 0; i < n; i++) matrix[i].resize(m);
    }
    friend Matrix operator*(const Matrix &a, const Matrix &b);
    T operator()(int i, int j) const { return matrix[i][j]; }

    void Add(int i, int j, int v) { matrix[i][j] = v;}
};

int main()
{
    Matrix<int> mat = Matrix<int>{3,3};
    
    mat.Add(1, 1, 10);

    cout << mat(1, 1) << endl;
}