#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for (int i = 0; i < size; i++) {
                for (int j = i; j <size ; j++) {
                    if (elements[i]>elements[j])
                        swap(elements[j], elements[i]);
                }
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif