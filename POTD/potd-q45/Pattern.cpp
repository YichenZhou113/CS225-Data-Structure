#include "Pattern.h"
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

bool wordPattern(std::string pattern, std::string str) {
   map<char, std::string> letter_to_word;
   set<std::string> words_seen;
   std::istringstream iss(str);
   string word;
for (int i = 0; i < int(pattern.size()); ++i)
{
    if (!(iss >> word))
        return false; // more letters than words
    std::string& expected_word = letter_to_word[pattern[i]];
    if (expected_word == "")
    {
        // if different letters require different words...
        if (words_seen.find(word) != words_seen.end())
            return false; // multiple letters for same word
        words_seen.insert(word);

        expected_word = word; // first time we've seen letter, remember associated word
    }
    else if (expected_word != word)
        return false; // different word for same letter
}
return !(iss >> word); // check no surplus words

    //write your code here
}
