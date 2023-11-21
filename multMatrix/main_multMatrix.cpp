#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "multmatrix.h"
#include "multmatrix_stub.h"
#include "operaciones.h"





void freeMatrix(matrix_t* m){
    delete[] m->data;
    delete[] m;

}
int main()
{
    //multMatrix* mmatrix=new multMatrix();
    Multmatrix_stub* mmatrix=new Multmatrix_stub();

    std::cout << "CREAMATRIZ 1" << std::endl;
    matrix_t* m1= mmatrix->createRandMatrix(5,5);
    std::cout << "CREAMATRIZ 2" << std::endl;
    matrix_t* m2= mmatrix->createIdentity(5,5);
    std::cout << "MATRIZ Mult 1" << std::endl;
    matrix_t* mres=mmatrix->multMatrices(m1,m2);
    std::cout << "ESCRIBE" << std::endl;
    mmatrix->writeMatrix(mres,"resultado.txt");
    std::cout << "LLEERMATRIZ" << std::endl;
    matrix_t* m3=mmatrix->readMatrix("resultado.txt");
    std::cout << "MULTIPLICAMATRICES 2" << std::endl;
    matrix_t* mres2=mmatrix->multMatrices(m1,m3);
    std::cout << "ESCRIBE" << std::endl;
    mmatrix->writeMatrix(mres2,"resultado2.txt");



    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(mres);
    freeMatrix(m3);
    freeMatrix(mres2);
    delete mmatrix;
}
