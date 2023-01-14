#include<semaphore.h>
#include<stdio.h>    
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>

#define up(sem) sem_post(sem)
#define down(sem) sem_wait(sem)

sem_t cars, customers, mutex;

int count = 0;
const int N = 5;

void tao_xe() {
    up(&cars);
    printf("Da tao xe\n");
}
void tao_khach() {
    up(&customers);
    printf("Da tao khach\n");
}
void ghep_chuyen() {
    down(&cars);
    down(&customers);
    // down(&mutex);
    count++;
    printf("So chuyen da ghep duoc: %d\n", count);
    // up(&mutex);
}

int main() {
    sem_init(&cars, 0, N);
    sem_init(&customers, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_t tid[N];
    int i;
    for (i = 0; i < N; i++) {
        pthread_create(&tid[i], NULL, tao_xe, NULL);
        sleep(0.05);
        pthread_create(&tid[i], NULL, tao_khach, NULL);
        sleep(0.05);

        pthread_create(&tid[i], NULL, ghep_chuyen, NULL);
        sleep(0.1);

    }
}
