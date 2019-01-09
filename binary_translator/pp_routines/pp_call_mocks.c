#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#include "pp_shared.h"
#include "progper.h"

static int ctr = 0;

long _do_pp_begin_call(pp_user_t *user_d) {
  int pp_id = user_d->tid + ctr++;
  printf("Doing pp begin (%d) for pid %d tid %d wss %d sync group %d\n", pp_id, user_d->pid, user_d->tid, user_d->wss, user_d->sync_group);
  return pp_id;
}

long _do_pp_end_call(long pp_id) {
  printf("Doing pp end for %ld\n", pp_id);
  return 0;
}

