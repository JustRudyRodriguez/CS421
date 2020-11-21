
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include "scanner.cpp"

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

// ** Need syntax_error1 and syntax_error2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.

// Type of error: **
// Done by: **
void syntax_error1(string lexeme, tokentype token)
{

  cout << "SYNTAX ERROR: expected " << token << "but found " << lexeme << endl;
  //cout<< "String       Token "<<endl;
  cout << lexeme << "      " << token << endl;
  ofstream file;
  file.open("errors.txt");
  file << "SYNTAX ERROR: expected " << token << "but found " << lexeme << endl;
  file.close();
}
// Type of error: **
// Done by: **
void syntax_error2(tokentype input, tokentype expected)
{
  cout << "SYNTAX ERROR: expected " << expected << "but found " << input << endl;

  //need exit(1)
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

tokentype saved_token;
string saved_lexeme;              // the example has this within next_token()
bool token_available;             //not sure if this needs to be here.
bool display_tracing_flag = true; // used for turning on and off tracing messages

istringstream split;

// Purpose: **
// Done by: **

tokentype next_token()
{
  //bool token_available;
  //need to set saved_lexeme = scanner()
  if (!token_available)
  {
    scanner(saved_token, saved_lexeme);
    token_available = true;

    if (saved_token == ERROR)
    {
      syntax_error1(saved_lexeme, saved_token);
    }
  }
  return saved_token;
}

// Purpose: **
// Done by: **

bool match(tokentype expected)
{
  if (next_token() != expected)
  {
    syntax_error2(saved_token, expected);
  }
  else
  {
    token_available = false;
    //can add flag to turn on and off tracing messages
    if (display_tracing_flag == true)
      cout << "Match succeeded, token type is: " + expected << endl; //display matched token_type when succeeds, used for tracing the program
    return true;
  }
}

// ----- RDP functions - one per non-term -------------------

void TENSE()
{
  split >> saved_lexeme;

  if (display_tracing_flag == true)
    cout << "Processing <TENSE>\n";
  switch (next_token())
  {
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
    syntax_error2(saved_token, saved_token);
  }
}

void VERB_FUNC()
{
  split >> saved_lexeme;

  if (display_tracing_flag == true)
    cout << "Processing <VERB>\n";
  match(WORD2);
}

void NOUN()
{
  split >> saved_lexeme;

  if (display_tracing_flag == true)
    cout << "Processing <NOUN>\n";
  switch (next_token())
  {
  case VERB:
    match(WORD1);
    break;
  case PRONOUN:
    match(PRONOUN);
    break;
  default:
    syntax_error2(saved_token, saved_token);
  }
}

void AFTER_SUBJECT()
{
  split >> saved_lexeme;

  if (display_tracing_flag == true)
    cout << "Processing <AFTER_SUBJECT>\n";
  switch (next_token())
  {
  case WORD2:
    VERB_FUNC();
    TENSE();
    match(PERIOD);
    break;
  case WORD1:
    NOUN();
    AFTER_NOUN();
    break;
  case PRONOUN:
    NOUN();
    AFTER_NOUN();
    break;
  default:
    syntax_error2(saved_token, saved_token);
  }
}
void BE()
{
  split >> saved_lexeme;

  if (display_tracing_flag == true)
    cout << "Processing <BE>\n";
  switch (next_token())
  {
  case IS:
    match(IS);
    break;
  case WAS:
    match(WAS);
    break;
  default:
    syntax_error2(saved_token, saved_token);
  }

  void AFTER_NOUN()
  {
    split >> saved_lexeme;

    if (display_tracing_flag == true)
      cout << "Processing <AFTER_NOUN>\n";
    switch (next_token())
    {
    case IS:
      BE();
      match(PERIOD);
      break;
    case WAS:
      BE();
      match(PERIOD);
      break;
    case DESTINATION:
      match(DESTINATION);
      VERB_FUNC();
      TENSE();
      match(PERIOD);
      break;
    case OBJECT:
      match(OBJECT);
      AFTER_OBJECT();
      break;
    default:
      syntax_error2(saved_token, saved_token);
    }
  }

  void AFTER_OBJECT()
  {
    split >> saved_lexeme;

    if (display_tracing_flag == true)
      cout << "Processing <AFTER_OBJECT>\n";
    switch (next_token())
    {
    case VERB:
      VERB_FUNC();
      TENSE();
      match(PERIOD);
      break;
    case WORD1:
      NOUN();
      match(DESTINATION);
      VERB_FUNC();
      TENSE();
      match(PERIOD);
      break;
    case PRONOUN:
      NOUN();
      match(DESTINATION);
      VERB_FUNC();
      TENSE();
      match(PERIOD);
      break;
    default:
      syntax_error2(saved_token, saved_token);
    }
  }

  void story()
  {
    split >> saved_lexeme;

    if (display_tracing_flag == true)
      cout << "Processing <story>\n";
    if (next_token() == CONNECTOR)
    {
      match(CONNECTOR);
    }
    NOUN();
    match(SUBJECT);
    AFTER_SUBJECT();
  }

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  string choice;
  cout << "Display tracing messages? Y/N: ";
  cin >> choice;
  if(choice == "N")
    display_tracing_flag = false;
  cout << "Enter the input file name: ";
  cin >> filename;
  ifstream fin;
  string line;
  fin.open(filename.c_str());
  if(fin.good()){//if the file is good run the parser.
    while (getline(fin, line)) {//while we can get a line from the text
split=new istringstream(line);
      story();      //** calls the <story> to start parsing
    }

  } // end
  //** require no other input files!
  //** syntax error EC requires producing errors.txt of error messages
  //** tracing On/Off EC requires sending a flag to trace message output functions
