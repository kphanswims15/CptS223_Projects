/*
Programmer: Kimi Phan
Class: Cpts 223, Fall 2016
Project: Dictionary hash
*/

#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Word.h"

using namespace std;

/*
Description: Implements a hash table (a vector), hash table size will start with
             size 101. This class will keep track of how many Words it holds
             (which is size N)
*/
class Dictionary
{
public:
  // constructor
  Dictionary();

  // destructor
  ~Dictionary();

  //getter
  int getTableSize() const;
  int getNumberOfWords() const;
  double getLoadFactor() const;

  void insert(Word & x);
  bool contains(string word);
  Word * deleteWord(string word);

private:
  int mTableSize;
  int mNumberOfWords;
  double mLoadFactor;
  vector<vector<Word>> mTheLists;

  void rehash();
  int nextPrime(int tableSize);
  bool isPrime(int tableSize);
};
