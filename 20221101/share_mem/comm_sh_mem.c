#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include "comm_sh_mem.h"

int shm_init(key_t key_id, int size)
{
	int shmid;
	void *p;

	shmid = shmget(key_id, size, IPC_CREAT | 0666);
	if (shmid == -1){
		printf("shmget error.\n");
		return -1;
	}

	p = shmat(shmid, 0, 0);
	if (p < 0){
		printf("shmget error.\n");
		return -1;
	}

	if(0 > shmdt(p)){
		printf("shmdt error.\n");
	}

	return 0;	
}


void *shm_get(key_t key_id)
{
	int shmid;
	void *p;

	shmid = shmget(key_id, 0, 0);
	if (shmid == -1){
		printf("shmget error!\n");
		return NULL;
	}

	p = shmat(shmid, 0, 0);
	if (p < 0){
		printf("shmat error.\n");
		return NULL;
	}

	return p;
}


int my_write(void)
{
	int *pdata;

	pdata = shm_get(MY_KEY_ID);
	if (NULL == pdata)
		return -1;

	*pdata = 0x12345678;

	return 0;
}

int my_read(void)
{

	int *pdata;

	pdata = shm_get(MY_KEY_ID);
	if (NULL == pdata)
		return -1;

	printf("read shm data %x\n", *pdata);
	return 0;
}

int main(void)
{
	int iret;
	iret = shm_init(MY_KEY_ID, 8);
	if (iret != 0)
		printf("shm_init error\n");

	return 0;
}





