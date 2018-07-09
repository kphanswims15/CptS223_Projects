/*
Programmer: Kimi Phan
Class: Cpts 223, Fall 2016
Project: Dictionary hash
*/

#include "Dictionary.h"

/*
Description: This is a constructor that creates a new object for the Dictionary
             class.
*/
Dictionary::Dictionary()
{
  mTableSize = 101;
  mTheLists.resize(mTableSize);
  mNumberOfWords = 0;
  mLoadFactor = 0;
}


// Description: This is a destructor.
Dictionary::~Dictionary()
{

}

// Description: This a getter to get access to the private data member of tableSize.
int Dictionary::getTableSize() const
{
  return mTableSize;
}

// Description: This is a getter to get access to the private data member of number of words.
int Dictionary::getNumberOfWords() const
{
  return mNumberOfWords;
}

//Description: This is a getter to get access to the private data member of loadfactor
double Dictionary::getLoadFactor() const
{
  return mLoadFactor;
}

/*
Description: Hashes the word's key() and adds it to the hash table if it isn't already
             there.
*/
void Dictionary::insert(Word & x)
{
  string word = x.getWord();
  unsigned int key = x.key(word, mTableSize);

  // access to the vector in the hash table that contains the word
  vector<Word> &whichList = mTheLists[key];
  vector<Word>::iterator it = whichList.begin();

  // returns the iterator of where the word exists
  for (; it != whichList.end() && ((*it).getWord().compare(word)); it++)
  { }

  // if it exists then it updates the word definition
  if(it != end(whichList))
  {
    (*it).setDefinition(x.getDefinition());
  }
  else
  {
    // adds the word to the vector
    whichList.push_back(x);
    mNumberOfWords++;
  }

  mLoadFactor = (double)mNumberOfWords / (double)mTableSize;

  // rehash if load factor is greater than or equal to 1.
  if(mLoadFactor >= 1)
  {
    rehash();
  }
}

/*
Description: Searches the hash table by a string. It converts the string to a key,
             then hash it ans search the vector of Words to see if it is in the vector.
*/
bool Dictionary::contains(string word)
{
  bool inHash = false;

  Word words;

  // hashes to get the key of the word
  unsigned int key = words.key(word, mTableSize);


  // allows access to the first list that it finds.
  vector<Word> whichList = mTheLists[key];
  vector<Word>::iterator it = whichList.begin();

  // returns the iterator where it is located in the list
  for (; it != whichList.end() && (((*it).getWord()).compare(word)); it++)
  { }

  // returns true if it is in the list.
  if (it != whichList.end())
  {
    cout << it->getDefinition() << endl;
    inHash = true;
  }
  else
  {
    cout << "Word not found" << endl;
  }

  return inHash;
}

/*
Description: Finds an entry using the passed in words, erases it using vector.erase()
             from the hash table. It returns nullptr if the word does not exists.
*/
Word * Dictionary::deleteWord(string word)
{
  Word words;

  // hashes the word to get the key.
  unsigned int key = words.key(word, mTableSize);

  // gives access to the first vector where the word would be.
  vector<Word> & whichList = mTheLists[key];
  vector<Word>::iterator it = whichList.begin();

  // returns the iterator where the word exists
  for (; it != whichList.end() && ((*it).getWord().compare(word)); it++)
  { }

  if(it == end(whichList))
  {
    // nothing is deleted in the hash table
    return nullptr;
  }
  else
  {
    // word is found and the word gets deleted
    Word *temp = &(*it);
    whichList.erase(it);
    mNumberOfWords--;
    return temp;
  }
}

////////// Private data members ///////////

/*
Description: This is called when the table gets above a load factor(N/Table Size)
             of 1.0 during an insert of the word. It at least doubles the table
             size then finds the next prime number for the new table size.
*/
void Dictionary::rehash()
{
  vector<vector<Word>> oldLists = mTheLists;

  // Create new double-sized, empty table
  for(auto & thisList : mTheLists)
  {
    thisList.clear();
  }

  // resizes array to new table size
  mTheLists.resize(nextPrime(2 * mTableSize));

  // resets everything back to zero
  mLoadFactor = 0;
  mNumberOfWords = 0;

  // gets new table size
  mTableSize = mTheLists.size();

  // copy the table over
  for(auto & thisList : oldLists)
  {
    for(auto & x : thisList)
    {
      insert(x);
    }
  }
}

// Description: Finds the next prime number
int Dictionary::nextPrime(int tableSize)
{
    int nextPrime = tableSize;
    bool found = false;

    // loop continuously until isPrime returns true for a number above n
    while (!found)
    {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}

// Description: Checks if the number is prime
bool Dictionary::isPrime(int tableSize)
{
  //loop from 2 to n/2 to check for factors
    for (int i = 2; i <= tableSize/2; i++)
    {
        if (tableSize % i == 0)     //found a factor that isn't 1 or n, therefore not prime
            return false;
    }
    return true;
}
