#include "queue.h"
#include "task.h"
#include "cpu.h"
#include "schedulers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// add a task to the list
void add(Queue *queue, char *name, int priority, int burst)
{
   fprintf(stdout, "Adding task to queue\n");

   /*int tid = queue->length + 1;

   Task *task = (Task *)malloc(sizeof(Task));
   if (task == NULL)
   {
      // Handle memory allocation failure
      fprintf(stderr, "Memory allocation failed\n");
      return;
   }

   task->name = strdup(name);
   task->tid = tid;
   task->priority = priority;
   task->burst = burst;

   enqueue(queue, task);*/
}

// select a task from the queue
Task *pickNextTask(Queue *queue)
{
   fprintf(stdout, "Picking next task\n");

   /*return dequeue(queue);*/
}

// invoke the scheduler
void schedule(Queue *queue)
{
   fprintf(stdout, "Running the schedule\n");
   /*while (queue->length > 0)
   {
      Task *task = pickNextTask(queue);
      run(task, QUANTUM);
      free(task);
   }*/
}
