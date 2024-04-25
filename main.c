
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(){
    // Создаём маску заблокированных сигналов
    sigset_t mask;
    // Зануляем маску
    sigemptyset(&mask);
    // Добавляем в маску сигнал SIGUSR1
    sigaddset(&mask, SIGUSR1);
    // Блокируем сигналы в маске
    sigprocmask(SIG_BLOCK, (const sigset_t*)&mask, NULL);

    printf("My pid: %d\n", getpid());

    int sig = SIGUSR1;
    while(1){
        sigwait((const sigset_t*)&mask, &sig);
        printf("I received SIGUSR1!\n");
        break;
    }

    return 0;
}