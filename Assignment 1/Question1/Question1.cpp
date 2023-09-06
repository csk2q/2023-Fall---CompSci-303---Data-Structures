//Author csk2q

#include "Question1.h"
#include <stdexcept>
#include <string>

using namespace std;

Question1::Question1(int startSize) : Question1(new int[startSize], 0, startSize)
{
}

Question1::Question1(int* numberArray, int count, int maxCount)
{
	this->numArray = numberArray;
	this->count = count;
	this->maxCount = maxCount;
}

Question1::~Question1()
{
	delete[] numArray;
}

int Question1::GetCount() const
{
	return count;
}

int Question1::GetLength() const
{
	return maxCount;
}

int Question1::Contains(int number)
{
    //Search the entire array
	for (int i = 0; i < count; i++)
	{
        //If found return index
		if (numArray[i] == number)
			return i;
	}

    //The number was not found
	return -1;
}

int* Question1::Modify(int index, int newNumber)
{
    //Check that index is in bounds
	if (index < 0 || index >= count)
		//throw out_of_range("Invalid index of " + to_string(index) + " passed to Question1::Modify!");
		return nullptr; //If out of bounds
    
    //Swap in the new number
	int oldNumber = numArray[index];
	numArray[index] = newNumber;

    //Return old and new numbers
	return new int[2] {oldNumber, newNumber};
}

void Question1::AddToEnd(int newNumber)
{
    //If numArray is full reallocate with +10 slots
	if (count >= maxCount)
	{
		int* newArray = new int[count + 10];
		for (int i = 0; i < count; i++)
		{
			newArray[i] = numArray[i];
		}

		delete[] numArray;
		numArray = newArray;
		maxCount += 10;

	}

    //Add the new number to the first unused slot
	numArray[count++] = newNumber;
}

bool Question1::Remove(int index)
{
    //If the number exists
	if (index >= 0 && index < count)
	{
        //Overwrite the number with the last number
		numArray[index] = numArray[--count];
		return true;
	}

    //Number was not found
	return false;
}
