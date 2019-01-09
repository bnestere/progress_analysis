#define NR_PP_BEGIN 329
#define NR_PP_END 330
#define NR_PP_PRINT 331
#define NR_PP_RESET 332

typedef struct pp_user_t pp_user_t;

struct pp_user_t {
	int wss;
	int reuse;
	int resource;
};

long pp_begin(pp_user_t *user_d);
void pp_end(long);
void pp_print_queues(void);
void pp_reset(void);
