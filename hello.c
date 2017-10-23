#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

#define NULL 0

void hello();
void wait_example();

int main(int argc, char * argv[])
{
    wait_example();
    // hello();
    return 0;
}

void hello()
{
    int stdout = 1;
    printf(stdout, "Hello World!\n");
}

void wait_example()
{
    int pid = 0;
    if (fork() == 0)
    {
        exit(0);
    }
    else
    {
        pid = wait(NULL);
    }
    printf(1, "Parent pid = %d\n", getpid());
    printf(1, "Child pid = %d\n", pid);
}
