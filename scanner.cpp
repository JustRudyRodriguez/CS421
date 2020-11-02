#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: **
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA
// Done by: Julian Jaramillo
// RE:   **
bool word (string s)
{

  int state = 0;
  int charpos = 0;
  // replace the following todo the word dfa  **
  while (s[charpos] != '\0')
    {
      if (state == 0 && s[charpos] == 'c')
      state = 1;
      else
      if (state == 0 && s[charpos] == 't')
      state = 2;
      else
      if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
          s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 3;
      else
      if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
          s[charpos] == 'y' || s[charpos] == 'j'))
      state = 4;
      else
      if (state == 0 && s[charpos] == 's')
        state = 5;
      else
      if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
      state = 7;
      else
      if (state == 1 && s[charpos] == 's')
        state = 4;
      else
      if (state == 2 && s[charpos] == 's')
        state = 4;
      else
      if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
        state = 7;
      else
      if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
        state = 7;
      else
      if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
        state = 7;
      else
      if (state == 5 && s[charpos] == 'h')
        state = 4;
      else
      if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
        state = 7;
      else
      if (state == 6 && s[charpos] == 'c')
        state = 1;
      else
      if (state == 6 && s[charpos] == 't')
        state = 2;
      else
      if (state == 6 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
          s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r') )
        state = 3;
      else
      if (state == 6 && s[charpos] == 'y')
        state = 4;
      else
      if (state == 6 && s[charpos] == 's')
        state = 5;
      else
      if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
        state = 7;
      else
      if (state == 7 && s[charpos] == 'c')
        state = 1;
      else
      if (state == 7 && s[charpos] == 't')
        state = 2;
      else
      if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
          s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
        state = 3;
      else
      if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
          s[charpos] == 'y' || s[charpos] == 'j'))
        state = 4;
      else
      if (state == 7 && s[charpos] == 's')
        state = 5;
      else
      if (state == 7 && s[charpos] == 'n')
        state = 6;
      else
      if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
          s[charpos] == 'e' || s[charpos] == 'o'))
        state = 7;
     else
	    return(false);
     charpos++;
    }//end of while

  // where did I end up????
  if (state == 7) return(true);  // end in a final state
   else return(false);

}

// PERIOD DFA
// Done by: **
bool period (string s)
{ if(s.compare(".")==0)
  return true;
  else return false;
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype{VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN,PRONOUN,PRONOUN,PRONOUN,PRONOUN, CONNECTOR,CONNECTOR,CONNECTOR, CONNECTOR, WORD1, WORD2, EOFM, PERIOD, ERROR };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN","PRONOUN","PRONOUN","PRONOUN","PRONOUN", "CONNECTOR","CONNECTOR","CONNECTOR", "CONNECTOR", "WORD1", "WORD2", "EOFM" };



string reservedWords[30] = {"masu","masen","mashita","masendeshita"
,"desu" ,"deshita","o","wa","ni","watashi","anata","kare","kanojo","sore","mata"
,"soshite","shikashi","dakara"};
string verb = "masu";
string verbneg = "masen";
string verbpast = "ashita";
string verbpastneg = "masendeshita";
string is = "desu";
string was = "deshita";
string object = "o";
string subject = "wa";
string destination = "ni";
// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.


// ------------ Scanner and Driver -----------------------

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Rodolfo Rodriguez
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.
  string current;
  fin >> current;
  tt = ERROR;// setting this as a starting value for logic reasons ahead, ignore for now.

  if(current == ' '){
    fin >> current;
  }
  if(current == "eofm"){
    //need to add token type after table is setup. tt = eofm
    w=current;//passing value of "eofm" back and breaking out of loop.
    return 0;
  }
  /*  **


  2. Call the token functions (word and period)
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

***/
  if (period(current)) {
      tt= PERIOD;
      w = current;
      return 0;
  }
  else if(!(word(current))){
      //condition of a double false
      tt = ERROR; // This is to be updated after token table is created.
      w = current;// passing by reference.
      return 0;// May need to print "lexical error: &current is not a valid token" and Idea would be to recursively call scanner(), I don't see why not.
  }

/***

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.


***/
for(int i = 0;i < 30;i++){

  if(reservedWords[i]==current){
    tt = tokenName[i];//should assign correct token if both tables are setup correctly.
    w = current;
    return 0;// may delete this.
  }

}
if(current.back() == 'I'||current.back() == 'E'){
  tt= WORD2;// needs to be added to list.
  w = current;
  return 0;
}
else{
  tt= WORD1;
  w = current;
  return 0;
}
cout << "this is just here for testing. End of Scanner() reached, and no token type was selected.";



/***
  4. Return the token type & string  (pass by reference)
  */
// the returns are setup at all the if/else markers.
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword;
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end
