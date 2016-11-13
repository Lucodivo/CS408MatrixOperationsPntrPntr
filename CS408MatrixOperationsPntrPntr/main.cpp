#include <iostream>
#include "Matrix.h"

void printCommands();
void printTwoMatrices(Matrix m1, Matrix m2);
void printResults(Matrix m1, Matrix m2, Matrix m3);
void getMatricesFromUser(Matrix &m1, Matrix &m2); 
void getMatrixFromUser(Matrix &m);

/**
* @brief    Performs 2D array matrix operations and displays their results
* @author   Connor A. Haskins
* @date	11/11/2016
*/
int main() {
    // create and fill two matrices
    Matrix m1;
    m1.numCols = 5;
    m1.numRows = 5;
    m1.ptrPtr = new double * [m1.numRows];
    m1.ptrPtr[0] = new double [m1.numCols] { 1.0, 2.0, 3.0, 4.0, 5.0 };
    m1.ptrPtr[1] = new double [m1.numCols] { 2.0, 2.0, 2.0, 2.0, 2.0 };
    m1.ptrPtr[2] = new double [m1.numCols] { 3.0, 1.0, 1.0, 1.0, 3.0 };
    m1.ptrPtr[3] = new double [m1.numCols] { 0.0, 0.0, 2.0, 3.0, 2.0 };
    m1.ptrPtr[4] = new double [m1.numCols] { 4.0, 4.0, 4.0, 0.0, 0.0 };

    Matrix m2;
    m2.numCols = m1.numCols;
    m2.numRows = m1.numRows;
    m2.ptrPtr = new double * [m2.numRows];
    m2.ptrPtr[0] = new double [m2.numCols] { 1.0, 0.0, 0.0, 0.0, 0.0 };
    m2.ptrPtr[1] = new double [m2.numCols] { 1.0, 2.0, 1.0, 2.0, 1.0 };
    m2.ptrPtr[2] = new double [m2.numCols] { 0.0, 0.0, 1.0, 0.0, 0.0 };
    m2.ptrPtr[3] = new double [m2.numCols] { 1.0, 1.0, 1.0, 1.0, 1.0 };
    m2.ptrPtr[4] = new double [m2.numCols] { 2.0, 2.0, 2.0, 2.0, 2.0 };

    Matrix m3;
    m3.numCols = m2.numCols;
    m3.numRows = m1.numRows;
    zeroInitMat(m3);

    printTwoMatrices(m1, m2);
    printCommands();

    char choice;
    std::cin >> choice;

    // while the user enters a given command, continue the program
    while (choice > '0' && choice < '5') {
        switch (choice)
        {
        case '1':
            if (sameDimensions(m1,m2)) {
                addMat(m1, m2, m3);

                std::cout << "(1) M4 = M1 + M2 \n";
                printResults(m1, m2, m3);
            }
            else {
                std::cout << "Matrices do not have the same dimensions \n";
            }
            break;
        case '2':
            if (sameDimensions(m1, m2)) {
                subMat(m1, m2, m3);

                std::cout << "(2) M4 = M1 - M2 \n";
                printResults(m1, m2, m3);
            }
            else {
                std::cout << "Matrices do not have the same dimensions \n";
            }
            break;
        case '3':
            if (sameInnerDimensions(m1, m2)) {
                multMat(m1, m2, m3);

                std::cout << "(3) M5 = M1 * M2 \n";
                printResults(m1, m2, m3);
            }
            else {
                std::cout << "Matrices do not have the same inner dimensions \n";
            }
            break;
        case '4':
            getMatricesFromUser(m1, m2);
            // deallocate all memory
            deleteMat(m3);
            // adjust the size of the array appropriately
            m3.numRows = m1.numRows;
            m3.numCols = m2.numCols;
            // initiailze the values in the new array to zero
            zeroInitMat(m3);
            // print the new matrices
            printTwoMatrices(m1, m2);
            break;
        default:
            break;
        }
        printCommands();
        std::cin >> choice;
    }

    return 0;
}

/**
 * @brief   Gets two matrices from user input
 * @param   m1  To store the first Matrix
 * @param   m2  To store the second Matrix
 */
void getMatricesFromUser(Matrix &m1, Matrix &m2) {
    deleteMat(m1);

    std::cout << "You are now replacing the first matrix... \n";
    std::cout << "How many rows in the first matrix? \n";
    std::cin >> m1.numRows;
    std::cout << "How many columns in the second matrix? \n";
    std::cin >> m1.numCols;

    getMatrixFromUser(m1);

    deleteMat(m2);

    std::cout << "You are now replacing the second matrix... \n";
    std::cout << "How many rows in the second matrix? \n";
    std::cin >> m2.numRows;
    std::cout << "How many columns in the second matrix? \n";
    std::cin >> m2.numCols;

    getMatrixFromUser(m2);
}

/**
 * @brief   Gets a matrix from user input
 * @param [in,out]  m   Where to store the Matrix
 */
void getMatrixFromUser(Matrix &m) {
    m.ptrPtr = new double * [m.numRows];
    for (int i = 0; i < m.numRows; i++) {
        m.ptrPtr[i] = new double[m.numCols];
        std::cout << "Input row " << i << ":" << "\n";
        for (int j = 0; j < m.numCols; j++) {
            std::cin >> m.ptrPtr[i][j];
        }
    }
}

/**
* @brief   Display the user's options
*/
void printCommands() {
    std::cout << "(1) M3 = M1 + M2 \n";
    std::cout << "(2) M4 = M1 - M2 \n";
    std::cout << "(3) M5 = M1 * M2 \n";
    std::cout << "(4) Input new M1 & M2 matrix dimensions and values \n";
    std::cout << "Enter the one of the following commands. \n";
    std::cout << "Or any other key to terminate. \n";
    std::cout << "\n";
}

/**
* @brief   Print two matrices.
*
* @param   m1[NUM_ROWS][NUM_COLS]
* @param   m2[NUM_ROWS][NUM_COLS]
*/
void printTwoMatrices(Matrix m1, Matrix m2) {
    std::cout << "===============Matrix 1===============\n";
    printMat(m1);
    std::cout << "===============Matrix 2===============\n";
    printMat(m2);
    std::cout << "\n";
}


/**
* @brief   Print two matrices and their result matrix.
*
* @param   m1[NUM_ROWS][NUM_COLS]
* @param   m2[NUM_ROWS][NUM_COLS]
* @param   m3[NUM_ROWS][NUM_COLS]
*/
void printResults(Matrix m1, Matrix m2, Matrix m3) {
    printTwoMatrices(m1, m2);
    std::cout << "================Result================\n";
    printMat(m3);
    std::cout << "\n\n";
}