
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>

#include"utils.h"
#include "operaciones.h"
#include"multmatrix.h"
#define MSG_OK 1
#define MSG_NOK 0


class Multmatrix_stub{
    private:
        std::string ip="172.31.51.35";
        int port=60000;
        connection_t serverConnection;
    public:
    Multmatrix_stub(){
    //conectar con server
    	//iniciar conexion
	serverConnection=initClient(ip,port);
    MultmatrixOp op=constructorOP;
    std::vector<unsigned char> rpcOut;
    std::vector<unsigned char> rpcIn;

    pack(rpcOut,op);

    sendMSG(serverConnection.serverId, rpcOut);
    recvMSG(serverConnection.serverId, rpcIn);

    if(rpcIn[0]!=MSG_OK){
        std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
    }

    }
    ~Multmatrix_stub(){
        //desconectar conexion
         MultmatrixOp op=destructorOP;
         std::vector<unsigned char> rpcOut;
         std::vector<unsigned char> rpcIn;

       pack(rpcOut,op);

         sendMSG(serverConnection.serverId, rpcOut);
         recvMSG(serverConnection.serverId, rpcIn);
          if(rpcIn[0]!=MSG_OK){
        std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
    }

        closeConnection(serverConnection.serverId);
    };

  
    matrix_t* readMatrix(const char* dato){
            std::cout << "readMatrix_STUB 1" << std::endl;
            MultmatrixOp op = readMatrixOp;
            std::vector<unsigned char> rpcOut;
            std::vector<unsigned char> rpcIn;

            // empaquetamos operacion
            pack(rpcOut, op);

            // pack de la ruta del archivo, *filename*
            //usamos strlen en porque es un const char* si fuese string usariamos length()
             //nombre ruta del archivo
            // empacar ruta del archivo
            std::cout << "readMatrix_STUB 2" << std::endl;
            int datolength= strlen(dato)+1;
            pack(rpcOut,datolength);  // enviar la longitud del dato
            packv(rpcOut, dato,datolength);  // +1 para incluir el carácter nulo
            std::cout << "readMatrix_STUB 3" << std::endl;
            // enviamos el mensaje
            sendMSG(serverConnection.serverId, rpcOut);
            std::cout << "readMatrix_STUB 4" << std::endl;
            // recibimos la matriz
            recvMSG(serverConnection.serverId, rpcIn);
           
          std::cout << "readMatrix_STUB 5" << std::endl;
            // desempaquetamos matriz leida
            matrix_t* result= new matrix_t();
            result->rows = unpack<int>(rpcIn);
            result->cols = unpack<int>(rpcIn);
            result->data = new int[result->rows * result->cols];
            unpackv(rpcIn, result->data, result->rows * result->cols);
             //mensaje de ok
            unsigned char ok=unpack<unsigned char>(rpcIn); 
                
                if(ok!=MSG_OK){
                std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
            }
           return result;
                

         
    };

    matrix_t* multMatrices(matrix_t* m1, matrix_t* m2){
        std::cout << "STUB_multmatrices" << std::endl;
        MultmatrixOp op = multMatricesOp;
        std::vector<unsigned char> rpcOut;
        std::vector<unsigned char> rpcIn;

        // empaquetar operacion
        pack(rpcOut, op);
        std::cout << "STUB_multmatrices 2" << std::endl;
        // pack matrices filas columnas y data de matriz 1 y matriz 2
        pack(rpcOut, m1->rows);
        pack(rpcOut, m1->cols);
        packv(rpcOut, m1->data, m1->rows * m1->cols);
        
    
        std::cout << "STUB_multmatrices 2-2" << std::endl;
        pack(rpcOut, m2->rows);
        std::cout << "STUB_multmatrices 2-rows" << std::endl;
        pack(rpcOut, m2->cols);
        std::cout << "STUB_multmatrices 2-cols" << std::endl;
        packv(rpcOut, m2->data, m2->rows * m2->cols);
        //enviamos la segunda matriz
        std::cout << "STUB_multmatrices 2-SENDMSG" << std::endl;
        sendMSG(serverConnection.serverId, rpcOut);
                
        std::cout << "STUB_multmatrices  3" << std::endl;
        // recibir matriz resultado
        recvMSG(serverConnection.serverId, rpcIn);
        //mensaje de ok
        unsigned char ok=unpack<unsigned char>(rpcIn); 
            
            if(ok!=MSG_OK){
            std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
        }
        // desempaquetar matriz resultado fila columna data
        //y un packv para que desempaquete la matriz
        matrix_t* result = new matrix_t();
        result->rows = unpack<int>(rpcIn);
        result->cols = unpack<int>(rpcIn);
        result->data = new int[result->rows * result->cols];
        unpackv(rpcIn, result->data, result->rows * result->cols);

        return result;
                
    };


