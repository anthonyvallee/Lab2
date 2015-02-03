#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <iostream>
#include <string>

const unsigned int DEFAULT_CAPACITE = 100;

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(unsigned int _capacite);
	~DynamicArray();
	int getElement(unsigned int _index);
	void setElement(unsigned int _index, int _valeur);
	unsigned int getCapacite();
	void setCapacite(unsigned int _capacite);
private:
	int* tabElements;
	unsigned int capacite;
	void initArray();
};


#endif //DYNAMICARRAY_H_