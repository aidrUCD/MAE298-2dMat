#include <stdlib.h>
#include <stdio.h>

//Enumeration for matrix major type
enum MAJOR{
    ROW = 1,
    COL = 0
};

//Enum for matrix type
enum TYPE{
    INT,
    FLOAT,
    DOUBLE
};

//matrix of integers
typedef struct{
    int length;
    int rows;
    int cols;
    enum TYPE type;
    enum MAJOR major;
    int **mat;
} intMatrix;

//matrix of floats
typedef struct{
    int length;
    int rows;
    int cols;
    enum TYPE type;
    enum MAJOR major;
    float **mat;
} floatMatrix;

//matrix of doubles
typedef struct{
    int length;
    int rows;
    int cols;
    enum TYPE type;
    enum MAJOR major;
    double **mat;
} doubleMatrix;

//void matrix for generic functionality
typedef struct{
    int length;
    int rows;
    int cols;
    enum TYPE type;
    enum MAJOR major;
    void **mat;
} voidMatrix;

//generic function for creating 2d matrix
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
            default:
                printf("\n!!!WRONG TYPE!!!\n\n"); exit(-1);
                break;
        }
        tMat = (void **)malloc(pSize);
        for (size_t i = 0; i < rows; i++)
            tMat[i] = malloc(tSize);

        return tMat;
    }else if(major == COL){
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
                default:
                    printf("\n!!!WRONG TYPE!!!\n\n"); exit(-1);
                    break;
            }
            tMat = (void **)malloc(pSize);
            for (size_t i = 0; i < cols; i++)
                tMat[i] = malloc(tSize);

        return tMat;
    }else{
        printf("\n!!!Wrong major!!!\n\n");
        exit(-1);
    }
};


//generic function for creating 2DMatrix object
voidMatrix* make_2DMatrix(const int rows, const int cols, const enum TYPE type, const enum MAJOR major)
{
    voidMatrix* matrix = (voidMatrix*)malloc(sizeof(voidMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->length = rows * cols;
    matrix->type = type;
    matrix->major = major;
    matrix->mat = make_Matrix(rows, cols, type, major);
    
    return matrix;
};

int main()
{
    
    floatMatrix* im = (floatMatrix*)make_2DMatrix(5, 7, DOUBLE, ROW);
    for(int j = 0; j < im->rows; j++){
        for(int i = 0; i < im->cols; i++)
            im->mat[j][i] = j*im->cols+i;
    }

    for(int j = 0; j < im->rows; j++){
        for(int i = 0; i < im->cols; i++)
            printf("%.0f ", im->mat[j][i]);
        printf("\n");
    }
    return 0;
    
}
