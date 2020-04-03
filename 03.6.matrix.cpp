#include <iostream>
using namespace std;

class matrix
{
private:
    int row;
    int column;
    int ** elem;
public:
    matrix(int r = 1, int c = 1);
    void getrow(int r);
    void getmatrix();
    int operator()(int i, int j);
    matrix operator=(const matrix & m);
    matrix operator+(matrix & m) const;
    matrix operator-(matrix & m) const;
    matrix operator*(matrix & m) const;
};

matrix::matrix(int r, int c)
{
    row = r;
    column = c;
    elem = new int *[row];
    for (int i = 0; i < row; i++)
        elem[i] = new int [column];
}

void matrix::getrow(int r)
{
    for (int i = 0; i < column; i++)
    {
        cin >> elem[r][i];
    }
}

void matrix::getmatrix()
{
    for (int i = 0; i < row; i++)
        this->getrow(i);
}

int matrix::operator()(int i, int j)
{
    return elem[i][j];
}

matrix matrix::operator=(const matrix & m)
{
    for (int i = 0; i < row; i++)
    {
        delete [] elem[i];
    }
    delete [] elem;

    row = m.row;
    column = m.column;
    elem = new int *[row];
    for (int i = 0; i < row; i++)
        elem[i] = new int [column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            elem[i][j] = m.elem[i][j];
        }
    }

    return *this;
}

matrix matrix::operator+(matrix & m) const
{
    matrix sum(row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            sum.elem[i][j] = elem[i][j] + m.elem[i][j];
        }
    }

    return sum;
}

matrix matrix::operator-(matrix & m) const
{
    matrix dif(row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            dif.elem[i][j] = elem[i][j] - m.elem[i][j];
        }
    }

    return dif;
}

matrix matrix::operator*(matrix & m) const
{
    matrix pro(row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            pro.elem[i][j] = elem[i][j] * m.elem[i][j];
        }
    }

    return pro;
}

int main()
{
    int row, column;
    cin >> row >> column;

    matrix m1(row, column);
    matrix m2(row, column);
    matrix res;

    m1.getmatrix();
    m2.getmatrix();

    res = m1 + m2;
    cout << "c=a+b" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << res(i, j) << " ";
        }
        cout << endl;
    }

    res = m1 - m2;
    cout << "c=a-b" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << res(i, j) << " ";
        }
        cout << endl;
    }

    res = m1 * m2;
    cout << "c=a*b" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << res(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}