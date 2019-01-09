#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <syscall.h>

#include <progper.h>

#define N_THREADS 8

void *do_pp_thread(void *ptr) {
  int *val = (int *) ptr;
  int pp_no = *val;
  pp_user_t pp;
  pp.pid = getpid();
  pp.tid = syscall(__NR_gettid);
  pp.wss = 20;
  pp.resource = 0;
  pp.reuse = 0;
  pp.sync_group = 1;
  pp.n_syncing_threads = N_THREADS;

  //unsigned long pp_no = 1;
  printf("Beginning progress period pid %d tid %d\n", pp.pid, pp.tid);
  sleep(pp_no);
  long ppid =  pp_begin(&pp, pp_no);
  printf("TID %d inside PP\n", pp.tid);
  //usleep(5000000);
  pp_end(ppid, pp_no);
  printf("Ending progress period pid %d tid %d\n", pp.pid, pp.tid);

  free(val);
}

int main(int argc, char *argv[]) {

  printf("In the main\n");
  int nt = N_THREADS;
  pthread_t threads[nt];

  for(int i = 0; i < nt; i++) {
    int *arg = malloc(sizeof(int));
    *arg = i;
    if(pthread_create(&threads[i], NULL, do_pp_thread, arg)) {
      perror("Failed to alloc thread");
      exit(EXIT_FAILURE);
    }
  }

  for(int i = 0; i < nt; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;





//
//  pp_user_t pp;
//  pp.wss = 2;
//  pp.resource = 0;
//  pp.reuse = 0;
//
//  unsigned long pp_no = 1;
//  long ppid =  pp_begin(&pp, pp_no);
//  usleep(50000);
//  pp_end(ppid, pp_no);
//  ppid =  pp_begin(&pp, pp_no);
//  usleep(500000);
//  pp_end(ppid, pp_no);

}
