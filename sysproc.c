#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

#define NULL 0

    int
sys_fork(void)
{
    return fork();
}

// modified in lab 1 CS153
    int
sys_exit(void)
{
    int s;
    if (argint(0, &s) < 0)
    {
        return -1;
    }
    exit(s);
    return 0;  // not reached
}

// added in lab 1 CS153
    int
sys_waitpid(void)
{
    int pid;
    int * status;
    int options = 0;
    if (argint(0, &pid) < 0)
    {
        return -1;
    }

    if (argptr(1, (char **) &status, sizeof(int*)) < 0)
    {
        return -1;
    }
    return waitpid(pid, status, options);
}

// CS153
    int
sys_wait(void)
{
    int * w;
    if (argptr(0, (char **) &w, sizeof(int*)) < 0)
    {
        return -1;
    }
    return wait(w);
}

    int
sys_kill(void)
{
    int pid;

    if(argint(0, &pid) < 0)
        return -1;
    return kill(pid);
}

    int
sys_getpid(void)
{
    return myproc()->pid;
}

    int
sys_sbrk(void)
{
    int addr;
    int n;

    if(argint(0, &n) < 0)
        return -1;
    addr = myproc()->sz;
    if(growproc(n) < 0)
        return -1;
    return addr;
}

    int
sys_sleep(void)
{
    int n;
    uint ticks0;

    if(argint(0, &n) < 0)
        return -1;
    acquire(&tickslock);
    ticks0 = ticks;
    while(ticks - ticks0 < n){
        if(myproc()->killed){
            release(&tickslock);
            return -1;
        }
        sleep(&ticks, &tickslock);
    }
    release(&tickslock);
    return 0;
}

// return how many clock tick interrupts have occurred
// since start.
    int
sys_uptime(void)
{
    uint xticks;

    acquire(&tickslock);
    xticks = ticks;
    release(&tickslock);
    return xticks;
}

// CS153
    int
sys_setpriority(void)
{
    int priority;
    // it's a stack of variables
    if (argint(0, &priority) < 0)
        return -1;

    return setpriority(priority);
}
