//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #5
#include <iostream> 
using namespace std;


float calcAvgRating(User users[], Book books[], int numUsers,int numBooks, string bookTitle)
{ 

    if(numUsers == 0) // edge case if there is no rating for a book return -3
    {
        return -3;
    }
    string bookValue = ""; // use this to compare in the books array
    string userValue = "";// use this value to compare in users array
    int bookIndex = -1;// index will increment
    int rating = -1;
    for(int i = 0; i<numBooks;i++)// go through numBooks
    {
      bookValue = books[i].getTitle();// get the title from book class
      string bookValueLower = to_lower(bookValue);// this will make it to lower case
      string bookTitleLower = to_lower(bookTitle);
      if(bookTitleLower.compare(bookValueLower) == 0 ) //bookTitle == bookValue
          {
              
              bookIndex = i;
              break;
          }
    }
    if (bookIndex == -1) //if the book does not exist
    {
        return -3;//return this value
    }
    
    float averageRating = 0.0; // initialize as double
    int sum = 0;
    int usercountWhoRated = 0;
    for(int i = 0; i<numUsers;i++)
    {

            rating = users[i].getRatingAt(bookIndex);
            if (rating > 0 && rating <= 5) 
            {
                sum = sum + rating;
                usercountWhoRated++;
            }
            
            

    }
    if(usercountWhoRated == 0)
    {
        return 0;
    }
    averageRating = float(sum)/float(usercountWhoRated);
    return averageRating;

        
}
int main()
{
    //test case 1
numBooks = 1; 
     books[numBooks];
    books[0] .setTitle("Title1");
    books[0].setAuthor("Author1")
    users[0].setUserName("User1");
    users[0].setNumRatings(2);
    users[0].setRatingAt(1,2);
    users[1].setUserName("Username1");

cout <<calcAverageRating(books, users, 1, 2,
"title1”);
    

//test case 2
//expected output 
//expected output 3.0
 numBooks = 3; 
     books[numBooks];
    books[0] .setTitle("Title1");
    books[0].setAuthor("Author1")
    users[0].setUserName("User1");
    users[0].setNumRatings(2);
    users[0].setRatingAt(1,2);
    users[1].setUserName("Username1");
    users[1].setUsername("User2");
    users[1].setNumRatings(4); 
    users[1].setRatingAt(0,4); 
    users[1].setRatingAt(1,4);
// calcAvgRating for Title2
cout <<calcAverageRating(books, users, 2, 2,
"title2");
     
    
    
}
