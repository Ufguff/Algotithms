#include <iostream>
#include <map>

using namespace std;

/*
Определить АТД Разреженная матрица, обеспечивающий метод get(i,j) для получения элемента матрицы и set(i,j,v) 
для изменения (добавления) ненулевого элемента. В конструкторе задаются размеры матрицы.
Реализовать АТД через словарь по ключам map<pair<int,int>, double>. Определить эффективность операций + и * в зависимости 
от количества ненулевых элементов K.
*/

class SparseMatrix
{
    map<pair<int, int>, double> matrix;
    int n, m;
public:
    SparseMatrix(int n, int m): n(n), m(m) {}

    double get(int i, int j)    // exception ???
    {
        if (!(i < 0 && j < 0) && i < n && j < m)
            return matrix[make_pair(i, j)];
        /*
        else
            throw exception("not valid coor");
        */

    }

    void set(int i, int j, double v)    // exception ???
    {
        if (!(i < 0 && j < 0) && i < n && j < m)
            matrix[make_pair(i, j)] = v;
        /*
        else
            throw exception("not valid coor");
        */
    }
// K1 - кол-во ненулевых в первой матрице
// K2 - кол-во ненулевых во второй матрице
    SparseMatrix operator+(SparseMatrix a)  // эффективность K1 + K2
    {
        if (a.n == n && a.m == m)
        {
            SparseMatrix result(n, m);
            for (auto& [pair, v] : matrix)
                result.matrix[make_pair(pair.first, pair.second)] += v;

            for (auto& [pair, v] : a.matrix)
                result.matrix[make_pair(pair.first, pair.second)] += v;

            return result;
        }
    }

    SparseMatrix operator*(SparseMatrix a)
    {
        if (m == a.n)
        {
            SparseMatrix result(n, a.m);
            for(int i = 0; i < n; i++)
            {
                

            } 
        }
    }

    //debug
    void Print()
    {
        for (auto& [pair, v] : matrix)
            cout << pair.first << " " << pair.second << " - " << v << endl; 
    }
};

int main()
{
    int n = 2, m = 3;
    SparseMatrix mat(n, m);

    for (int i = 0; i < n; i++)
        mat.set(i, 0, i + 1);

    mat.Print();

    cout << mat.get(0, 1) << endl;
    //cout << mat.get(10, 10) << endl;

    SparseMatrix mat2(n, m);

    for (int i = 0; i < m; i++)
        mat2.set(0, i, i + 1);
    mat2.Print();
    cout << "-----------------------" << endl;


    SparseMatrix resSum = mat + mat2;

    resSum.Print();
    return 0;
}