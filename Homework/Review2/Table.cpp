/* 
 * File:   Table.cpp
 * Author: Victor Alcaraz
 * Created on September 29, 2016, 12:26 AM
 * Purpose: 
 */

#include "Table.h"

Table::Table(unsigned int r,unsigned int c) {
	this->szRow = r;
        this->szCol = c;
        this->columns = new RowAray *[szRow];
        for(int i = 0; i < szRow; i++)
        {
            this->columns[i] = new RowAray(szCol);
        }
}

Table::~Table() {
	for(int i = 0; i < szRow; i++)
    {
        delete columns[i];
    }
    delete [] columns;
}

int Table::getData(int r, int c)const {
    if(r > szRow && c > szCol) {return -1;}
    else return columns[r]->getData(c);
}

void Table::setData(int r, int c, int data) {
    this->columns[r]->setData(c,data);
}

Table::Table(const Table& table) {
    this->szCol = table.getSzCol(); 
    this->szRow = table.getSzRow();
    this->columns = new RowAray *[szRow];
    
    for(int i = 0; i < szRow; i++)
    {
        this->columns[i] = new RowAray(szCol);
    }
    
    for(int i = 0; i < szRow; i++)
    {
        for(int j = 0; j < szCol; j++)
        {
            setData(i,j,table.getData(i,j) );
        }
    }
}