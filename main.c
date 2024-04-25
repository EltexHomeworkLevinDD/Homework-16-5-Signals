
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int g_exit_flag = 0;

void usr_handler(){
    printf("I received SIGUSR1!\n");
    g_exit_flag = 1;
}

int main(){
    struct sigaction action;
    // Устанавливаем обработчик
    action.sa_handler = usr_handler;
    // Зануляем маску сигналов
    sigemptyset(&action.sa_mask);
    // Устанавливаем флаги
    action.sa_flags = 0;

    if (sigaction(SIGUSR1, &action, NULL) == -1){
        perror("sigaction()");
        exit(EXIT_FAILURE);
    }

    printf("My pid: %d\n", getpid());

    while(g_exit_flag == 0){

    }

    return 0;
}