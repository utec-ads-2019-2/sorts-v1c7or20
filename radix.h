#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int max = *max_element(elements,elements+size),
            sorted[size],
            exp;
            for ( exp = 1; max/exp > 0 ; exp= exp*10) {
                int contador[10]={0};
                for (int j = 0; j < size ; j++){
                    contador[(elements[j]/exp)%10]++ ;}
                for (int k = 1; k < 10 ; k++){
                    contador[k] += contador[k - 1];}
                for (int l = size-1; l >=0 ; l--){
                    sorted[contador[(elements[l]/exp)%10]-1] = elements[l];
                    contador[(elements[l]/exp)%10]-- ;}
                for (int m = 0; m <size ; m++) {
                    elements[m]=sorted[m];}
            }
        }

        inline string name() { return "RadixSort"; }
};

#endif