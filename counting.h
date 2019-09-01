#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int max = *max_element(elements,elements+size);
            int min = *min_element(elements,elements+size);
            int rango = max-min + 1;
            int contador[rango], sorted[size];
            for (int i = 0; i <rango ; i++){
                contador[i] = 0;}
            for (int j = 0; j < size ; j++){
                contador[elements[j]-min]++ ;}
            for (int k = 1; k <= rango ; k++){
                contador[k] += contador[k - 1];}
            for (int l = size-1; l >=0 ; l--){
                sorted[contador[elements[l]-min]-1] = elements[l];
                contador[elements[l]-min]-- ;}
            for (int m = 0; m <size ; m++) {
                elements[m]=sorted[m];
            }
        }


        inline string name() { return "CountingSort"; }
};

#endif