
#ifndef CHARACTER_DEV_H
#define CHARACTER_DEV_H

#include <linux/ioctl.h>


#define MAJOR_NUM 100


#define IOCTL_GET_INFO _IOR(MAJOR_NUM, 2, char *)


struct result
{
    int tgid;
    int task_prio;
    int task_link_count;
    unsigned int task_flags;

    unsigned int signal_flags;
    int signal_nr_threads;
    int signal_notify_count;
    int signal_group_exit_code;
    int signal_group_stop_count;
};


struct data
{
    int pid;
    struct result result;
};

#define DEVICE_NAME "test_device"
#define BUFFER_SIZE 1024
#endif