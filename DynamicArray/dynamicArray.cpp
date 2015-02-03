#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	DynamicArray(DEFAULT_CAPACITE);
}

DynamicArray::DynamicArray(unsigned int _capacite)
{
	this->tabElements = new int[_capacite];
	this->capacite = _capacite;
}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

int DynamicArray::getElement(unsigned _index)
{
	return *tabElements[_index];
}

void DynamicArray::setElement(unsigned _index, int _valeur)
{

}

unsigned int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setCapacite(unsigned _capacite)
{
	this->capacite = _capacite;
}