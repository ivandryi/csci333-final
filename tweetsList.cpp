#include <iostream>
#include <map>
#include <fstream>
#include <string>

using std::map;
using std::string;

int main() {

  std::map<string, int> tweetList;
  std::map<string, int>::iterator it;
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
      // std::cout << word << " "; 
      tweetList[word] = tweetList[word] + 1;
    }
    myfile.close();
    for (it = tweetList.begin(); it != tweetList.end(); it++) {
      std::cout << (*it).first << " => " << (*it).second << std::endl;
    }
  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}