    void writeMatrix(matrix_t* m, const std::string &ruta){
        std::cout << "WriteMatrix_STUB 1" << std::endl;
         MultmatrixOp op = writeMatrixOp;
         std::vector<unsigned char> rpcOut;
         std::vector<unsigned char> rpcIn;
        //pack operacion
        pack(rpcOut, op);
        //pack fila
        pack(rpcOut,m->rows); 
        //pack columna
        pack(rpcOut,m->cols);
        std::cout << "WriteMatrix_STUB 2" << std::endl;
         //packv data
        packv(rpcOut,m->data,m->rows * m->cols);
        //nombre ruta del archivo
        std::cout << "WriteMatrix_STUB 3" << std::endl;
       int datolength = ruta.length()+1;
       pack(rpcOut, datolength);  // +)1 para incluir el carácter nulo
       packv(rpcOut, (char*)ruta.data(), datolength);  // c_str() devuelve el const char*

         //enviar mensaje
        sendMSG(serverConnection.serverId, rpcOut);
        std::cout << "WriteMatrix_STUB 4" << std::endl;
        recvMSG(serverConnection.serverId,rpcIn);
       std::cout << "WriteMatrix_STUB 5" << std::endl;
       //mensaje ok
        unsigned char ok=unpack<unsigned char>(rpcIn); 
        
        if(ok!=MSG_OK){
        std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
         }
    };
     matrix_t* createIdentity(int rows, int cols){
        MultmatrixOp op = createIdentityOp;
        std::vector<unsigned char> rpcOut;
        std::vector<unsigned char> rpcIn;

        // pack operacion
        pack(rpcOut, op);

        // empaquetar filas columnas 
        pack(rpcOut, rows);
        pack(rpcOut, cols);

        // enviar mensaje
        sendMSG(serverConnection.serverId, rpcOut);

        // recibir matriz identidad
        recvMSG(serverConnection.serverId, rpcIn);
         //mensaje ok
        unsigned char ok=unpack<unsigned char>(rpcIn); 
        if(ok!=MSG_OK){
                std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
            }
        // desempaquetar matriz identidad , creamos matriz identidad y desempaquetamos las filas y columnas
        matrix_t* identity = new matrix_t();
        identity->rows = unpack<int>(rpcIn);
        identity->cols = unpack<int>(rpcIn);
        identity->data = new int[identity->rows * identity->cols];
        unpackv(rpcIn, identity->data, identity->rows * identity->cols);
        
       return identity;
     };
     matrix_t* createRandMatrix(int rows, int cols){
        MultmatrixOp op = createRandMatrixOp;
        std::vector<unsigned char> rpcOut;
        std::vector<unsigned char> rpcIn;

        // pack operacion
        pack(rpcOut, op);

        // pack filas y columnas
        pack(rpcOut, rows);
        pack(rpcOut, cols);

        // enviar mensaje
        sendMSG(serverConnection.serverId, rpcOut);

        // recibir matriz aleatoria
        recvMSG(serverConnection.serverId, rpcIn);

        //mensaje ok
        unsigned char ok=unpack<unsigned char>(rpcIn); 
        
        if(ok!=MSG_OK){
        std::cout<<"ERROR "<<__FILE__<<":"<<__LINE__<<"\n";
        }
        // desempaquetar matriz aleatoria filas columnas y data
        matrix_t* randMatrix = new matrix_t();
        randMatrix->rows = unpack<int>(rpcIn);
        randMatrix->cols = unpack<int>(rpcIn);
        randMatrix->data = new int[randMatrix->rows * randMatrix->cols];
        unpackv(rpcIn, randMatrix->data, randMatrix->rows * randMatrix->cols);

        
        return randMatrix;
        
     };
};