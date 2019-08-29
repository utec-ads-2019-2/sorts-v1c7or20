#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int contador[100], sorted[size];
            for (int i = 0; i <= 100 ; i++){
                contador[i] = 0;}
            for (int j = 1; j <= size ; j++){
                contador[elements[j]]++ ;}
            for (int k = 1; k <= 100 ; k++){
                contador[k] += contador[k - 1];}
            for (int l = size; l >=1 ; l--){
                sorted[contador[elements[l]]-1] = elements[l];
                contador[elements[l]] = contador[elements[l]] - 1;}
            for (int m = 0; m <size ; m++) {
                elements[m]=sorted[m];
            }
        }

        inline string name() { return "CountingSort"; }
};

#endif