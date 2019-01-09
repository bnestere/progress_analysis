#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <iterator>
#include <set>
#include <vector>

#include "pp_reader.h"

using namespace std;

void extract_loops(string input, vector<int> *hierarchy) {
  string delimiter = ".";
  size_t pos = 0;
  std::string token;
  while ((pos = input.find(delimiter)) != string::npos) {
    token = input.substr(0, pos);
    hierarchy->push_back(atoi(token.c_str()));
    input.erase(0, pos + delimiter.length());
  }
  hierarchy->push_back(atoi(input.c_str()));

}

void process_pp_file(const char *filename, set<pp_set_t*> *pps_to_set) {
  fstream infile(filename);
  string line;

  pp_set_t *cur_pp;

  while(getline(infile, line)) {
    string pref = line.substr(0, 3);
    if(pref == "New") {
      cur_pp = new pp_set_t;
      pps_to_set->insert(cur_pp);

      istringstream iss(line);
      vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
      cur_pp->pp_no = atoi(results.at(2).c_str());
      cur_pp->function_name = results.at(8);
    } else if (pref == "Met") {
      istringstream iss(line);
      vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
      int is_first = 1;
      for(auto mvit = results.begin(); mvit != results.end(); ++mvit) {
        if(is_first == 1) {
          is_first = 0;
          continue;
        }
        stringstream doublewriter(*mvit);
        double mval;
        doublewriter >> mval;
        cur_pp->metric_vals.push_back(mval);
      }
    } else if(pref == "Loo") {
      // Loop idx
      string loop_idx = line.substr(15);
      extract_loops(loop_idx, &(cur_pp->loop_hierarchy));
      //cout << "Loop idx is " << loop_idx << endl;
    }
  }
}


