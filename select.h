#ifndef SELECT_H
#define SELECT_H

#include "sort.h"


class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int indice;
            for (int i = 0; i <size ; ++i) {
                indice=i;
                for (int j = i+1; j <size ; ++j) {
                    if(elements[j]<elements[indice])
                        indice = j;
                }
                swap(elements[indice],elements[i]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif