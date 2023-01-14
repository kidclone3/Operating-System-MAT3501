#include<semaphore.h>
#include<stdio.h>    
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>

#define up(sem) sem_post(sem)
#define down(sem) sem_wait(sem)

// transfer money from account A to account B using semaphore

int accountA = 1000;
int accountB = 0;
int amount = 100;


void deposit() {
    account += amount;
}
void withdraw() {
    account -= amount;
}
void transfer(int *accountA, int *accountB, int amount) {
    withdraw(accountA, amount);
    deposit(accountB, amount);
}
void print_balance(int *accountA, int *accountB) {
    printf("Account A: %d\n", *accountA);
    printf("Account B: %d\n", *accountB);
}



int main() {
    int accountA = 1000;
    int accountB = 0;
    int amount = 100;
    pthread_t tid[4];
}