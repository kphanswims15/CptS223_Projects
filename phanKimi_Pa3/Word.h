/*
Programmer: Kimi Phan
Class: Cpts 223, Fall 2016
Project: Dictionary hash
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Description: This is a word class that holds a word and the word's definition
*/
class Word
{
public:
  // constructor
  Word();
  Word(string newWord, string newDefinition);

  // destructor
  ~Word();

  // getters
  string getWord() const;
  string getDefinition() const;
  int getKey() const;

  //setters
  void setWord(string newWord);
  void setDefinition(const string newDefinition);
  void setKey(const int newKey);

  unsigned int key(const string & key, int tableSize);

private:
  string mWord;
  string mDefinition;
  int mKey;
};
