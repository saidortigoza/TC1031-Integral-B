//
//  File: timsort.h
//  Date: 28/11/2021
//  Author: Said Ortigoza
//  Description: Implementación de las funciones del algoritmo de ordenamiento Timsort
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#ifndef TIMSORT_H
#define TIMSORT_H

#include<bits/stdc++.h>
#include <vector>
#include "usuario.h"

using namespace std;

const int RUN = 32;

// Algortimo de ordenamiento insertionSort que ordena las partes divididas del arreglo original
template<class T>
void insertionSort(vector<T> &v, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int temp = v[i];
    int j = i - 1;
    while (j >= left && v[j] > temp) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = temp;
  }
}

// Funcion merge que mezcla las corridas ordenadas por insertion sort
template<class T>
void merge(vector<T> &v, int l, int m, int r) {
    // El arreglo original se divide en dos partes: left y right
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    
    for (int i = 0; i < len1; i++) {
      left[i] = v[l + i];
    }
    
    for (int i = 0; i < len2; i++) {
      right[i] = v[m + 1 + i];
    }
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            v[k] = left[i];
            i++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copiamos los elementos restantes de left, si existe alguno
    while (i < len1) {
        v[k] = left[i];
        k++;
        i++;
    }
 
    // Copiamos los elementos restantes, si existe alguno
    while (j < len2) {
        v[k] = right[j];
        k++;
        j++;
    }
}

// Funcion timSort para ordenar los datos contenidos en el vector
template<class T>
vector<T> timSort(vector<T> &v) {
    int n = v.size(), i = 0;
    
    // Sort individual subarrays of size RUN
    for (i; i < n; i+=RUN) {
      insertionSort(v, i, min((i + RUN - 1), (n - 1)));
    }
 
    // Start merging from size RUN (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    
    for (int size = RUN; size < n; size = 2*size) {
      // Pick starting point of left sub array. We are going to merge arr[left..left+size-1]
      // and arr[left+size, left+2*size-1]. After every merge, we increase left by 2*size
      for (int left = 0; left < n; left += 2*size) {   
        // Find ending point of left sub array
        // mid+1 is starting point of right sub array
        int mid = left + size - 1;
        int right = min((left + 2*size - 1), (n-1));
 
        // Merge sub array arr[left.....mid] & arr[mid+1....right]
        if(mid < right) {
          merge(v, left, mid, right);
        }
      }
    }
    return v;
}

// Funcion para imprimir el vector ordenado
template<class T>
void printArray(vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    cout << v[i];
    cout << "\n";
  }
}

#endif