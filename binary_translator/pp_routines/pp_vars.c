#include <time.h>

long active_pps[1024][128]; // tid pp_id
long trust_pp_nos[128]; // -1 ignore, 0 not sure and monitor, 1 trust
struct timespec duration_check_pp_nos[1024][128]; // [tid][pp_id]
