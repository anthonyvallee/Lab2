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
	return tabElements[_index];
}

void DynamicArray::setElement(unsigned _index, int _valeur)
{
	if (_index + 1 > capacite)
	{
		setCapacite(_index + 1);
	}
	tabElements[_index + 1] = _valeur;
}

unsigned int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setCapacite(unsigned int _capacite)
{
	if (_capacite >= 1)
	{
		int* newArray = new int[_capacite];
		int* arrayToRemove = tabElements;
		for (int i = 0; i < capacite && i < _capacite; ++i)
		{
			newArray[i] = tabElements[i];
		}
		if (capacite < _capacite)
		{
			for (int i = capacite - 1; i < _capacite - 1; ++i)
			{
				newArray[i] = 0;
			}
		}
		this->capacite = _capacite;
		tabElements = newArray;
		delete arrayToRemove;
	}
	else
	{
		std::cout << "The given size must be greater or equal to 1.\n";
	}
}