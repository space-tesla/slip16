/*Write a C program that creates a child process to catch SIGHUP, SIGINT, and SIGQUIT signals. The parent process sends a SIGHUP or SIGINT signal every 3 seconds. After 30 seconds, the parent sends a SIGQUIT signal to the child, causing it to terminate with the message "My DADDY has Killed me!!!".*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sighup(int sig) { printf("Received SIGHUP\n"); }
void handle_sigint(int sig) { printf("Received SIGINT\n"); }
void handle_sigquit(int sig) { printf("My DADDY has Killed me!!!\n"); exit(0); }

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGHUP, handle_sighup);
        signal(SIGINT, handle_sigint);
        signal(SIGQUIT, handle_sigquit);
        while (1) pause();
    } else {
        for (int i = 0; i < 10; i++) {
            sleep(3);
            if (i % 2 == 0) kill(pid, SIGHUP);
            else kill(pid, SIGINT);
        }
        kill(pid, SIGQUIT);
    }

    return 0;
}


















/*Received SIGHUP
Received SIGINT
Received SIGHUP
Received SIGINT
Received SIGHUP
Received SIGINT
Received SIGHUP
Received SIGINT
Received SIGHUP
Received SIGINT
My DADDY has Killed me!!!
*/