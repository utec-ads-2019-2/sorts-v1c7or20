#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        void quicksort(int array[], int low, int high){
            if (low<high){
                int part = partir(array,low,high);
                quicksort(array,low, part-1);
                quicksort(array,part+1,high);
            }
        }
        int partir(int array[], int low,int high){
            int pivot = array[high];
            int i = (low - 1);
            for (int j = low; j <=high -1 ; ++j) {
                if (array[j]<pivot){
                    i++;
                    swap(array[i],array[j]);
                }
            }
            swap(array[i+1],array[high]);
            return i+1;
        }

        void execute() {
            quicksort(elements,0,size);
        }

        inline string name() { return "QuickSort"; }
};

#endif