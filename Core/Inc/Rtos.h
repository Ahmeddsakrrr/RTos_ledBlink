/*
 * Rtos.h
 *
 *  Created on: Oct 13, 2023
 *      Author: A M
 */

#ifndef INC_RTOS_H_
#define INC_RTOS_H_
#include "std_types.h"
#define numberoftasks 3
#define priority_0		 0
#define priority_1 		 1
#define priority_2  	 2

typedef struct
{
	uint16 Periodicity;
	void(*Fptr)(void);
}Task;

void Scheduler(void);
void create_task(uint8 priority , uint16 periodicity , void (*Fptr)(void));


#endif /* INC_RTOS_H_ */
