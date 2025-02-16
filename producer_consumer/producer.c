#include "process_helper.h"
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int shmid;
    char *shm;
    sem_t *sem;

    // Create shared memory, using default shared config inside process_helper.h file
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        log_err(PRODUCER, "shmget failed");
        exit(1);
    }

    // Attach shared memory
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (void *)-1)
    {
        log_err(PRODUCER, "shmat failed");
        exit(1);
    }

    // Create semaphore
    sem = sem_open(SEM_NAME, O_CREAT, 0666, 0);
    if (sem == SEM_FAILED)
    {
        log_err(PRODUCER, "sem_open failed");
        exit(1);
    }

    // Read and produce message in shared memory
    log_info(PRODUCER, "Enter message: ");
    fgets(shm, SHM_SIZE, stdin);
    shm[strcspn(shm, "\n")] = '\0'; // Remove newline char

    // Signal consumer
    sem_post(sem);

    log_info(PRODUCER, "Message saved");

    // Detach shared memory
    shmdt(shm);

    return 0;
}
