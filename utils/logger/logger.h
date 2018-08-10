#ifndef __LOGGER_H__
#define __LOGGER_H__ 

#include<errno.h>

extern int errno;

#define STD_OUT 0;
#define STD_ERR 2;
#define DEFAULT_LEVEAL "debug"

void fatal();

void error();

void debug();

void warn();

void __write_stream();

void __write_stack();

void __write_file();

extern char * __get_file_name();

extern char * __get_log_line();

#endif
