#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include<scanner.cpp>

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .
       and then append the two files into one:
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: *25*
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.

// Type of error: **
// Done by: **
void syntaxerror1(string lexeme,tokentype token  ){

   cout<< "SyntaxError 1 Found. "<<endl;
   cout<< "String       Token "<<endl;
   cout<< lexeme << "      "<< token<< endl;
 }
// Type of error: **
// Done by: **
void syntaxerror2( tokentype input,tokentype expected  ) {
   cout<< "SyntaxError 2 Encountered:"<<endl;
      cout<< "Input       Expected "<<endl;
   cout<< input << "      "<< expected<< endl;
    }

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

tokentype saved_token;
string saved_lexeme;// the example has this within next_token()
bool token_available;//not sure if this needs to be here.

// Purpose: **
// Done by: **

tokentype next_token(){
   //bool token_available;
   if(!token_available){
      scanner(saved_token,saved_lexeme);
      token_available=true;

      if(saved_token == ERROR){
         syntaxerror1(saved_lexeme,saved_token);
      }
}
   return saved_token;
}

// Purpose: **
// Done by: **

boolean match(tokentype expected) {

   if(next_token()!=expected){
      syntaxerror2(saved_token,expected);
   }
   else{
      token_available=false;
      return true;
   }

}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

string filename;

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  //** closes the input file

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
