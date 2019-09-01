#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}


    void merge(int array[], int low, int high, int mid){
        int i,j,k,temp[high-low+1];
        i = low;
        k=0;
        j = mid + 1;
        while (i<= mid && j <= high){
            if (array[i] < array[j]){
                temp[k]= array[i];
                k++; i++;
            }else{
                temp[k] = array[j];
                k++;
                j++;
            }
        }
        while (i <= mid){
            temp[k] = array[i];
            k++;
            i++;
        }
        while (j <= high){
            temp[k] = array[j];
            k++;
            j++;
        }
        for ( i = low; i <= high; i++) {
            array[i] = temp[i-low];
        }
    }
    void mergesort(int array[], int low, int high){
        int mid = (low+high)/2;
        if (low < high){
            mergesort(array,low,mid);
            mergesort(array,mid+1,high);
            merge(array,low,high,mid);
        }
    }
        void execute() {
            mergesort(elements,0,size);
        }

        inline string name() { return "MergeSort"; }
};

#endif