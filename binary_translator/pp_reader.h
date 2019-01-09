#include <string>
#include <set>
#include <vector>

using namespace std;

typedef struct _pp_set_t {
  int pp_no;
  string function_name;
  vector<double> metric_vals;
  vector<int> loop_hierarchy;
} pp_set_t;

void process_pp_file(const char *filename, set<pp_set_t*> *pps_to_set);

