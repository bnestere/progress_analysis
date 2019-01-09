#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#include "pp.h"

/*
 * Begins a new progress period with user specified data
 */
long pp_begin(pp_user_t *user_d) {
	return syscall(NR_PP_BEGIN, (void *) user_d);
}

void pp_end(long remove_id) {
	long ret = syscall(NR_PP_END, remove_id);
	if(ret) {
		perror("Syscall pp_end failed");
		exit(1);
	}
}

void pp_print_queues() {
	long ret = syscall(NR_PP_PRINT, NULL);
	if(ret) {
		perror("Syscall pp_print failed");
		exit(1);
	}
}

void pp_reset() {
	long ret = syscall(NR_PP_RESET, NULL);
	if(ret) {
		perror("Syscall pp_reset failed");
		exit(1);
	}
}
