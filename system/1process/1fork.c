#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    /*
        pid_t fork(void);
        Clone the calling process, creating an exact copy.
        Return -1 for errors, 0 to the new process,
        and the process ID of the new process to the old process.
    */
    /*  克隆一个新进程，新进程的代码和数据从父进程而来
        数据在修改的时候才会发生复制，称为写时拷贝
        pid_t fork(void);
        返回 -1 表示出错
        子进程会返回 0
        父进程会返回新进程的 pid
    */
    pid_t id = fork();

    if (id == 0)
    {
        printf("this is child\n");
        exit(0);
    }

    /*
        pid_t waitpid(pid_t __pid, int *__stat_loc, int __options)

        // 等待一个子进程死亡
        Wait for a child matching PID to die.
        // pid大于0，则等待id为pid的进程
        If PID is greater than 0, match any process whose process ID is PID.
        // pid为-1，等待任意进程
        If PID is (pid_t) -1, match any process.
        //
        If PID is (pid_t) 0, match any process with the same process group as the current process.
        If PID is less than -1, match any process whose process group is the absolute value of PID.
        If the WNOHANG bit is set in OPTIONS, and that child is not already dead, return (pid_t) 0.
        If successful return PID and store the dead child's status in STAT_LOC.
        Return (pid_t) -1 for errors. If the WUNTRACED bit is
        set in OPTIONS, return status for stopped children; otherwise don't.

        此函数没有异常机制而被废弃
        This function is a cancellation point and therefore not marked with __THROW.
     */
    printf("this is father\n");
    waitpid(id, NULL, 0);

    return 0;
}