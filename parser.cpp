
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
istringstream split;
/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: **
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA
// Done by: Julian Jaramillo
// RE:   **
bool word(string s)
{

  int state = 0;
  int charpos = 0;
  // replace the following todo the word dfa  **
  while (s[charpos] != '\0')
  {
    if (state == 0 && s[charpos] == 'c')
      state = 1;
    else if (state == 0 && s[charpos] == 't')
      state = 2;
    else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
                            s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 3;
    else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
                            s[charpos] == 'y' || s[charpos] == 'j'))
      state = 4;
    else if (state == 0 && s[charpos] == 's')
      state = 5;
    else if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'E'|| s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else if (state == 1 && s[charpos] == 's')
      state = 4;
    else if (state == 2 && s[charpos] == 's')
      state = 4;
    else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'E'|| s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'E'|| s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'E'|| s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else if (state == 5 && s[charpos] == 'h')
      state = 4;
    else if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'i'|| s[charpos] == 'I'|| s[charpos] == 'E' || s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else if (state == 6 && s[charpos] == 'c')
      state = 1;
    else if (state == 6 && s[charpos] == 't')
      state = 2;
    else if (state == 6 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
                            s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 3;
    else if (state == 6 && s[charpos] == 'y')
      state = 4;
    else if (state == 6 && s[charpos] == 's')
      state = 5;
    else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'E'|| s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else if (state == 7 && s[charpos] == 'c')
      state = 1;
    else if (state == 7 && s[charpos] == 't')
      state = 2;
    else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
                            s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'||s[charpos] == 'g'))
      state = 3;
    else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
                            s[charpos] == 'y' || s[charpos] == 'j'))
      state = 4;
    else if (state == 7 && s[charpos] == 's')
      state = 5;
    else if (state == 7 && s[charpos] == 'n')
      state = 6;
    else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'E'|| s[charpos] == 'u' ||
                            s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
    else
      return (false);
    charpos++;
  } //end of while

  // where did I end up????
  if (state == 7)
    return (true); // end in a final state
  else
    return (false);
}

