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

/*
 * Begins a new progress period with user specified data
 */
void pp_end(long pp_id, int pp_no) {
  int tid = syscall(__NR_gettid) & 1023;
  if(pp_id > 0 && active_pps[tid][pp_no] == pp_id) {
    // This is the pp we want to kill

    long ret = _do_pp_end_call(pp_id);
    if(ret) {
      perror("Syscall pp_end failed");
      exit(1);
    }

    active_pps[tid][pp_no] = 0;
  }
}
