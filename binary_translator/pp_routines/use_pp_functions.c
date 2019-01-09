#include <stdio.h>
#include <stdlib.h>

//#include "pp_shared.h"

#include <unistd.h>

#include <pthread.h>


typedef struct _pp_user_t {
  int wss;
  int reuse;
  int resource;
} pp_user_t;
          

long pp_start(pp_user_t*, unsigned long);
void pp_end(long, unsigned long);

void *do_pp_thread(void *ptr) {
  int *val = (int *) ptr;
  int pp_no = *val;
  pp_user_t pp;
  pp.wss = 20;
  pp.resource = 0;
  pp.reuse = 0;

  //unsigned long pp_no = 1;
 // ppid =  pp_begin(&pp, pp_no);
  usleep(20000000);
  //pp_end(ppid, pp_no);

  free(val);
}

int main(int argc, char *argv[]) {

  printf("In the main\n");
  int nt = 20;
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
