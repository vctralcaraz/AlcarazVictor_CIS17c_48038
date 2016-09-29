/* 
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the Abstract Row Array Class
 */

#ifndef ABSROW_H
#define	ABSROW_H


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;
        virtual int getData(int)const = 0;
};

#endif	/* ABSROW_H */