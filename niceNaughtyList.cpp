#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using std::map;
using std::string;

int main(int argc, char** argv) {

  std::map<string , int> nameList;
  std::map<string, int>::iterator it;
  if (argc < 3 || argc >=4) {
    std::cout << "Usage: [filename] [threshold]" << std::endl;
  } else {
    int threshold = atoi(argv[2]);
    string line;
    std::ifstream myfile (argv[1]);
    if (myfile.is_open()) {
      while (myfile.good()) {
	getline (myfile, line);
	nameList[line] = nameList[line] + 1;
      }
      std::cout << "Nice List: " << std::endl;
      for (it = nameList.begin(); it != nameList.end(); it++) {
	if ((*it).second >= threshold)
	  std::cout << (*it).first << "=>" << (*it).second << " ";
      }
      std::cout<< std::endl;
      std::cout << "Naughty List: " << std::endl;
      for (it = nameList.begin(); it != nameList.end(); it++){
	if ((*it).second < threshold)
	  std::cout << (*it).first << "=>" << (*it).second << " ";
      }
      myfile.close();
    } else {
      std::cout << "Unable to open file" << std::endl;
    }
  }
  return 0;
}
