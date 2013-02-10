#if !defined(_TASK_H)
#define _TASK_H

#include <stdint.h>

typedef void (*sk_task_entry_point)();

typedef enum 
{
	NEW,
	READY,
	RUNNING,
	BLOCKED
} sk_task_state;

#define SK_TASK_STACK	64

typedef struct {
	char tag[4];
	sk_task_entry_point entry_point;

	sk_task_state  state;
	
	// processor info
	uint8_t registers[32];
  uint8_t status;
  uint8_t stack_pointer;
 
	uint8_t stack[SK_TASK_STACK];
		
} sk_task_info;

void sk_create_task(char tag[4], sk_task_entry_point task_func);

sk_task_info *sk_ready_task();

void sk_startup();
#endif