// PERIOD DFA
// Done by: *Andrew Malmstead*
bool period(string s)
{
  if (s.compare(".") == 0)
    return true;
  else
    return false;
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype
{
  VERB,
  VERBNEG,
  VERBPAST,
  VERBPASTNEG,
  IS,
  WAS,
  OBJECT,
  SUBJECT,
  DESTINATION,
  PRONOUN,
  CONNECTOR,
  WORD1,
  WORD2,
  EOFM,
  PERIOD,
  ERROR,
  BE,
  NOUN
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[32] = {"VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "WORD1", "WORD2", "EOFM", "PERIOD", "ERROR", "BE", "NOUN"};

string reservedWords[30] = {"masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara"};

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

// ------------ Scanner and Driver -----------------------

ifstream fin; // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Rodolfo Rodriguez
int scanner(tokentype &tt, string &w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.
  string current;
  split >> current;
  tt = ERROR; // setting this as a starting value for logic reasons ahead, ignore for now.

  if (current.compare(" ") == 0)
  {
    fin >> current;
  }
  if (current.compare("eofm") == 0)
  {
    //need to add token type after table is setup. tt = eofm
    w = current; //passing value of "eofm" back and breaking out of loop.
    return 0;
  }
  /*  **


  2. Call the token functions (word and period)
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

***/
for (int i = 0; i < 30; i++)
{

  if (reservedWords[i] == current)
  {

    if (i >= 9)
    {
      if (i >= 13)
      {
        tt = CONNECTOR;
        w = current;
        return 0;
      }
      tt = PRONOUN;
      w = current;
      return 0;
    }
    tt = tokentype(i); //should assign correct token if both tables are setup correctly.
    w = current;
    return 0; // may delete this.
  }
}
  if (period(current))
  {
    tt = PERIOD;
    w = current;
    return 0;
  }
  else if (!(word(current)))
  {


    //condition of a double false
    tt = ERROR;  // This is to be updated after token table is created.
    w = current; // passing by reference.
    cout << "Lexical error: " << current << " is not a valid token" << endl;
    return 0; // May need to print "lexical error: &current is not a valid token" and Idea would be to recursively call scanner(), I don't see why not.
  }

  /***

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.


***/

  if (current.back() == 'I' || current.back() == 'E')
  {
    tt = WORD2; // needs to be added to list.
    w = current;
    return 0;
  }
  else
  {
    tt = WORD1;
    w = current;
    return 0;
  }
  cout << "this is just here for testing. End of Scanner() reached, and no token type was selected.";

  return 1; //we shouldn't get to this point and if we do its an error;
  /***
  4. Return the token type & string  (pass by reference)
  */
  // the returns are setup at all the if/else markers.
} //the end of scanner

// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Louis

void AFTER_NOUN();
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

  cout << "SYNTAX ERROR: expected " << tokenName[token] << "but found " << lexeme << endl;
  //cout<< "String       Token "<<endl;
  cout << lexeme << "      " << token << endl;
  ofstream file;
  file.open("errors.txt");
  file << "SYNTAX ERROR: expected " << tokenName[token] << "but found " << lexeme << endl;
  file.close();
}
// Type of error: **
// Done by: **
void syntax_error2(tokentype input, tokentype expected)
{

//<<<<<<< HEAD
  cout << "SyntaxError 2 Encountered:" << endl;
  cout << "Input       Expected " << endl;
  cout << tokenName[input] << "      " << expected << endl;
//=======
  cout << "SYNTAX ERROR: expected " << tokenName[expected] << "but found " << tokenName[input] << endl;
  //need exit(1)
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

tokentype saved_token;
string saved_lexeme;              // the example has this within next_token()
bool token_available;             //not sure if this needs to be here.
bool display_tracing_flag = true; // used for turning on and off tracing messages



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
  }
  return true;

}

// ----- RDP functions - one per non-term -------------------

void TENSE()
{

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

  if (display_tracing_flag == true)
    cout << "Processing <VERB>\n";
  match(WORD2);
}

void NOUN_FUNC()
{

  if (display_tracing_flag == true)
    cout << "Processing <NOUN>\n";
  switch (next_token())
  {
  case WORD1:
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

  if (display_tracing_flag == true)
    cout << "Processing <AFTER_SUBJECT>\n";
  switch (next_token())
  {
  case VERB:
    VERB_FUNC();
    TENSE();
    match(PERIOD);
    break;
  case WORD1:
    NOUN_FUNC();
    AFTER_NOUN();
    break;
  case PRONOUN:
    NOUN_FUNC();
    AFTER_NOUN();
    break;
  default:
    syntax_error2(saved_token, saved_token);
  }
}
void BE_FUNC()
{

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
}
void AFTER_OBJECT()
{

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
    NOUN_FUNC();
    match(DESTINATION);
    VERB_FUNC();
    TENSE();
    match(PERIOD);
    break;
  case PRONOUN:
    NOUN_FUNC();
    match(DESTINATION);
    VERB_FUNC();
    TENSE();
    match(PERIOD);
    break;
  default:
    syntax_error2(saved_token, saved_token);
  }
}

  void AFTER_NOUN()
  {

    if (display_tracing_flag == true)
      cout << "Processing <AFTER_NOUN>\n";
    switch (next_token())
    {
    case IS:
      BE_FUNC();
      match(PERIOD);
      break;
    case WAS:
      BE_FUNC();
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

  void story()
  {

    if (display_tracing_flag == true)
      cout << "Processing <story>\n";

    switch (next_token()) {
      case CONNECTOR:
      match(CONNECTOR);
      NOUN_FUNC();
      match(SUBJECT);
      AFTER_SUBJECT();
      break;
      default:
      NOUN_FUNC();
      match(SUBJECT);
      AFTER_SUBJECT();
      break;
    }

  }

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  string choice;
  string filename;
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
split.str(line);
      story();      //** calls the <story> to start parsing
    }

  }else
  cout<<"There is no filename:"<<filename<<endl;
 }// end
  //** require no other input files!
  //** syntax error EC requires producing errors.txt of error messages
  //** tracing On/Off EC requires sending a flag to trace message output functions
