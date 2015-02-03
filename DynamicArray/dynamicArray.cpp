#include "dynamicArray.h"


DynamicArray::DynamicArray()
{
	this->tabElements = new int[DEFAULT_CAPACITE];
	this->capacite = DEFAULT_CAPACITE;
	initArray();
}

DynamicArray::DynamicArray(unsigned int _capacite)
{
	if (_capacite < 1)
	{
		throw std::invalid_argument("The given capacity must be greater than or equal to 1.\n");
	}
	this->tabElements = new int[_capacite];
	this->capacite = _capacite;
	initArray();		
}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

int DynamicArray::getElement(unsigned int _index)
{
	if (_index + 1 > capacite)
	{
		throw std::out_of_range("The given index is not part of the array.\n");
	}
	return tabElements[_index];
}

void DynamicArray::setElement(unsigned int _index, int _valeur)
{
	if (_index + 1 > capacite)
	{
		setCapacite(_index + 1);
	}
	tabElements[_index] = _valeur;
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
			std::string tempValue = std::to_string(tabElements[i]);
		}
		if (capacite < _capacite)
		{
			for (int i = capacite; i < _capacite; ++i)
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
		throw std::invalid_argument("The resize capacity must be greater than or equal to 1.");
	}
}

void DynamicArray::initArray()
{
	for (int i = 0; i < capacite; ++i)
	{
		tabElements[i] = 0;
	}
}