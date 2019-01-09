#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#include "pp_shared.h"
#include "progper.h"


long _do_pp_begin_call(pp_user_t *user_d) {
  return syscall(NR_PP_BEGIN, (void *) user_d);
}

long _do_pp_end_call(long pp_id) {
  return syscall(NR_PP_END, pp_id);
}

