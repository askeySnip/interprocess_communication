#ifndef WRAPPER_FUNC_H_
#define WRAPPER_FUNC_H_

#include "myerror.h"

void
Pipe(int fd[2]);

pid_t
Fork();

void
Close(int fd);

void
Waitpid(pid_t pid, int* status, int options);

void
Fgets(char* str, int num, FILE* stream);

void
Write(int fd, const void* buf, size_t len);

ssize_t
Read(int fd, void* buf, size_t len);

FILE*
Popen(const char* command, const char* type);

void
Fputs(const char* str, FILE* stream);

void
Pclose(FILE* stream);

#endif
