#include<semaphore.h>
#include<stdio.h>    
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>

#define up(sem) sem_post(sem)
#define down(sem) sem_wait(sem)

sem_t mutex, players;
const int N = 5; // so luong khach toi da.
int numPlayer = 0;
int counter = 0;

void them_nguoi() {
    up(&players);
    down(&mutex);
    numPlayer++;
    printf("Da them nguoi choi\n");
    up(&mutex);
}

void truot_ong() {
    down(&players);
    down(&players);
    down(&mutex);
    numPlayer-=2;
    counter++;
    printf("So cap khach da truot ong: %d\n", counter);
    printf("Con lai %d nguoi choi\n", numPlayer);
    up(&mutex);
}


int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&players, 0, 0);
    pthread_t tid[N];
    int i;
    for (i = 0; i < N; i++) {
        pthread_create(&tid[i], NULL, them_nguoi, NULL);
        pthread_create(&tid[i], NULL, them_nguoi, NULL);
        pthread_create(&tid[i], NULL, truot_ong, NULL);
        // sleep(1);
    }

}