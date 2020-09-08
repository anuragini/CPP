//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #6




#include <iostream> 
#include <fstream>
using namespace std;    
#include "Book.h"

void printBooksByAuthor(Book books[], int numBooks, string author)// make an array for books with Book objects
{
    if(numBooks <=0) // if the size of array is less than or equal to zero
    {
        cout<<"No books are stored"<<endl;// prinr this statemnt
        return;
    }
    int count = 0; //set counter
    bool authorNamePrinted = false; // if authors name is not their print false
    for(int i = 0; i < numBooks; i++ ) // cycle through the size of the array
    {
        //cout<<authors[i]<<endl;
        if( books[i].getAuthor().compare(author) == 0) // if the author in array does equal author
        {
            count++;// count will increment 
            if (!authorNamePrinted){
                cout<<"Here is a list of books by "<<author<<endl; // if the authors name is not printed
                authorNamePrinted = true; // print list of books by author
            
            }
            cout<<books[i].getTitle()<<endl; // print titles from author
        } 
        
    }
    if(count == 0) // if there are not books 
    {
      cout<<"There are no books by "<<author<<endl; // print this statement
    }
   
    

}


int main()
{ 
//test case 1
//expected output 
// Here is a list of books from J RR Tolkien title3, 4, and 6
    int numBooks = 6; 
    Book books[numBooks];
    books[0] = Book("Title1", "Author1");
    books[1] = Book("Title2","Author2");
    books[2] = Book("Title3","J RR Tolkien");
    books[3] = Book("Title4","J RR Tolkien");
    books[4] = Book("Title5","Author2");
    books[5] = Book("Title6","J RR Tolkien");
    string s = "J RR Tolkien";
    printBooksByAuthor(books, numBooks,s);

//test case 2
//expected output 
//Here is a list of books by author2 
//title1 and title2
 numBooks = 3; 
     books[numBooks];
    books[0] = Book("Title1", "Author1");
    books[1] = Book("Title2","Author2");
    books[2] = Book("Title3","J RR Tolkien");
     s = "J RR Tolkien";
    printBooksByAuthor(books, numBooks,s);
    
    
    
}