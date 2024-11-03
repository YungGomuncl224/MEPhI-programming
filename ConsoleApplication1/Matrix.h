#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
#include <iostream>
const double eps = 1e-9;

class matrix
{
private:
    double** a;
    int n, m;
public:
    // матрица без элементов
    matrix()
    {
        a = 0;
        n = 0;
        m = 0;
    }

    int N()
    {
        return n;
    }
    int M()
    {
        return m;
    }
    double* operator [] (int index)
    {
        return getRow(index);
    }

    // получить строку матрицы
    double* getRow(int index)
    {
        if (index >= 0 && index < n)
            return a[index];
        return 0;
    }


    // матрица NxM, если E, то единичная, иначе нулевая
    matrix(int N, int M, bool E = 0)
    {
        n = N;
        m = M;
        a = new double* [n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = new double[m];
            for (int j = 0; j < m; ++j)
                a[i][j] = (i == j) * E;
        }
    }

    // вывести матрицу на консоль
    void printMatrix(matrix& a)
    {
        for (int i = 0; i < a.N(); ++i)
        {
            for (int j = 0; j < a.M(); ++j)
                printf("%5.3lf ", a[i][j]);
            puts("");
        }
    }
};
#endif