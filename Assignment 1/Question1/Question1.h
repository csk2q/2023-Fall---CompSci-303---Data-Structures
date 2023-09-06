//Author csk2q
#pragma once


//ASSUMPTION: This class makes no guaranties about the order of items.
//New items will be added at the end of the array but may be moved from that location.
class Question1
{
private:
	int*  numArray;
	int count;
	int maxCount;

public:
	Question1(int startSize);
	Question1(int* numArray, int count, int arrayLength);
	~Question1();

	int GetCount() const;
	int GetLength() const;

	//1. A function to check if a certain integer exists in the array if the number is present return the index where the number is present.
	/**
	* Returns the index of the first occurrence of the given number.
	* If the number is not found -1 is returned instead.
	*/
	int Contains(int number);

	//2. A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
	//?QUESION: Does "return to the user" mean display to std or does it reference the return value of the function?
	/**
	* Sets the number at the given index to the new number.
	* Returns a pointer to an int array of length two in the form [oldNumber, newNumber].
	* Returns nullptr if the index was invalid.
	*/
	int* Modify(int index, int newNumber);

	//3. A function that adds a new integer to the end of the array
	/**
	* Adds a new integer to the end of the array. Expands the array if needed.
	*/
	void AddToEnd(int newNumber);
	 
	//4. A function which intakes an index of an array and replaces the value with either 0 or removes the integer altogether.
    /**
    * Removes the FIRST occurrence of the given number from the array.
    * Returns true if the number is removed.
    * Returns false if the number is not found.
    * POST-CONDITION: The order of the array is not maintained during removal.
    */
	bool Remove(int number);
};

