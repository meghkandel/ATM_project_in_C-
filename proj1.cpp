
// These are the libraries that is necessary for this program

#include <iostream>
#include "proj1.h"
#ifndef PROJ1_H
#define PROJ1_H
#include<fstream>
using namespace std;

//function protypes

int menuStart();
int menuMain();
void withdraw();
void deposit(float& accountBalance );
void displayAccountDetails(string fName, string lName, int age, float accountBalance );
void displayBalance(float accountBalance);


#endif


// main function 



int main(){


  //variables declarations  
  
  string fName, lName, yn;
  int age;
  ofstream outputStream;
  ifstream inputStream;  
  float accountBalance;
  const int NUM_0 = 0;
  const int NUM_1 = 1;
  const int NUM_3 = 3;    
  const int NUM_5 =5;
  const int NUM_6 = 6;
  cout<< fixed << showpoint <<setprecision(2);

  int value =  menuStart ( );  // function call

 
  // This while loop checks whether the choice entered by user is valid or not

 
  while(value < NUM_1 || value > NUM_3){
    
       cout<<"Please enter the number 1 or 2 or 3"<<endl;
       cin>> value;
     }//end while

   // a switch statement that switches the choices of user

  switch( value){
  case 1:
    
   inputStream.open("proj1.txt");
   inputStream>>fName >> lName;
   inputStream >> age;
   inputStream >> accountBalance;
   cout<<"  First Name:" << fName<<endl ;
   cout << "Last Name:" <<lName << endl;
   cout << "Age:" << age << endl;
   cout << "Initial Deposit :"<< accountBalance <<endl;
  
   inputStream.close();
      
   break;

  case 2:
    cout<<"Please enter the following:"<<endl;
    cout<<"First Name:"<<endl;
    cin>> fName;
    cout<< "Last Name:"<< endl;
    cin>> lName;
    cout<<"Age:"<<endl;
    cin>> age;
    cout<<"Initial Deposit:"<<endl;
    cin>> accountBalance;
    cout<<"$"<< accountBalance << "deposited"<<endl;


    
        
    break;
    
  default :
    
    return 0;
  }//ends switch



  int  value1 =  menuMain();// function call menuMain() 
    

    while (value1< NUM_1 || value1 > NUM_5 ){
      cout<<"Please enter a number 1 to 5"<<endl;
    
       cin>> value1;
    }
       while (value1>NUM_0 && value1< NUM_6){

    switch  (value1){


    case 1:
       displayBalance ( accountBalance);
       
       break;

    case 2:
      deposit( accountBalance);
      
      break;
  
  case 3:
      withdraw( accountBalance );
      
      break;

    case 4:
       displayAccountDetails( fName,  lName,  age,  accountBalance );
       
        break;

    case 5:
      cout<<"Would you like to save your account information?:"<<endl;
      cout<<"Yes or No"<<endl;
      cin>> yn;
      if (yn == "Yes" || yn == "yes" )
	{
	outputStream.open("proj1.txt");
        outputStream<< fName <<" "<< lName;
        outputStream <<" "<< age;
        outputStream<<" " << accountBalance;
	cout<<"File Saved"<<endl;
	outputStream.close();
	}
      cout <<"Thank you for using the UMBC ATM"<<endl;
     
      return 0;
      
  

    
    
    }//end switch
value1=    menuMain();
 
    } //ends while  
  return 0;

}// end of main() function 




/* function definition of menuMain(). This function welcomes users and allows t 
 users to enter some options*/
 

int menuStart( ){
  int choice;
  string fName, lName;
  
  fstream inputStream;

    cout << "Welcome to UMBC ATM"<<endl;
    cout  << "Choose from below"<<endl;
    cout << "1.Load a User Profile from File"<<endl;
    cout << "2.Enter a new User Profile"<<endl;
    cout << "3.Exit"<<endl;
    cout << "Enter your choice: ";
  cin >> choice;
  return choice;



}// end of menuStart()




/*function definition of menuMain(). This function also provides some options to users 
  to see their balance, to deposit, to withdraw etc.*/
 

int menuMain(){

  int choice;

  cout<<"*******Please choose option from the menu********** "<<endl;
     cout <<"1.Account Balance "<<endl;
     cout<<"2.Deposit money"<<endl;
     cout<<"3.Withdraw money"<<endl;
     cout<<"4.Display your account details"<<endl;
     cout<<"5.Exit"<<endl;
     cout<<"Enter your choice"<<endl;
     cin>> choice;
     return choice;
}//end of menuMain()




/* This is definition of function withdraw().
 * This allows users to withdraw        
 * money form their account.
*/
 

void withdraw (float&  accountBalance ){

  float withdrawAmount;
  
  float *ptrone = & accountBalance;

  cout <<"Please enter the amount to be withdrawn"<<endl;
  cin>> withdrawAmount;
  if(withdrawAmount< 0){
    cout<<"Amount cannot be less than 0"<<endl;
  }
  else{
    accountBalance = *ptrone - withdrawAmount;
    cout<<"$" << withdrawAmount<< "withdrawn from your account."<<endl;
  }
}// end of withdraw()




/* This is definition of deposit() function.
 * This alows to deposit money.
 * This tells users to enter valid 
 * balance as it cannot be negative
 */ 

void deposit (float& accountBalance ){
  
  float depositAmount;
  float *ptrtwo = &accountBalance;

  cout<<"Please enter the amount to be deposited"<<endl;
  cin>>depositAmount;

  if (depositAmount<0){
    cout<<"Amount cannot be less than 0"<<endl;
  }
  else{
    accountBalance = *ptrtwo + depositAmount;
    cout<<"$"<< depositAmount<<"deposited to your account"<<endl;

  }
}// end of deposit()



/* This is definition of displayAccountDetails()
 * This function displays users first name
 * last name, age, and account balance 
 */

void displayAccountDetails (string fName,string lName, int age, float accountBalance ){
  
  

cout<<"First Name:"<< fName <<endl;
cout<<"Last Name:"<< lName <<endl;
cout<<"Age:"<< age<< endl;
cout<<"Account Balance: $  "<< accountBalance <<endl;

}//end of displayAccountDetails()




/* This is function definition of dispalyBalance()
 * This function just show the banalce that user 
 *has on account.
 */

void displayBalance(float accountBalance ){
       
  
  cout<<"Your account balance is: $  "<< accountBalance <<endl;
}

