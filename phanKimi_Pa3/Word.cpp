/*
Programmer: Kimi Phan
Class: Cpts 223, Fall 2016
Project: Dictionary hash
*/

#include "Word.h"

/*
Description: This is the default constructor
*/
Word::Word()
{
  mWord = "";
  mDefinition = "";
}

/*
Description: This is the constructor for the Word class. And it createds
             a new Word object when it is called.
*/
Word::Word(string newWord, string newDefinition)
{
  mWord = newWord;
  mDefinition = newDefinition;
}

/*
Description: This is the destructor.
*/
Word::~Word()
{

}

/*
Description: This is a getter that will get access to a copy of the private data
             member.
*/
string Word::getWord() const
{
  return mWord;
}

/*
Description: This is a getter that will get access to a copy of the private data
             memeber.
*/
string Word::getDefinition() const
{
  return mDefinition;
}

/*
Description: This is a getter that will get access to a copy of the private data
             member.
*/
int Word::getKey() const
{
    return mKey;
}

/*
Description: This is a setter that allows you to manipulate the private data memeber
*/
void Word::setWord(string newWord)
{
  mWord = newWord;
}

/*
Description: This is a setter that allows you to manipulate the private data member
*/
void Word::setDefinition(const string newDefinition)
{
  mDefinition = newDefinition;
}

/*
Description: Function that returns an integer based upon converting the word to
             to an int.
*/
unsigned int Word::key(const string & key, int tableSize)
{
  unsigned int hashVal = 0;

  for(char ch : key)
  {
    hashVal = (37 * hashVal) + ch;
  }

  return hashVal % tableSize;
}
