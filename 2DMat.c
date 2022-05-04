#include <stdlib.h>
typedef struct
{
    int length;
    int rows;
    int cols;
    int end;
    bool major;
    double **mat;
} dMatrix;

void make_dMatrix(int rows, int cols, bool major, dMatrix &matrix)
{

    matrix.rows = rows;
    matrix.cols = cols;
    matrix.length = rows * cols;
    matrix.major = major;
    if (major)
    {
        // row major
        matrix.mat = (double **)malloc(rows * sizeof(double *));
        for (size_t i = 0; i < rows; i++)
            matrix.mat[i] = (double *)malloc(cols * sizeof(double));
    }
    else
    {
        // row major
        matrix.mat = (double **)malloc(cols * sizeof(double *));
        for (size_t i = 0; i < cols; i++)
            matrix.mat[i] = (double *)malloc(rows * sizeof(double));
    }

    matrix.end = matrix.length - 1;
};

int main()
{
    dMatrix dmat;
    make_dMatrix(5, 7, false, dmat);
}