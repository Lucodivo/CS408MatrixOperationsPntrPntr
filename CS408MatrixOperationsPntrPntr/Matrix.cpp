#include <iostream>
#include "Matrix.h"

/**
* @brief    Adds the first two matrices and stores the values in the third matrix
* @param    X	Matrix #1 (addend)
* @param    Y	Matrix #2 (addend)
* @param    Z	The location of the summation of the two matrices
*/
void addMat(Matrix x, Matrix y, Matrix z) {
    for (int i = 0; i < x.numRows; i++) {
        for (int j = 0; j < x.numCols; j++) {
            z.ptrPtr[i][j] = x.ptrPtr[i][j] + y.ptrPtr[i][j];
        }
    }
}

/**
* @brief    Subtracts the second matrix from the first matrix and stores the values in the third matrix.
* @param    X	Matrix #1 (minuend)
* @param    Y	Matrix #2 (subtrahend)
* @param    Z	The location of the difference of the two matrices
*/
void subMat(Matrix x, Matrix y, Matrix z) {
    for (int i = 0; i < x.numRows; i++) {
        for (int j = 0; j < x.numCols; j++) {
            z.ptrPtr[i][j] = x.ptrPtr[i][j] - y.ptrPtr[i][j];
        }
    }
}

/**
* @brief    Performs matrix multiplication on the two matrices and stores the values in the third matrix
*           (DOES NOT SIMPLY MULTIPLY CORRESPONDING INDEXES)
* @param    X	Matrix #1 (multiplicand)
* @param    Y	Matrix #2 (multiplier)
* @param    Z	The location of the product of the two matrices
*/
void multMat(Matrix x, Matrix y, Matrix z) {
    for (int i = 0; i < x.numRows; i++) {
        for (int j = 0; j < y.numCols; j++) {
            z.ptrPtr[i][j] = 0;
            for (int k = 0; k < y.numRows; k++) {
                z.ptrPtr[i][j] += x.ptrPtr[i][k] * y.ptrPtr[k][j];
            }
        }
    }
}

/**
 * @fn  deleting allocated memory from Matrix
 * @param   [in,out]X   
 */
void deleteMat(Matrix &x) {
    for (int i = 0; i < x.numRows; i++) {
        delete [] x.ptrPtr[i];
    }
    delete [] x.ptrPtr;
    x.ptrPtr = NULL;
}

/**
 * @brief   Returns true if the matrices have the same dimensions, used for add/sub
 * @param   m1  
 * @param   m2  
 * @return  
 */
bool sameDimensions(const Matrix & m1, const Matrix & m2)
{
    return (m1.numRows == m2.numRows && m1.numCols == m2.numCols);
}

/**
 * @brief   Returns true if the matrices have the same inner dimensions, used for mult
 * @param   m1  
 * @param   m2  
 * @return  
 */
bool sameInnerDimensions(const Matrix & m1, const Matrix & m2)
{
    return  (m1.numCols == m2.numRows);
}

/**
 * @brief   Initialize the matrix to zero
 * @param   [in,out]X   Matrix to be initialized
 */
void zeroInitMat(Matrix &x) {
    x.ptrPtr = new double *[x.numRows];
    for (int i = 0; i < x.numRows; i++) {
        x.ptrPtr[i] = new double[x.numCols];
        for (int j = 0; j < x.numCols; j++) {
            x.ptrPtr[i][j] = 0;
        }
    }
}

/**
* @brief    Prints a matrix to console
* @param    X
*/
void printMat(const Matrix &x) {
    for (int i = 0; i < x.numRows; i++) {
        for (int j = 0; j < x.numCols; j++) {
            std::cout << x.ptrPtr[i][j] << "\t";
        }
        std::cout << "\n";
    }
}