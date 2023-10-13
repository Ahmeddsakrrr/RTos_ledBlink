/*
 * Rtos.c
 *
 *  Created on: Oct 13, 2023
 *      Author: A M
 */

#include "std_types.h"
#include "Rtos.h"
Task array [numberoftasks]; /*Creating an array of OS tasks (from Task sruct)*/
volatile uint16 gl_counter = 0; /*Tick counts that will be incrementing every 1 ms*/
void create_task(uint8 priority , uint16 periodicity , void (*Fptr)(void))
{
array[priority].Periodicity = periodicity;
array[priority].Fptr = Fptr;
}
void Scheduler(void)
{
	uint8 counter;
		/*Counter to loop over all tasks*/

		/*For loop to check if periodicity of the highest priority task corresponds to ticks count*/
		for(counter = 0; counter < numberoftasks; counter++)
		{
			if((gl_counter % array[counter].Periodicity) == 0)

			{
				array[counter].Fptr();

			}

			else
			{
				/*Do nothing*/
			}
		}

}
