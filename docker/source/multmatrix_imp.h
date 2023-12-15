#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#include"utils.h"
#include"operaciones.h"
#include"multmatrix.h"
#define MSG_OK 1
#define MSG_NOK 0

class Multmatrix_imp{
    private:
    int clientId=-1;
    multMatrix* p=nullptr;
    public:
    Multmatrix_imp(int clientId): clientId(clientId){};

    bool connectionClosed(){
        return p==nullptr;
    }

    void recibeOp(){
        
        std::vector<unsigned char> rpcIn;
        std::vector<unsigned char> rpcOut;
        //recibe operacion
        recvMSG(clientId,rpcIn);

        MultmatrixOp operacion=unpack<MultmatrixOp>(rpcIn);
        //ejecuta
        switch(operacion){
            case constructorOP:{
                p=new multMatrix();
                pack(rpcOut,(unsigned char)MSG_OK);
            }
            break;
            case destructorOP:{
                delete p;
                p=nullptr;
                pack(rpcOut,(unsigned char)MSG_OK);
            }
            break;

            case readMatrixOp:{
                std::cout << "readMatrix-Function-INICIO" << std::endl;
                std::string dato;
                int datolength = unpack<int>(rpcIn);
                dato.resize(datolength);
                std::cout << "readMatrix-Function-MID" << std::endl;
                unpackv(rpcIn, (char*)dato.data(),datolength);

                //creo nueva matrix  //llamamos a la funcion
                matrix_t* matrix = p->readMatrix(dato.c_str());
                std::cout << "readMatrix-Function-MID 2" << std::endl;
                // enviar matriz filas columnas y data
                pack(rpcOut, matrix->rows);
                pack(rpcOut, matrix->cols);
                packv(rpcOut, matrix->data, matrix->rows * matrix->cols);
                
                
                  std::cout << "readMatrix-Function-MID 3" << std::endl;  
                //envio de respuesta ok
                pack(rpcOut,(unsigned char)MSG_OK);
                //sendMSG(clientId, rpcOut);
                // liberar memoria de matrix
                delete[] matrix->data;
                delete matrix;
                std::cout << "readMatrix-Function-OK" << std::endl;

            }
            break;
            case multMatricesOp:{
              std::cout << "MULTmatrix-Function-INICIO" << std::endl;

                
                //creamos dos matrices para multiplicar
                matrix_t* m1 = new matrix_t();
                matrix_t* m2 = new matrix_t();

                // desempaquetar matrices
                //desempaqueta matriz1
                m1->rows = unpack<int>(rpcIn);
                m1->cols = unpack<int>(rpcIn);
                m1->data = new int[m1->rows * m1->cols];
                unpackv(rpcIn, m1->data, m1->rows * m1->cols);
                 //desempaqueta matriz2
                m2->rows = unpack<int>(rpcIn);
                m2->cols = unpack<int>(rpcIn);
                m2->data = new int[m2->rows * m2->cols];
                unpackv(rpcIn, m2->data, m2->rows * m2->cols);

                //creamos la matriz resultante con la llamada a la funcion de multiplicarmatriz
                matrix_t* result = p->multMatrices(m1, m2);
                //mensjae envio ok
                pack(rpcOut,(unsigned char)MSG_OK);
                // enviar matriz resultado
                pack(rpcOut, result->rows);
                pack(rpcOut, result->cols);
                packv(rpcOut, result->data, result->rows * result->cols);
                
                
                // enviar resultado ya lo enviamos al final del switch
                //sendMSG(clientId, rpcOut);
                
                // liberar memoria de las matrices
                delete[] m1->data; 
                delete[] m2->data;
                delete m1;
                delete m2;
                delete[] result->data;
                delete result;
                std::cout << "MULTmatrix-Function-OK" << std::endl;

                
            }
            break;
            case writeMatrixOp:{
                std::cout << "WriteMatrix-Function-INICIO" << std::endl;
                //desempaquetar la matriz... filas , columnas, dataa
                matrix_t *mmatrix= new matrix_t(); 
                mmatrix->rows=unpack<int>(rpcIn);
                mmatrix->cols=unpack<int>(rpcIn);
                mmatrix->data= new int[mmatrix->rows * mmatrix->cols];
                //desempaquetar ruta del archivo
                unpackv(rpcIn, mmatrix->data, mmatrix->rows * mmatrix->cols );
                // desempaquetar ruta del archivo
                int datolength = unpack<int>(rpcIn);
                std::string dato;
                dato.resize(datolength);
                //pack(rpcOut,datolength);
                unpackv(rpcIn, (char*)dato.data(),datolength);
                 std::cout << "WriteMatrix-Function-IMEDIO" << std::endl;
                //llamar a la funcion
                p->writeMatrix(mmatrix,dato.c_str());
                //envio de respuesta ok
                std::cout << "WriteMatrix-Function-IMEDIO 2" << std::endl;
                pack(rpcOut,(unsigned char)MSG_OK);
                // enviar resultado al cliente
                //sendMSG(clientId, rpcOut);
                
                // liberar memoria
                delete[] mmatrix->data;
                delete mmatrix;
                std::cout << "WriteMatrix-Function-OK" << std::endl;

            }
            break;
            case createIdentityOp:{
                std::cout << "createIdentity-Function-INICIO" << std::endl;

                //desempaqutamos la entrada de datos de filas y columnas
                int rows = unpack<int>(rpcIn);
                int cols = unpack<int>(rpcIn);

                
                //puntero de matriz identidad para llamar a la funcion de crear identidad
                matrix_t* identity = p->createIdentity(rows, cols);
                 //envio de respuesta ok
                pack(rpcOut,(unsigned char)MSG_OK);
                // pack de matriz identidad filas columnas data
                pack(rpcOut, identity->rows);
                pack(rpcOut, identity->cols);
                packv(rpcOut, identity->data, identity->rows * identity->cols);
                
                
                // enviar resultado no hay que enviarlo porque se envia al final del switch
                //sendMSG(clientId, rpcOut);
                
                // liberamos memoria
                delete[] identity->data;
                delete identity;
                std::cout << "createIdentity-Function-OK" << std::endl;

            }
            break;
            case createRandMatrixOp:{
                std::cout << "createRandMatrixop-Function-INICIO" << std::endl;
                //desempaqutamos la entrada de datos de filas y columnas
                int rows = unpack<int>(rpcIn);
                int cols = unpack<int>(rpcIn);
                //puntero de matriz random para llamar a la funcion de crear matriz random
                matrix_t* randMatrix = p->createRandMatrix(rows, cols);
                //envio de respuesta ok
                pack(rpcOut,(unsigned char)MSG_OK);

                // pack de matriz aleatoria filas columnas y data
                pack(rpcOut, randMatrix->rows);
                pack(rpcOut, randMatrix->cols);
                packv(rpcOut, randMatrix->data, randMatrix->rows * randMatrix->cols);
                
              
                // liberar memoria
                delete[] randMatrix->data;
                delete randMatrix;
                 std::cout << "createRandMatrixop-Function-OK" << std::endl;
            }
            break;
            default:
            {
                std::cout<<"Error: función no definida\n";
				pack(rpcOut,(unsigned char)MSG_NOK);

 
            }break;

        };
        //devuelve resultados
        sendMSG(clientId,rpcOut);
    }


};
