#include <iostream>
#include <map>
#include <fstream>
#include <string>


using std::map;
using std::string;
using std::pair;

int main() {

  std::map<string, int> tweetList;
  std::multimap<int, string> reverseTweetList;
  std::map<string, int>::iterator it;
  std::multimap<int, string>::reverse_iterator itR;
  int totalWords = 0;
  int uniqueWords = 0;
  string line;
  std::ifstream myfile("tweets");
  if (myfile.is_open()) {
    while (myfile.good()) {
      getline (myfile, line);
      string word = "";
      for (size_t i = 0; i < line.length(); i++) {
	if (line.at(i) != ' ') {
	  word.push_back(line.at(i));
	} else {
	  word = "";
	}
      }
      totalWords++;
      tweetList[word] = tweetList[word] + 1;
    }
    myfile.close();
    for (it = tweetList.begin(); it != tweetList.end(); it++) {
      //std::cout << (*it).first << "=>" << (*it).second << std::endl;
    }
    for (it = tweetList.begin(); it != tweetList.end(); it++) {
      reverseTweetList.insert (pair<int, string>((*it).second, (*it).first) );
    }
    for (itR = reverseTweetList.rbegin(); itR != reverseTweetList.rend(); itR++) {
       std::cout << (*itR).first << " => " << (*itR).second << std::endl;
    }
    for (itR = reverseTweetList.rbegin(); itR != reverseTweetList.rend(); itR++) {
      if ((*itR).first == 1) {
uniqueWords++;
      }
    }
    std::cout << "Number of unique words: " << uniqueWords << std::endl;
    std::cout << "Diversity: " << totalWords/uniqueWords << std::endl;
  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}
