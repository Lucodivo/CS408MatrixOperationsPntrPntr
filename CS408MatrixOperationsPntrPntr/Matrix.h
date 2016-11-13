// acts as #ifndef
#pragma once

struct Matrix {
    double ** ptrPtr;
    int numRows;
    int numCols;
};

// matrix operation functions
void addMat(Matrix x, Matrix y, Matrix z);
void subMat(Matrix x, Matrix y, Matrix z);
void multMat(Matrix x, Matrix y, Matrix Z);

void zeroInitMat(Matrix &x);
void deleteMat(Matrix &x);

void printMat(Matrix x);