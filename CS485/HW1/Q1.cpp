//Homework 1, Question 1
//Shift cipher

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

int main(){
  //variables used to decrypt
  string cipherText;
  char decrypt[250];
  int check = 0;

  //Open the text file
  ifstream myText ("Q1.txt");

  //read in the text file
  if(myText.is_open()){
    getline(myText, cipherText);
    //close the text file
    myText.close();
    //Loop to check multiple key values
    while(check != 99){

      cout << "Key to check" << endl;
      cin >> check;    
      cin.ignore(100, '\n');
      
      for(int i = 0; i < cipherText.length(); i++){
        //the input text will be shifted by the value of the key
        //and stored into the array decrypt.
        decrypt[i] = ((((cipherText[i] - 97) + (25 - check)) % 25) + 97);
      }
      cout << endl;
      for(int j = 0; j < cipherText.length(); j++){
        cout << decrypt[j];
      }
      cout << endl;
    }
  }
  else
    cout << "Cannot open file\n";
  return 0;
}
