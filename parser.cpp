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
void story(string sentence){
if(next_token()==CONNECTOR)
  match(CONNECTOR)
}
  NOUN();
  match(SUBJECT);
  AFTER_SUBJECT();
}

void AFTER_SUBJECT(){
  switch (next_token()) {
    case VERB:
      VERB();
      TENSE();
      match(PERIOD);
      break;
    case NOUN
      NOUN()
      AFTER_NOUN()
      break;
    default:
    syntaxerror2(next_token(),SUBJECT);
    break;

  }
}
void AFTER_NOUN(){
  switch (next_token()) {
    case WAS:
      BE();
      match(PERIOD);
      break;
    case IS:
      BE();
      match(PERIOD);
      break;
    case DESTINATION:
      match(DESTINATION);
      VERB();
      TENSE();
      match(PERIOD);
      break;
    case OBJECT:
      match(OBJECT);
      AFTER_OBJECT();
      break;
    default:
    syntaxerror2(next_token(),NOUN);
    break;
  }
}
void AFTER_OBJECT(){
  switch (next_token()) {
    case VERB:
      VERB();
      TENSE();
      match(PERIOD);
      break;
    case NOUN:
      NOUN();
      match(DESTINATION);
      VERB();
      TENSE();
      match(PERIOD);
      break;
    default:
    syntaxerror2(next_token(),OBJECT);
    break;
  }
}
void NOUN(){
  switch (next_token()) {
    case WORD1:
      match(WORD1);
      break;
    case PRONOUN:
      match(PRONOUN);
      break;
    default:
    syntaxerror2(next_token(),NOUN);
    break;

  }
}
void VERB(){
  match(WORD2);
}
void BE(){
  switch (next_token()) {
    case IS:
      match(IS);
      break;
    case WAS:
      match(WAS);
      break;
    default:
    syntaxerror2(next_token(),BE);
    break;
  }
}
void TENSE(){
  switch (next_token()) {
    case VERBPAST:
      break;
    case VERBPASTNEG:
      break;
    case VERB:
      match(VERB);
      break;
    case VERBNEG:
      match(VERBNEG);
      break;
    default:
    syntaxerror2(next_token(),TENSE);
    break;
  }
}
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
  ifstream fin;
  String line;
  fin.open(filename.c_str());
  if(fin.good()){//if the file is good run the parser.
    while (getline(fin, line)) {//while we can get a line from the text
      story(line);      //** calls the <story> to start parsing
    }
    fin.close();//** closes the input file
  }else{
    cout<<"The file does not exist"<<endl;//error handling for when a file doesn't exist
  }

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
