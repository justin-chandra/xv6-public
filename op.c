#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

    int
main(int argc, char *argv[])
{

    int pid = 0;
    int pid2 = 0;
    int status;
    //  int options = 0;
    /*
       if(pid != 0){
    // printf(1, "I am a parent, this can print first\n");
    waitpid(pid, &status, options);
    printf(1, "I am a parent, this cannot print before child\n");
    }
    else{
    printf(1, "I am a child!!!!\n");
    }
    */
    pid = fork();
    if(pid == 0){
	pid2 = fork();
	printf(1,"print %d\n",pid2);
	exit(0);
    }
    else{
	wait(&status);
	printf(1,"last thing\n");
    }
    exit(0);
    return 0;
}
