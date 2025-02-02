#ifndef __STACKPLZ_TYPES_H__
#define __STACKPLZ_TYPES_H__

#include "vmlinux_510.h"
#include "common/consts.h"

typedef struct common_filter {
    u32 is_32bit;
    u32 trace_mode;
    u32 trace_uid_group;
    u32 signal;
} common_filter_t;

typedef struct args {
    unsigned long args[6];
    u32 flag;
} args_t;

typedef struct match_ctx {
    u32 apply_filter;
    u32 match_whitelist;
    u32 match_blacklist;
} match_ctx_t;

typedef struct thread_name {
    char name[16];
} thread_name_t;

typedef struct arg_filter {
    u32 filter_type;
    u32 filter_index;
    u64 num_val;
    char oldstr_val[256];
    u32 oldstr_len;
    char newstr_val[256];
    u32 newstr_len;
} arg_filter_t;

typedef struct str_buf {
    char str_val[256];
} str_buf_t;

enum arg_filter_e
{
    UNKNOWN_FILTER = 0,
    EQUAL_FILTER,
    GREATER_FILTER,
    LESS_FILTER,
    WHITELIST_FILTER,
    BLACKLIST_FILTER,
    REPLACE_FILTER
};

typedef struct config_entry {
    u32 stackplz_pid;
    u32 thread_whitelist;
} config_entry_t;

enum trace_group_e
{
    GROUP_NONE = 1 << 0,
    GROUP_ROOT = 1 << 1,
    GROUP_SYSTEM = 1 << 2,
    GROUP_SHELL = 1 << 3,
    GROUP_APP = 1 << 4,
    GROUP_ISO = 1 << 5,
};

enum event_id_e
{
    SYSCALL_ENTER = 456,
    SYSCALL_EXIT,
    UPROBE_ENTER
};

enum arm64_reg_e
{
    REG_ARM64_X0 = 0,
    REG_ARM64_X1,
    REG_ARM64_X2,
    REG_ARM64_X3,
    REG_ARM64_X4,
    REG_ARM64_X5,
    REG_ARM64_X6,
    REG_ARM64_X7,
    REG_ARM64_X8,
    REG_ARM64_X9,
    REG_ARM64_X10,
    REG_ARM64_X11,
    REG_ARM64_X12,
    REG_ARM64_X13,
    REG_ARM64_X14,
    REG_ARM64_X15,
    REG_ARM64_X16,
    REG_ARM64_X17,
    REG_ARM64_X18,
    REG_ARM64_X19,
    REG_ARM64_X20,
    REG_ARM64_X21,
    REG_ARM64_X22,
    REG_ARM64_X23,
    REG_ARM64_X24,
    REG_ARM64_X25,
    REG_ARM64_X26,
    REG_ARM64_X27,
    REG_ARM64_X28,
    REG_ARM64_X29,
    REG_ARM64_LR,
    REG_ARM64_SP,
    REG_ARM64_PC,
    REG_ARM64_MAX
};

enum arg_type_e
{
	TYPE_NONE = 0,
	TYPE_NUM,
	TYPE_EXP_INT,
	TYPE_INT,
	TYPE_UINT,
	TYPE_INT16,
	TYPE_UINT16,
	TYPE_INT32,
	TYPE_UINT32,
	TYPE_INT64,
	TYPE_UINT64,
	TYPE_STRING,
	TYPE_STRING_ARR,
	TYPE_POINTER,
	TYPE_STRUCT,
	TYPE_TIMESPEC,
	TYPE_STAT,
	TYPE_STATFS,
	TYPE_SIGACTION,
	TYPE_UTSNAME,
	TYPE_SOCKADDR,
	TYPE_RUSAGE,
	TYPE_IOVEC,
	TYPE_EPOLLEVENT,
	TYPE_SIGSET,
	TYPE_POLLFD,
	TYPE_ARGASSIZE,
	TYPE_SYSINFO,
	TYPE_SIGINFO,
	TYPE_MSGHDR,
	TYPE_ITIMERSPEC,
	TYPE_STACK_T,
	TYPE_TIMEVAL,
	TYPE_TIMEZONE,
	TYPE_PTHREAD_ATTR,
	TYPE_BUFFER_T,
};

enum point_flag_e
{
	FORBIDDEN = 0,
	SYS_ENTER_EXIT,
	SYS_ENTER,
	SYS_EXIT,
	UPROBE_ENTER_READ
};

typedef struct event_context {
    u64 ts;
    u32 eventid;
    u32 host_tid;
    u32 host_pid;
    u32 tid;
    u32 pid;
    u32 uid;
    char comm[TASK_COMM_LEN];
    u8 argnum;
    char padding[7];
} event_context_t;

typedef struct event_data {
    event_context_t context;
    char args[ARGS_BUF_SIZE];
    u32 buf_off;
    struct task_struct *task;
} event_data_t;

#define MAX_EVENT_SIZE sizeof(event_context_t) + ARGS_BUF_SIZE

typedef struct program_data {
    config_entry_t *config;
    event_data_t *event;
    void *ctx;
} program_data_t;

typedef struct simple_buf {
    u8 buf[MAX_PERCPU_BUFSIZE];
} buf_t;


typedef struct vma_arg {
    u64 vma_ptr;
} vma_arg_t;

#define MAX_CACHED_PATH_SIZE 64

typedef u32 __kernel_dev_t;

typedef __kernel_dev_t dev_t;

typedef struct file_info {
    union {
        char pathname[MAX_CACHED_PATH_SIZE];
        char *pathname_p;
    };
    dev_t device;
    unsigned long inode;
    u64 ctime;
} file_info_t;

#endif