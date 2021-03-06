#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#define PWD "0000"

//Show signal
void afficheSig(int sig) {
    printf("Sig : %d reçu \n", sig);
}


//Treat the password
void askPassWord() {
    char pwd[20];
    printf("ENTRER YOUR PASS WORD : ");
    scanf("%s", &pwd);
    if(!strcmp(pwd, PWD)) {
        signal(SIGINT, SIG_DFL);
        kill(getpid(), SIGINT);
    }
}


int main(int argn, char ** args) {

    if( signal(SIGINT, &askPassWord) == SIG_ERR ) 
        printf("Can't catch CTRL-C \n");
    if( signal(SIGSTOP, SIG_IGN) == SIG_ERR ) 
        printf("Can't catch CTRL-Z \n");
    
    signal(SIGTERM, &afficheSig);


    while(1) {
        printf("Tic\n");
        sleep(1);
    }
}
