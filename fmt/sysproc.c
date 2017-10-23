3750 #include "types.h"
3751 #include "x86.h"
3752 #include "defs.h"
3753 #include "date.h"
3754 #include "param.h"
3755 #include "memlayout.h"
3756 #include "mmu.h"
3757 #include "proc.h"
3758 
3759     int
3760 sys_fork(void)
3761 {
3762     return fork();
3763 }
3764 
3765     int
3766 sys_exit(void)
3767 {
3768     int s;
3769     if (argint(0, &s) < 0)
3770     {
3771         return -1;
3772     }
3773     exit(s);
3774     return 0;  // not reached
3775 }
3776 
3777     int
3778 sys_waitpid(void)
3779 {
3780     return 0;
3781     // return waitpid();
3782 }
3783 
3784     int
3785 sys_wait(void)
3786 {
3787     int w;
3788     if (argint(0, &w) < 0)
3789     {
3790         return -1;
3791     }
3792     return wait(&w);
3793 }
3794 
3795 
3796 
3797 
3798 
3799 
3800     int
3801 sys_kill(void)
3802 {
3803     int pid;
3804 
3805     if(argint(0, &pid) < 0)
3806         return -1;
3807     return kill(pid);
3808 }
3809 
3810     int
3811 sys_getpid(void)
3812 {
3813     return myproc()->pid;
3814 }
3815 
3816     int
3817 sys_sbrk(void)
3818 {
3819     int addr;
3820     int n;
3821 
3822     if(argint(0, &n) < 0)
3823         return -1;
3824     addr = myproc()->sz;
3825     if(growproc(n) < 0)
3826         return -1;
3827     return addr;
3828 }
3829 
3830     int
3831 sys_sleep(void)
3832 {
3833     int n;
3834     uint ticks0;
3835 
3836     if(argint(0, &n) < 0)
3837         return -1;
3838     acquire(&tickslock);
3839     ticks0 = ticks;
3840     while(ticks - ticks0 < n){
3841         if(myproc()->killed){
3842             release(&tickslock);
3843             return -1;
3844         }
3845         sleep(&ticks, &tickslock);
3846     }
3847     release(&tickslock);
3848     return 0;
3849 }
3850 // return how many clock tick interrupts have occurred
3851 // since start.
3852     int
3853 sys_uptime(void)
3854 {
3855     uint xticks;
3856 
3857     acquire(&tickslock);
3858     xticks = ticks;
3859     release(&tickslock);
3860     return xticks;
3861 }
3862 
3863 
3864 
3865 
3866 
3867 
3868 
3869 
3870 
3871 
3872 
3873 
3874 
3875 
3876 
3877 
3878 
3879 
3880 
3881 
3882 
3883 
3884 
3885 
3886 
3887 
3888 
3889 
3890 
3891 
3892 
3893 
3894 
3895 
3896 
3897 
3898 
3899 
