#include "../header/myerror.h"

void
Pipe(int fd[2]) {
  if (pipe(fd) == -1)
    myerr_sys("pipe error");
}

pid_t
Fork() {
  pid_t pid;
  if((pid = fork()) == -1)
    myerr_sys("fork error");
  return pid;
}

void
Close(int fd) {
  if(close(fd) == -1)
    myerr_sys("close error");
}

void
Waitpid(pid_t pid, int* status, int options) {
  if(waitpid(pid, status, options) == -1)
    myerr_sys("waitpid error");
}

void
Fgets(char* str, int num, FILE* stream) {
  if(fgets(str, num, stream) == NULL)
    myerr_sys("fgets error");
}

void
Write(int fd, const void* buf, size_t len) {
  if(write(fd, buf, len) == -1)
    myerr_sys("write error");
}

ssize_t
Read(int fd, void* buf, size_t len) {
  ssize_t n;
  if((n = read(fd, buf, len)) == -1)
    myerr_sys("read error");
  return n;
}

FILE*
Popen(const char* command, const char* type) {
  FILE* fd;
  if((fd = popen(command, type)) == NULL)
    myerr_sys("popen error");
  return fd;
}
void
Fputs(const char* str, FILE* stream) {
  if(fputs(str, stream) == EOF)
    myerr_sys("fputs error");
}

void
Pclose(FILE* stream) {
  if(pclose(stream) == -1)
    myerr_sys("pclose error");
}

