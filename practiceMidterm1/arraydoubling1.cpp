#include<iostream>
#include<fstream>
using namespace std; 

bool append(string* str_arr, string s, int &numEntries, int &arraySize)
{
    bool doubled = false;
    //if the number of elements 
    if(numEntries == arraySize)
    {
        int newCapacity = 2* arraySize;
        //dynamically allocate the new size to the new array
        string*newArray = new string[newCapacity];
        for(int i = 0; i<arraySize;i++)
        {
            newArray[i] = str_arr[i];
        }
        delete [] str_arr; 
        str_arr = newArray;
        arraySize = newCapacity;
        doubled = true;
        
        
    }
    str_arr[numEntries] = s; 
        numEntries++; 
        return doubled; 
        
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

	str_arr = new string[arraySize];

	string temp;

	if(data.is_open())
	{
		while(getline(data, temp))
		{
			string s = temp;
			isDoubled = append(str_arr, s, numEntries, arraySize);
			cout<<s<<" " <<isDoubled<<endl;
		}
		data.close();
	}

	for(int i = 0; i < numEntries; i++)
	{
		cout << "Num: " << str_arr[i] << endl;
	}
	return 0;
}