#include "process_helper.h"
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int shmid;
    char *shm;
    sem_t *sem;

    // Access shared memory, using default shared config inside process_helper.h file
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid == -1)
    {
        log_err(CONSUMER, "shmget failed");
        exit(1);
    }

    // Attach shared memory
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (void *)-1)
    {
        log_err(CONSUMER, "shmat failed");
        exit(1);
    }

    // Open existing semaphore to ensure producer complete process
    sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED)
    {
        log_err(CONSUMER, "sem_open failed");
        exit(1);
    }

    // Wait for producer
    sem_wait(sem);

    // Read message
    log_info(CONSUMER, shm);

    // Detach shared memory
    shmdt(shm);

    // Cleanup shared memory and semaphore
    shmctl(shmid, IPC_RMID, NULL);
    sem_close(sem);
    sem_unlink(SEM_NAME);

    return 0;
}
