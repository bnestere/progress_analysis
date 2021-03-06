#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#include "pp_shared.h"
#include "progper.h"

#include <time.h>

static long pp_ctr = 0;

extern long active_pps[1024][128]; // tid pp_id
extern long trust_pp_nos[128]; // -1 ignore, 0 not sure and monitor, 1 trust
extern struct timespec duration_check_pp_nos[1024][128]; // [tid][pp_id]


long pp_begin(pp_user_t *user_d, int pp_no);

/*
 * Begins a new progress period with user specified data
 */
long pp_begin(pp_user_t *user_d, int pp_no) {
  //int pid = getpid() & 1023;
  int tid = syscall(__NR_gettid) & 1023;
  long pp_id = -1;

  // This pp is too short, ignore
  if(trust_pp_nos[pp_no] == -1) {
    //printf("Ignoring PP %d\n", pp_no);
    return -1;
  } else if(trust_pp_nos[pp_no] == 0) {
    // Not sure, we need to time the PP and see
    //printf("Testing the waters... pp %d tid %d\n", pp_no,syscall(__NR_gettid));
    struct timespec *spec = &duration_check_pp_nos[tid][pp_no];
    clock_gettime(CLOCK_REALTIME, spec);
  }

  // Assume trusted at this point, even if "not sure"
  if(active_pps[tid][pp_no] == 0) {
    // No active pp, go ahead
    pp_id = _do_pp_begin_call(user_d);
    //pp_id = syscall(NR_PP_BEGIN, (void *) user_d);
    //pp_id = tid + pp_no;
    active_pps[tid][pp_no] = pp_id;

    //printf("Beginning progress period %d: tid %d wss %d, reuse %d, rsrc %d\n", pp_no,syscall(__NR_gettid), user_d->wss, user_d->reuse, user_d->resource);
  }
	return pp_id;
}
