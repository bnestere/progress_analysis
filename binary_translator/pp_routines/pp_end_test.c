#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>

#include "progper.h"
#include "pp_shared.h"

#define NR_PP_BEGIN 329
#define NR_PP_END 330
#define NR_PP_PRINT 331
#define NR_PP_RESET 332

extern long active_pps[1024][128]; // tid pp_id
extern long trust_pp_nos[128]; // -1 ignore, 0 not sure and monitor, 1 trust
extern struct timespec duration_check_pp_nos[1024][128]; // [tid][pp_id]



/*
 * Begins a new progress period with user specified data
 */
void pp_end(long pp_id, int pp_no) {
  //int pid = getpid() & 1023;
  int tid = syscall(__NR_gettid) & 1023;
  if(pp_id > 0 && active_pps[tid][pp_no] == pp_id) {
    //printf("Ending pp_no %d tid %d pp id %ld activeo %ld\n", pp_no,syscall(__NR_gettid), pp_id, active_pps[tid][pp_no]);
    // This is the pp we want to kill

    if(trust_pp_nos[pp_no] == 0) {
      struct timespec tend;
      struct timespec *tstart = &duration_check_pp_nos[tid][pp_no];
      clock_gettime(CLOCK_REALTIME, &tend);
      double diff = ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) 
        - ((double)tstart->tv_sec + 1.0e-9*tstart->tv_nsec);
      if(diff < 0.1) {
        // Ignore this one
        //printf("Diff time is %.5f seconds\n", diff);
        trust_pp_nos[pp_no] = -1;
        //printf("Ignoring because time is too short, pp %d: %.5f\n", pp_no, diff);
      } else {
        // we trust it
        trust_pp_nos[pp_no] = 1;
      }
    }

    long ret = _do_pp_end_call(pp_id);
    //long ret = syscall(NR_PP_END, pp_id);
    //long ret = 0;
    if(ret) {
      perror("Syscall pp_end failed");
      exit(1);
    }

    active_pps[tid][pp_no] = 0;
  }
}
