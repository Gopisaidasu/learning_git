#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 0x12324  // unique key for semaphore

int main() {
    int semid;

    // Step 1: Create (or get) a semaphore set with 1 semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }
    printf("Semaphore created with ID = %d\n", semid);

    // Step 2: Initialize the semaphore value to 1
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;

    arg.val = 1;  // initial value = 1 (unlocked)
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl - SETVAL");
        exit(1);
    }
    printf("Semaphore initialized to 1\n");

    // Step 3: Perform some example operations (optional)
    struct sembuf sb;

    printf("Waiting (P operation)...\n");
    sb.sem_num = 0;  // semaphore number
    sb.sem_op = -1;  // P operation (decrement / wait)
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
    printf("Semaphore locked\n");

    sleep(3);  // simulate some critical section

    printf("Signaling (V operation)...\n");
    sb.sem_op = 1;   // V operation (increment / signal)
    semop(semid, &sb, 1);
    printf("Semaphore unlocked\n");

    // Step 4: Remove semaphore after use
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl - IPC_RMID");
        exit(1);
    }
    printf("Semaphore removed successfully\n");

    return 0;
}

