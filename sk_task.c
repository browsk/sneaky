#include <string.h>
#include "sk_task.h"

sk_task_info tasks[2];
int task_count = 0;

void sk_create_task(char tag[4], sk_task_entry_point task_func)
{
  sk_task_info *task = &tasks[task_count];
	memset(task, 0, sizeof(sk_task_info));
	memcpy(task, tag, sizeof(tag));
	task->entry_point = task_func;
	task->state = NEW;
}

sk_task_info *sk_ready_task();

void sk_startup()
{
	
}
