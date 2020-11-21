
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  string filename;
  cout << "Enter the input file name: ";
  cin >> filename;
  ifstream fin;
  string line;
  istringstream split;

  fin.open(filename.c_str());
  if(fin.is_open()){//if the file is good run the parser.
    while (getline(fin, line)) {//while we can get a line from the text
        cout << line << endl;
split.str(line);
cout<<"next"<<endl;
string word;
while(split.good()){
split>>word;
std::cout << word << '\n';
}

}}}
