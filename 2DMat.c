#include <stdlib.h>
#include <stdio.h>

enum MAJOR{
    ROW = 1,
    COL = 0
};

enum TYPE{
    INT,
    FLOAT,
    DOUBLE
};

typedef struct{
    int length;
    int rows;
    int cols;
    int end;
    enum TYPE type;
    enum MAJOR major;
    int **mat;
} intMatrix;

typedef struct{
    int length;
    int rows;
    int cols;
    int end;
    enum TYPE type;
    enum MAJOR major;
    float **mat;
} floatMatrix;

typedef struct{
    int length;
    int rows;
    int cols;
    int end;
    enum TYPE type;
    enum MAJOR major;
    double **mat;
} doubleMatrix;

typedef struct{
    int length;
    int rows;
    int cols;
    int end;
    enum TYPE type;
    enum MAJOR major;
    void **mat;
} voidMatrix;

void** make_Matrix(const int rows, const int cols, const enum TYPE type, const enum MAJOR major){
    void **tMat;
    unsigned long tSize, pSize;
    
    if(major == ROW){
        //Row Major
        switch (type){
            case INT:
                tSize = cols*sizeof(int); pSize = rows*sizeof(int*);
                break;
            case FLOAT:
                tSize = cols*sizeof(float); pSize = rows*sizeof(float*);
                break;
            case DOUBLE:
                tSize = cols*sizeof(double); pSize = rows*sizeof(double*);
                break;
        }
        tMat = (void **)malloc(pSize);
        for (size_t i = 0; i < rows; i++)
            tMat[i] = malloc(tSize);

        return tMat;
    }
    //Column Major
    switch (type){
            case INT:
                tSize = rows*sizeof(int); pSize = cols*sizeof(int*);
                break;
            case FLOAT:
                tSize = rows*sizeof(float); pSize = cols*sizeof(float*);
                break;
            case DOUBLE:
                tSize = rows*sizeof(double); pSize = cols*sizeof(double*);
                break;
        }
        tMat = (void **)malloc(pSize);
        for (size_t i = 0; i < cols; i++)
            tMat[i] = malloc(tSize);

    return tMat;
};

voidMatrix* make_2DMatrix(const int rows, const int cols, const enum TYPE type, const enum MAJOR major)
{
    voidMatrix* matrix = (voidMatrix*)malloc(sizeof(voidMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->length = rows * cols;
    matrix->type = type;
    matrix->major = major;
    matrix->end = matrix->length - 1;
    matrix->mat = make_Matrix(rows, cols, type, major);
    
    return matrix;
};

int main()
{
    
    doubleMatrix* im = (doubleMatrix*)make_2DMatrix(5, 7, DOUBLE, ROW);
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 7; i++)
            im->mat[j][i] = j*7+i;
    }

    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 7; i++)
            printf("%f ", im->mat[j][i]);
        printf("\n");
    }
    return 0;
    
}
