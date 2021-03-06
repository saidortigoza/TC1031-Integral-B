//
//  File: main.cpp
//  Date: 28/11/2021
//  Author: Said Ortigoza
//  Description: Archivo que contiene el programa main del proyecto
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#include <fstream>
#include <vector>
#include "usuario.h"
#include "hash.h"
#include "timsort.h"

using namespace std;

unsigned int myHash(const string s) {
  unsigned int acum = 0;
  for (unsigned int i = 0; i < s.size(); i++) {
    acum += (int) s[i];
  }
  return acum;
}

int main() {
  //Para usar archivos .txt
  ifstream inputFile;
	ofstream outputFile;

  //Variables
  string nombre, apellido, password, respuesta, ansPassword;
  int id, balance;

  //Vector que almacena los usuarios
	vector<Usuario> v;
  //Vector que almacena el id de los usuarios
  vector<int> v_id;

  //Tabla hash
  Hash<string, int> hash(10, string("empty"), myHash);

  inputFile.open("usuarios.txt");
  if (inputFile.is_open()) {
  	cout << '\n' << "Mostrando registro de usuarios..." << '\n' << endl;
    
    while (inputFile>>id>>nombre>>apellido>>balance>>password){
      //Mostrar la información de los usuarios registrados
      cout<< id << " " << nombre << " " << apellido << endl;
      
      //Almacenar la información en el vector
      Usuario usuario(id, nombre, apellido, balance, password);
      v_id.push_back(id);
      v.push_back(usuario);
    }

    //Ordenar y mostrar
    cout << '\n' << "Ordenando id de usuarios con timsort..." << endl;
    timSort(v_id);
    
    cout << '\n' << "Mostrando id de usuarios ordenados..." << '\n' << endl;
    printArray(v_id);
    //for(int i = 0; i < v_id.size(); i++){
    //  v[i].mostrarInfo();
    //}

    //Cerrar el archivo
    inputFile.close();
  }

  cout << "\n" << "Leyendo archivo usuarios.txt y guardando datos de cuentas de usuarios en tabla hash..." << endl;
  
  //Abrir el archivo de cuentas
  inputFile.open("usuarios.txt");
  if (inputFile.is_open()) {
    //Almacenando en tabla hash
    for (int i = 0; i < v.size(); i++) {
      hash.put(v[i].getPassword(), v[i].getBalance()); 
    }
    //Mostrar contenido de la tabla hash
    cout << "\n" << "Tabla hash creada:" <<endl;
    cout << hash.toString() <<endl;

    cout << "\n" << "Ingresa una contraseña para desplegar el balance de ese usuario: ";
    cin >> ansPassword;
    cout << "\n" << "El balance es: " << hash.get(ansPassword);
    
    inputFile.close();
  }
  else {
    cout << "Error al abrir archivo." << endl;
    return 0;
  }
  
  return 0;
}