/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    /* Your code goes here! */
    ifstream wordsFile(word_list_fname);
    string words;
    if (wordsFile.is_open()){
      while(getline(wordsFile,words))
      {
        if (words.length() == 5){
          string temp1 = words.substr(1);
    		  string temp2 = words.substr(0,1).append(words.substr(2));
    		if (d.homophones(temp1, words) && d.homophones(temp1, temp2) && d.homophones(temp2, words)){
          ret.push_back(make_tuple(words, temp1, temp2));
        }
       }
    	}
    }
    return ret;

}
