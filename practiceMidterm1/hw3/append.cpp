#include<iostream>
#include<fstream>
#include<vector>
using namespace std; 

bool append_OLD(string* &str_arr, string s, int &numEntries, int &arraySize)
{
    bool doubled = false;
    if(numEntries == arraySize) //if the arraySize is equal to the 
    {
    	 int newCapacity =  2 * arraySize;
         //cout<<"Resizing from "<<arraySize<<" to "<<newCapacity<<endl;
    
    	 //dynamically allocate an array of size newCapacity
    	string *newArray = new string[newCapacity];
    
    	//copy all data from oldArray to newArray
        for(int i = 0; i<arraySize;i++)
        {
            newArray[i] = str_arr[i];
        }
    
    	//free the memory associated with oldArray
    	delete[] str_arr;
    	//setting the newly created array pointer to str_arr;
        str_arr = newArray;
    	arraySize = newCapacity;
    	doubled = true;
    
    }
    str_arr[numEntries] = s;
    numEntries++;
    return doubled;
}

bool append1(string* &str_arr, string s, int &numEntries, int &arraySize)
{
	bool isDoubled = false; 
	if(numEntries == arraySize)
	{
		int newCapacity = 2* arraySize; 
		string* newArray = new string[newCapacity];
		
		for(int i = 0; i<arraySize;i++)
		{
			newArray[i] = str_arr[i]; //newarray is on the left because it is being assigned
		}
		delete[] str_arr;
		str_arr = newArray; 
		arraySize = newCapacity;
		isDoubled = true; 
	}
	str_arr[numEntries] = s;
	numEntries++; //max index = size of array - 1
	return isDoubled;

	
}



bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
{
	 bool isDoubled = false; 
	if(numEntries == arraySize)
	{
		int newCapacity = 2* arraySize;
		string* newArray = new string[newCapacity];
		
		for(int i = 0;i<arraySize;i++)
		{
			str_arr[i] = newArray[i];
		}
		delete [] str_arr;
		str_arr = newArray; 
		arraySize = newCapacity;
		isDoubled = true;
	}
	str_arr[numEntries] = s; 
	numEntries++;
	return isDoubled;
}


//Uncomment the lines and implement the TODOs in the resizing logic
string* resize(string* arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times
	 int newCapacity =  2 * capacity;
     cout<<"Resizing from "<<capacity<<" to "<<newCapacity<<endl;

	 //TODO dynamically allocate an array of size newCapacity
	string *newArray = new string[newCapacity];

	// TODO copy all data from oldArray to newArray
    for(int i = 0; i<capacity;i++)
    {
        newArray[i] = arrayPtr[i];
    }

	// TODO free the memory associated with oldArray
	delete[] arrayPtr;
    
	capacity = newCapacity;

	// TODO return the newArray
    return newArray;

}

int main()
{
	string filename = "input.txt";
	ifstream data;
	data.open(filename.c_str());

	string *str_arr;
    int numEntries = 0; 
    int arraySize = 10;
    bool isDoubled = false; 
	int numDoubled = 0;
	str_arr = new string[arraySize];

	string temp;

	if(data.is_open())
	{
		while(getline(data, temp))
		{
			string s = temp;
			isDoubled = append(str_arr, s, numEntries, arraySize);
			if (isDoubled){
				numDoubled++;
				cout <<numDoubled<<endl;
			}

		}
		data.close();
	}

	for(int i = 0; i < numEntries; i++)
	{
		//cout << "Num: " << str_arr[i] << endl;
	}
	return 0;
}
