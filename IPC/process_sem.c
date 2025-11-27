#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main()
{
	int semid, pid;
	struct sembuf sop;
	
	//TODO 1: Allocate the semaphore with semget
	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | S_IRUSR | S_IWUSR);
	//semid = semget(0x20, 1, IPC_CREAT | S_IRUSR | S_IWUSR);
	//TODO 2: Set the semaphore value to 1 with semctl
	semctl(semid, 0, SETVAL, 1);

	pid = fork();
	if (pid == 0)
	{
		printf("Child before semop\n");
		//TODO 3: Populate the sembuf to decrement the first semaphore
		//Set sem_flg to 0
		sop.sem_num = 0; 
		sop.sem_op = -1;
		sop.sem_flg = 0;
		//TODO 4: Finally invoke the semop
		semop(semid, &sop, 1);
		printf("Child in critical section for 10 seconds\n");
		printf("Parent may have to wait\n");
		sleep(10);
		printf("Child coming out of critical section\n");
		//TODO 5: Populate the sembuf to increment the first semaphore
		//Set sem_flg to 0
		sop.sem_num = 0; 
		sop.sem_op = 1; 
		sop.sem_flg = 0;
		//TODO 6: Finally invoke the semop
		semop(semid, &sop, 1);
	}
	else
	{
		int child_status;

		printf("Parent before semop\n");
		//TODO 7: Populate the sembuf to decrement the first semaphore
		//Set sem_flg to 0
		sop.sem_num = 0; 
		sop.sem_op = -1;
		sop.sem_flg = 0;
		//TODO 8: Finally invoke the semop
		semop(semid, &sop, 1);
		printf("Parent in critical section\n");
		printf("Child may have to wait\n");
		sleep(10);
		printf("Parent coming out of critical section\n");
		//TODO 9: Populate the sembuf to increment the first semaphore
		//Set sem_flg to 0
		sop.sem_num = 0; 
		sop.sem_op = 1; 
		sop.sem_flg = 0;
		//TODO 10: Finally invoke the semop
		semop(semid, &sop, 1);

		//wait(&child_status);
		//semctl(semid, 0, IPC_RMID);
	}

	return 0;
}
