//
//  File: usuario.h
//  Date: 28/11/2021
//  Author: Said Ortigoza
//  Description: Clase para almacenar los atributos de cada cliente
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#ifndef USUARIO_H
#define USUARIO_H

#include<iostream>

using namespace std;

class Usuario {
  private:
    string nombre, apellido, password;
    int id, balance;

  public:
    Usuario(int i, string n, string a, int b, string p) {
      id = i;
      nombre = n;
      apellido = a;
      balance = b;
      password = p;
    }

    void mostrarInfo();

    int getId();
    string getNombre();
    string getApellido();
    int getBalance();
    string getPassword();
};

void Usuario::mostrarInfo() {
  cout << id << " " << nombre << " " << apellido << " " << balance << endl;
}

int Usuario::getId() {
  return id;
}

string Usuario::getNombre() {
  return nombre;
}

string Usuario::getApellido() {
  return apellido;
}

int Usuario::getBalance() {
  return balance;
}

string Usuario::getPassword() {
  return password;
}

#endif