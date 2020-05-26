#include<iostream> 
using namespace std; 

bool append(string* str_arr, string s, int &numEntries, int &arraySize)
{
    bool isDoubled = false; 
    if(numEntries == arraySize) //if the number of elements is equal to the arraySize then execute
    {
        int newCapacity = 2 * arraySize; //double size
        string* newArray = new string[newCapacity]; //create a new pointer for the size
        for(int i = 0; i<arraySize;i++)
        {
            newArray[i] = newCapacity[i]; //dynamically allocate the newCapacity to the assigned pointer
        }
        str_arr = newArray; //assign the old array to the new one
        delete[] str_arr;//delete old array
    }
    str_arr[numEntries] = s; //read lines of the file
    numEntries++; 
    return isDoubled;
}