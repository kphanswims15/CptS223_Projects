/*
Programmer: Kimi Phan
Class: Cpts 223, Fall 2016
Project: Dictionary hash
*/

#include "Dictionary.h"

int main(int argc, char *argv[])
{
  if(argc == 2)
  {
    ifstream file;
    file.open(argv[1]);
    Word newWord;
    Dictionary hash;

    string word = "", definition = "", buffer = "";

    while(file.good())
    {
      // get the word and definition from the file.
      getline(getline(file, buffer, '"'), word, '"');
      getline(getline(file, buffer, '"'), definition, '}');

      // gets rid of the '"' at the end of the definition.
      definition.pop_back();

      // sets the word and definition in the word class.
      newWord.setWord(word);
      newWord.setDefinition(definition);

      // inserts the new word into the hash table.
      hash.insert(newWord);
    }
    cout << "Hash table is full" << endl;
    cout << "Number of words in the hash table is " << hash.getNumberOfWords() << endl;
    cout << "Current table size is " << hash.getTableSize() << endl;
    cout << "Current load factor " << hash.getLoadFactor() << endl << endl;

    cout << "Word to define: ";
    string inWord;
    while(getline(cin, inWord))
    {
      // converts word to uppercase
      transform(inWord.begin(), inWord.end(), inWord.begin(), ::toupper);

      // checks if the word is in the class
      hash.contains(inWord);

      cout << "Word to define: ";
    }
}
  else
  {
    cout << "A file was not opened. To open the file please enter the file" << endl;
    cout << "name with the /a.out file that was generated." << endl;
  }
  return 0;
}
