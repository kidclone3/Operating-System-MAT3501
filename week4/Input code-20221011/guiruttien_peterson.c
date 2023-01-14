#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define DELAY	sleep(rand() % 4)

int account; // tai khoan ngan hang
int turn;
int interest[2];

enter_region(int pid) {
	int other;
	// ...;
	// ...;
	// ...;
	// ...;
	other = 1-pid;
	interest[pid] = TRUE;
	turn = pid;
	while ((turn == pid) && (interest[other] == TRUE)) {

	}
}

leave_region(int pid) {
	// ...;
	interest[pid] = FALSE;
}

void *chaGuiTien() {  // luot =0
	int x;
	while (TRUE) {
		enter_region(0); 
		x = account;
		x += 2;
		account = x;
		leave_region(0);
		printf("Bo: Tao da gui %d. Account=%d\n",2, account);
		DELAY;
	}
}

void *conRutTien() { // luot =1
	int y;
	while (TRUE) {
		enter_region(1); 
		y = account;
		if (y >= 3) {
			y -= 3;
			account = y;
			printf("Con: Con da rut %d. Account=%d\n", 3, account);
		} else {
			printf("So du khong du\n");
		}
		leave_region(1); 
		DELAY;
		
	}
}

void main() {
   pthread_t tid1, tid2;
   
   printf("Account=%d\n",account);
   pthread_create(&tid1, NULL, chaGuiTien, NULL);   
   pthread_create(&tid2, NULL, conRutTien, NULL);   
   
   pthread_join(tid1, NULL);  
   pthread_join(tid2, NULL);  
}
