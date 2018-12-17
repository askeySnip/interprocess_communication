#ifndef MYERROR_H_
#define MYERROR_H_
#include "unpipc.h"

void myerr_sys(const char*, ...);
void err_quit(const char* fmt, ...);
#endif
