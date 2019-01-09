#define NR_PP_BEGIN 329
#define NR_PP_END 330
#define NR_PP_PRINT 331
#define NR_PP_RESET 332

typedef struct _pp_user_t {
  int pid;
  int tid;
  int wss;
  int reuse;
  int sync_group;
  int sync_type_id;
  int n_syncing_threads;
  int resource;
} pp_user_t;

long pp_begin(pp_user_t *user_d, int pp_no);
void pp_end(long pp_id, int pp_no);

long _do_pp_begin_call(pp_user_t *user_d); // used internally, do not call
long _do_pp_end_call(long pp_id); // used internally, do not call
