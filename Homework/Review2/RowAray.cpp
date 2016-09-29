/* 
 * File:   RowAray.cpp
 * Author: Victor Alcaraz
 * Created on September 29, 2016, 12:26 AM
 * Purpose: 
 */

#include "RowAray.h"

RowAray::RowAray(unsigned int row) {
    this->size = row;
    this->rowData = new int[size];
    for(int i = 0; i < size; i++){
        rowData[i] = rand() % 90 + 10;
    }
}
RowAray::~RowAray() {
    delete []rowData;
}
void RowAray::setData(int i, int data) {
    this->rowData[i] = data;
}
