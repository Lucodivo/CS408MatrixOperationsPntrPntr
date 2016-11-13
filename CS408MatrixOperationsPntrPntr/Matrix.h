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

// allocation/deallocation functions
void zeroInitMat(Matrix &x);
void deleteMat(Matrix &x);

// helper functions for user of Matrix struct
bool sameDimensions(const Matrix &m1, const Matrix &m2);
bool sameInnerDimensions(const Matrix &m1, const Matrix &m2);
void printMat(const Matrix &x);