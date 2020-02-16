//This program reads sales information from a file and writes out a bar chart for each of the stores.
//The bar charts will be created by writing out a sequence of * characters.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Prototype functions
bool readFunction(ifstream & inputFile, long long int &, unsigned int &);
long long int salesDataFunction(long long int);
void displayFunction(ofstream & outputFile);

int main ()
{
    
    //Declare variables
    bool value = false;
    unsigned int storeNum;
    long long int salesData;
    string filename;
    
    
    // Prompt user for filename
    cout << "Enter input file name" << endl;
    cin >> filename;
    
    ifstream inputFile(filename); // Open file given by user
    ofstream outputFile("saleschart.txt"); // Sent files to output file
    
   if(inputFile) // Check to see if file can be read
   {
       bool firstDisplay = true; // Displays Star header
       
           do
           {
               while(inputFile >> storeNum >> salesData) // Read all input from file, line by line
               {
                   
                   value = readFunction(inputFile, salesData, storeNum); // Read and check files
                   
                   if(value == true) // Only displays when value is true
                   {
                       if(firstDisplay == true)
                       {
                           displayFunction(outputFile); // Calls display function
                           firstDisplay = false; // Sets display to false, so it is not called again
                       }
                       
                       salesData = salesDataFunction(salesData); // Calculates sales data for the amount of stars to be displayed
                       
                       if(storeNum < 10) // Calculates spaces for single digits
                       {
                           outputFile << "Store" << "  " << storeNum << ": ";
                       }
                       else // Spaces for multiple digits
                       {
                           outputFile << "Store" << " " << storeNum << ": ";
                       }
                       
                       for(int i = 0; i < salesData; i++) // Prints correct amount of stars
                       {
                           outputFile << "*";
                       }
                       
                       outputFile << endl;
                       value = false;
                   }
               }
           }
           while(value == true);
   }
   else // Only for a file that cannot be read
   {
       cout << "File \"" << filename << "\" could not be opened" << endl;
   }
    
    //Close all files
    inputFile.close();
    outputFile.close();
    
}

/*
 This function takes in an ifstream, long long int, unsigned int, and returns a bool. This
 function check the store number and then the sales data to determine if the varible is
 accurate.
 */

bool readFunction(ifstream & inputFile, long long int & salesData, unsigned int & storeNum)
{
    bool value = false;
    
   if(storeNum >= 1 && storeNum <= 99) // Make sure the value is in range
        {
            if(salesData >= 0) // Valid value will set value bool to true
            {
                value = true;
            }
            else // Otherwise false will be sent and error message will be sent
            {
                cout << "The sales value for store " << storeNum << " is negative" << endl;
                value = false;
            }
        }
        else // Error message will be sent out and bool set to false
        {
            cout << "The store number " << storeNum << " is not valid" << endl;
            value = false;
        }
    
    return value;
}

/*
 This function gets and returns a long long int.
 This function calculates the sales data.
 */

long long int salesDataFunction(long long int salesData)
{
    salesData /= 5000; //Calculate sales data
    
    return salesData;
}

/*
 This function takes in an ofstream and does not return a value.
 This function displays the header.
 */

void displayFunction(ofstream & outputFile)
{
    outputFile << "SALES BAR CHART" << endl << "(Each * equals 5,000 dollars)" << endl; //Display header
}
