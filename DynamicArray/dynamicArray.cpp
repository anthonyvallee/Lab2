#include "dynamicArray.h"


DynamicArray::DynamicArray(unsigned int _capacite)
{
	if (_capacite < 1) throw std::invalid_argument("The given capacity must be greater than or equal to 1.\n");
	this->tabElements = new int[_capacite];
	this->capacite = _capacite;
	initArray();		
}

DynamicArray::DynamicArray(const DynamicArray& _source)
	: tabElements(new int[_source.capacite]), capacite(_source.capacite)
{
	if (&_source == nullptr) throw std::invalid_argument("Le paramètre passé ne peut être NULL.\n");
	for (unsigned int i = 0; i < capacite; ++i)
	{
		this->tabElements[i] = _source.tabElements[i];
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray& _source)
{
	if (&_source == nullptr) throw std::invalid_argument("Le paramètre passé ne peut être NULL.\n");
	if (&_source != this)
	{
		delete[] tabElements;
		this->capacite = _source.capacite;
		this->tabElements = new int[capacite];
		for (unsigned int i = 0; i < capacite; ++i)
		{
			tabElements[i] = _source.tabElements[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& _rhs) const
{
	if (&_rhs == nullptr) throw std::invalid_argument("Le paramètre passé ne peut être NULL.\n");
	if (this->capacite != _rhs.capacite)
	{
		return false;
	}
	unsigned int smallestArrayLength = std::min(this->capacite, _rhs.capacite);
	for (int i = 0; i < smallestArrayLength; ++i)
	{
		if (this->tabElements[i] != _rhs.tabElements[i])
		{
			return false;
		}
	}
	return true;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _rhs)
{
	if (&_rhs == nullptr) throw std::invalid_argument("Le paramètre passé ne peut être NULL.\n");
	if (_rhs.capacite >= 1)
	{
		return appendArray(*this, _rhs);
	}
}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

int DynamicArray::getElement(unsigned int _index)
{
	if (_index + 1 > capacite) throw std::out_of_range("The given index is not part of the array.\n");
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
	if (_capacite <= 0) throw std::invalid_argument("The resize capacity must be greater than or equal to 1.");

	int* newArray = new int[_capacite];
	int* arrayToRemove = tabElements;
	for (unsigned int i = 0; i < capacite && i < _capacite; ++i)
	{
		newArray[i] = tabElements[i];
	}
	if (capacite < _capacite)
	{
		for (unsigned int i = capacite; i < _capacite; ++i)
		{
			newArray[i] = 0;
		}
	}
	this->capacite = _capacite;
	tabElements = newArray;
	delete arrayToRemove;
}

void DynamicArray::initArray()
{
	for (unsigned int i = 0; i < capacite; ++i)
	{
		tabElements[i] = 0;
	}
}

DynamicArray& DynamicArray::appendArray(const DynamicArray& firstArray, const DynamicArray& secondArray) const
{
	DynamicArray appendedArray(firstArray.capacite + secondArray.capacite);
	for (int i = 0; i < this->capacite; ++i)
	{
		appendedArray.tabElements[i] = firstArray.tabElements[i];
	}
	for (int i = 0; i < secondArray.capacite; ++i)
	{
		appendedArray.tabElements[i + firstArray.capacite] = secondArray.tabElements[i];
	}
	return appendedArray;
}