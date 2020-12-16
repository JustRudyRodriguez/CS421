#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
stringstream split;
/* Look for all **'s and complete them */
static std::map<std::string, std::string> dict;

bool replace;
string saved_E_word;

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
	/* 0=q0,
	1=qc
	2=qt
	3=qy
	4=qsa
	5=qs
	6=q0qy
	7=q0q1
	//q1 was dropped since nothing point it.

	*/
	while (s[charpos] != '\0')
	{ //q0
		if (state == 0 && s[charpos] == 'c')
			state = 1;
		else if (state == 0 && s[charpos] == 't')
			state = 2;
		else if (state == 0 && s[charpos] == 's')
			state = 5;

		else if (state == 0 && (s[charpos] == 'g' || s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
			s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
			state = 3;

		else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
			s[charpos] == 'y' || s[charpos] == 'j'))
			state = 4;

		else if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;

		//qc
		else if (state == 1 && s[charpos] == 'h')
			state = 4;

		//qt
		else if (state == 2 && s[charpos] == 's')
			state = 4;
		else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;

		//qy
		else if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;
		else if (state == 3 && s[charpos] == 'y')
			state = 4;

		//qsa
		else if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;

		//qs
		else if (state == 5 && s[charpos] == 'h')
			state = 4;
		else if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;

		//q0qy
		else if (state == 6 && s[charpos] == 'c')
			state = 1;
		else if (state == 6 && s[charpos] == 't')
			state = 2;
		else if (state == 6 && s[charpos] == 's')
			state = 5;

		else if (state == 6 && (s[charpos] == 'g' || s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
			s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
			state = 3;

		else if (state == 6 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
			s[charpos] == 'y' || s[charpos] == 'j'))
			state = 4;

		else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;

		//q0q1
		else if (state == 7 && s[charpos] == 'c')
			state = 1;
		else if (state == 7 && s[charpos] == 't')
			state = 2;
		else if (state == 7 && s[charpos] == 's')
			state = 5;

		else if (state == 7 && (s[charpos] == 'n'))
			state = 6;

		else if (state == 7 && (s[charpos] == 'g' || s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
			state = 3;

		else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
			s[charpos] == 'y' || s[charpos] == 'j'))
			state = 4;

		else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'e' || s[charpos] == 'u' ||
			s[charpos] == 'o'))
			state = 7;
		else
			return (false);
		charpos++;
	} //end of while

	// where did I end up????
	if (state == 7 || state == 6)
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
	TENSE,
	NOUN,

	STORY
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[34] = { "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "WORD1", "WORD2", "EOFM", "PERIOD", "ERROR", "BE","TENSE", "NOUN","STORY" };

string reservedWords[18] = { "masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara" };

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

// ------------ Scanner and Driver -----------------------

ifstream fin; // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Rodolfo Rodriguez
int scanner(tokentype& tt, string& w)
{
	// ** Grab the next word from the file via fin
	// 1. If it is eofm, return right now.
	string current;
	if (!replace) {// checks if we're adding a word in manually through syntax error 1 flag
		split >> current;//pull from split
	}
	else {
		cout << "input a word: ";
		cin >> current;//pull from the user input stream.
		cout << endl;
	}
	if (current.compare(" ") == 0)//if the current word is space return back control
	{
		fin >> current;
	}
	if (current.compare("") == 0)//if the current word is blank
		return 1;// return error for blank
	tt = ERROR; // setting this as a starting value for logic reasons ahead, ignore for now.
	cout << "Scanner called using word: " << current << endl;

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

	for (int i = 0; i < 18; i++)//iterate the reservedWords array and look for a match
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

	if (current.back() == 'I' || current.back() == 'E')//If the word ends with I or E then its a word2
	{
		tt = WORD2;
		w = current;
		return 0;
	}
	else//otherwise its a word1.
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

// Type of error: Error 1
// Done by: Julian
ofstream RecordErrors("errors.txt");

bool syntax_error1(string lexeme, tokentype token)
{
	cout << "SYNTAX ERROR : expected " << tokenName[token] << " but found " << lexeme << endl;
	RecordErrors << "SYNTAX ERROR: expected " << tokenName[token] << " but found " << lexeme << endl;

	return false;
}
// Type of error: Error 2
// Done by: Julian
void syntax_error2(tokentype input, tokentype expected)
{
	cout << "SYNTAX ERROR : expected " << tokenName[expected] << " but found " << tokenName[input] << endl;
	exit(1);
}

string saved_lexeme;              // the example has this within next_token()
bool token_available;             //not sure if this needs to be here.
bool display_tracing_flag = true; // used for turning on and off tracing messages
ofstream translated_file("translated.txt");

tokentype saved_token;
string checkDict(string input) {
	try {// add english work.
		dict.at(input);
		return dict.at(input);
	}
	catch (std::out_of_range) { // add japanese word
		return input;
	}
}

void createDict() {
	string filename = "lexicon.txt";
	ifstream fin2;
	string line;
	string line2;

	fin2.open(filename.c_str());
	if (!fin2.good()) {
		std::cout << "Enter the dictionary file name: ";
		cin >> filename;
		fin2.open(filename.c_str());
	}

	cout << endl;
	if (fin2.good()) {//if the file is good run the parser.
		while (fin2 >> line) {
			if (fin2 >> line2) {
				dict[line] = line2;
			}
			else
			{
				std::cout << "unbalanced dictionary file" << endl;
				break;
			}
		}
		cout << "dictionary size is: " << dict.size() << endl;
		fin2.close();
	}
}

// Purpose: To use the saved_lexeme and cast is to the method checkDict and assign the returned value to saved_E_word.
// Done by: Andrew
void getEword() {
	saved_E_word = checkDict(saved_lexeme);
}

void gen(string word)
{
	if (word != "TENSE") {
		cout << word << ": " << saved_E_word << endl;
		translated_file << word << ": " << saved_E_word << endl;
	}
	else {
		cout << word << ": " << tokenName[saved_token] << endl;
		translated_file << word << ": " << tokenName[saved_token] << endl;
	}
}

// Purpose: takes tokentype checks for token and next
// Done by: Rudy
tokentype next_token()
{
	if (!token_available)//If there is no token avialave
	{
		scanner(saved_token, saved_lexeme);//scan for one using saved_token, and saved_lexeme.
		token_available = true;//We have some cache in saved_token and saved_lexeme
	}
	return saved_token;//return the token type in saved_token
}

// Purpose: recieves tokentype and checks if its expected type
// Done by: Rudy
bool match(tokentype expected)
{
	if (next_token() != expected)
	{
		syntax_error1(saved_lexeme, expected);

		string choice;//the user choice
		cout << "Would you like to replace or skip word? R/S ";
		cin >> choice;

		if (choice == "S" || choice == "s") {//if we choose to skip this word
			token_available = false;//make the token_available so that we can go to the next
			return true;
		}
		else
			if (choice == "R" || choice == "r") {
				replace = true;// set replacement flag to on
				scanner(saved_token, saved_lexeme);//start scanner with replacement flag
				match(expected);//match the new word with the expected token
				replace = false;//lower the flag for replacement
			}
			else//if the user doesn't want to fix it
				exit(1);
	}
	else
	{
		token_available = false;
		//can add flag to turn on and off tracing messages
		if (display_tracing_flag == true)
			cout << " Match succeeded, token type is: " + tokenName[expected] << endl; //display matched token_type when succeeds, used for tracing the program
	}
	return true;
}

// ----- RDP functions - one per non-term -------------------
// Done by: Rudy
// Grammer:  <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
void TENSE_FUNC()
{
	if (display_tracing_flag == true)
		cout << "Processing <TENSE>\n";
	switch (next_token())//VERBPAST  | VERBPASTNEG | VERB | VERBNEG
	{
	case VERBPAST://VERBPAST
		match(VERBPAST);
		break;
	case VERBPASTNEG://VERBPASTNEG
		match(VERBPASTNEG);
		break;
	case VERB://VERB
		match(VERB);
		break;
	case VERBNEG://VERBNEG
		match(VERBNEG);
		break;
	default:
		syntax_error2(saved_token, TENSE);
	}
}

//Done by: Andrew
//Grammer: <verb> ::= WORD2
void VERB_FUNC()
{
	if (display_tracing_flag == true)
		cout << "Processing <VERB>\n";
	match(WORD2);
}

//Done by: Julian
// Grammer: <noun> ::= WORD1 | PRONOUN
void NOUN_FUNC()
{
	if (display_tracing_flag == true)
		cout << "Processing <NOUN>\n";
	switch (next_token())//WORD1 | PRONOUN
	{
	case WORD1:
		match(WORD1);//WORD1
		break;
	case PRONOUN:
		match(PRONOUN);//PRONOUN
		break;
	default:
		syntax_error2(saved_token, NOUN);
	}
}

//Done by: Rudy
//Grammer:<after_subject> ::= <verb> <tense> PERIOD | <noun> <after_noun>
void AFTER_SUBJECT()
{
	if (display_tracing_flag == true)
		cout << "Processing <AFTER_SUBJECT>\n";
	switch (next_token())//<verb>|<noun>
	{
	case WORD2:
		VERB_FUNC();//<verb>
		getEword();
		gen("ACTION");
		TENSE_FUNC();//<tense>
		gen("TENSE");
		match(PERIOD);//PERIOD
		break;
	case WORD1: case PRONOUN:
		NOUN_FUNC();//<noun>
		getEword();
		AFTER_NOUN();//<after_noun>
		break;

	default:
		syntax_error2(saved_token, SUBJECT);
	}
}

//Done by: Andrew
//Grammer: <be> ::=   IS | WAS
void BE_FUNC()
{
	if (display_tracing_flag == true)
		cout << "Processing <BE>\n";
	switch (next_token())// IS | WAS
	{
	case IS:
		match(IS);//IS
		break;
	case WAS:
		match(WAS);//WAS
		break;
	default:
		syntax_error2(saved_token, BE);
	}
}

//Done by: Julian
//Grammer:<AFTER_OBJECT>::= <verb> <tense> PERIOD |<noun> DESTINATION <verb> <tense> PERIOD
void AFTER_OBJECT()
{
	if (display_tracing_flag == true)
		cout << "Processing <AFTER_OBJECT>\n";
	switch (next_token())//<verb>|<noun>
	{
	case WORD2:
		VERB_FUNC();//<verb>
		getEword();
		gen("ACTION");
		TENSE_FUNC();//<tense>
		gen("TENSE");
		match(PERIOD);//PERIOD
		break;
	case WORD1:  case PRONOUN:
		NOUN_FUNC();//<noun>
		getEword();
		match(DESTINATION);//DESTINATION
		gen("TO");
		VERB_FUNC();//<verb>
		getEword();
		gen("ACTION");
		TENSE_FUNC();//<tense>
		gen("TENSE");
		match(PERIOD);//PERIOD
		break;
	default:
		syntax_error2(saved_token, OBJECT);
	}
}

//Done by: Rudy
//Grammer:<after_noun>::=<be> PERIOD | DESTINATION <verb> <tense> PERIOD | OBJECT
void AFTER_NOUN()
{
	if (display_tracing_flag == true)
		cout << "Processing <AFTER_NOUN>\n";
	switch (next_token())// <be> | DESTINATION| OBJECT
	{
	case IS: case WAS:
		gen("DESCRIPTION");
		BE_FUNC();//<be>
		gen("TENSE");
		match(PERIOD);//PERIOD
		break;
	case DESTINATION:
		match(DESTINATION);//DESTINATION
		gen("TO");
		VERB_FUNC();//<verb>
		getEword();
		gen("ACTION");
		TENSE_FUNC();//<tense>
		gen("TENSE");
		match(PERIOD);//PERIOD
		break;
	case OBJECT:
		match(OBJECT);//OBJECT
		gen("OBJECT");
		AFTER_OBJECT();
		break;
	default:
		syntax_error2(saved_token, NOUN);
	}
}

//Done by: Andrew
//Grammer:  <s> ::= [CONNECTOR] <noun> SUBJECT <after_subject>
void s()
{
	if (display_tracing_flag == true)
		cout << "Processing <story>\n";

	switch (next_token()) {
	case CONNECTOR:
		match(CONNECTOR);//[CONNECTOR]
		getEword();
		gen("CONNECTOR");
		NOUN_FUNC();//<noun>
		getEword();
		match(SUBJECT);//SUBJECT
		gen("ACTOR");
		AFTER_SUBJECT();//<after_subject>
		break;
	case PRONOUN: case WORD1:
		NOUN_FUNC();//<noun>
		getEword();
		match(SUBJECT);//<SUBJECT>
		gen("ACTOR");
		AFTER_SUBJECT();//<after_subject>
		break;
	default:
		syntax_error2(saved_token, STORY);
		break;
	}
}
//Done by: Andrew
//Grammar story::<s>{<s>}
void story() {
	s();//<s>

	while (true) {//{<s>}
		switch (next_token())
		{
		case CONNECTOR: case PRONOUN: case WORD1://<s>::= CONNECTOR| <noun>
			s();
			break;
		default:
			return;
		}
	}
}
//Done by: Julian
//Purpose: Remove the empty lines from txt file
void DeleteEmptyLines(const string& FilePath)
{
	string BufferString = "";

	//File
	fstream FileStream;
	string CurrentReadLine;

	FileStream.open(FilePath, fstream::in); //open the file in Input mode

	//Read all the lines till the end of the file
	while (getline(FileStream, CurrentReadLine))
	{
		//Check if the line is empty
		if (!CurrentReadLine.empty())
			BufferString = BufferString + CurrentReadLine + "\n";
	}
	FileStream.close();
	FileStream.open(FilePath, fstream::out); //open file in Output mode. This line will delete all data inside the file.
	FileStream << BufferString;
	FileStream.close();
}

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by: Andrew
int main()
{
	createDict();
	std::cout << "CS 433 Programming assignment 3" << std::endl;
	std::cout << "Authors: Andrew, Rudy, and Julian" << std::endl;
	std::cout << "Date: 11/22/2020" << std::endl;
	std::cout << "Course: CS421 (Theory of Computing)" << std::endl;
	std::cout << "Description : parser project " << std::endl;
	std::cout << "=================================" << std::endl;
	string choice;
	string filename;
	cout << "Display tracing messages? Y/N: ";
	cin >> choice;

	if (choice == "N" || choice == "n")
		display_tracing_flag = false;
	cout << "Enter the input file name: ";
	cin >> filename;
	ifstream fin;
	string line;
	DeleteEmptyLines(filename.c_str());
	fin.open(filename.c_str());
	int refernces = 0;
	cout << endl;
	if (fin.good()) {//if the file is good run the parser.
		while (getline(fin, line)) {//while we can get a line from the text
			refernces++;
			if (line.size() == 1)//if there is no contents ine line then skip this iteration
				continue;
			if (line == "eofm")//break the loop if line is eofm
				break;
			cout << "====================================================================================================" << endl;
			cout << "The line is: " << line << endl;
			split.clear();//clear the flags and contents of split
			split << line;//pipe in the string line into split so it's tokenized between space marks.
			story();      //** calls the <story> to start parsing
			token_available = false;
			//add borders between interation of story for readability.
			RecordErrors << "==========================================================================================================================" << endl;
			RecordErrors << endl;
			translated_file << "==========================================================================================================================" << endl;
			translated_file << endl;
			cout << endl;
		}
		fin.close();
	}

	if (refernces == 0)
		cout << "There is no filename:" << filename << endl;

	//close ofstream

	RecordErrors.close();//close the file for the error report.
	translated_file.close();//close the file for the translated report.
}// end
