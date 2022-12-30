#include "character_dev.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


// USAGE: client <PID> <PAGE_NUMBER>
int main(int argc, char **argv)
{
    int fd;

    // Check for unput and print help

    if (argc < 2 || (strcmp(argv[1], "help") == 0))
    {
        printf("USAGE: %s <PID> <PAGE_NUMBER>\n", argv[0]);
        return 0;
    }
    
    struct data *dt = malloc(sizeof(struct data));
    dt->pid = atoi(argv[1]);

    if (!dt->pid)
    {
        printf("Wrong <PID>\n");
        return 1;
    }

    fd = open(DEVICE_NAME, 0);

    if (fd < 0)
    {
        printf("Can't open device file: %s\n", DEVICE_NAME);
        exit(2);
    }

    int ret = ioctl(fd, IOCTL_GET_INFO, dt);
    if (ret != 0)
    {
        printf("IOCTL_GET_INFO failed %d: process with <PID> = %d doesn't exist\n", ret, dt->pid);
        exit(ret);
    }

    printf("TASK_STRUCT\n");
    printf("pid = %d\n", dt->pid);
    printf("prio = %x\n", dt->result.task_prio);
    printf("tgid = %d\n", dt->result.tgid);
    printf("flags = %x\n", dt->result.task_flags);
    printf("prio = %x\n", dt->result.task_prio);

    printf("SIGNAL_STRUCT\n");
    printf("flags = %x\n", dt->result.signal_flags);
    printf("notify_count = %x\n", dt->result.signal_notify_count);
    printf("nr_threads = %x\n", dt->result.signal_nr_threads);
    printf("sig_group_stop_count = %x\n", dt->result.signal_group_stop_count);
    printf("sig_group_exit_code = %x\n", dt->result.signal_group_exit_code);
    return 0;
}
