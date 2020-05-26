#include<iostream> 
using namespace std; 

bool append(string* str_arr, string s, int &numEntries, int &arraySize)
{
    bool isDoubled = false; 
    if(numEntries == arraySize)
    {
        int newCapacity = 2*arraySize; 
        string* newArray = new string[newCapacity]; 
        for(int i = 0; i<arraySize;i++)
        {
            newArray[i] = newCapacity[i];
        }
        str_arr = newArray;
        delete [] str_arr; //make sure you delete the memory
    }
    str_arr[numEntries] = s; 
    numEntries++; 
    return isDoubled;
}
