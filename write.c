#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>

// run as : b.exe CMD INPUT_FILE
// b.exe grep exe foo

int main(int argc, char* argv[])
{


pid_t pid;
int ofd;
char *cmd, *input;

cmd = argv[1];
input = argv[3];

pid = fork();
if(pid==0) // Child
{
//ejecutar-----> ./write arc1 arc2 > arc3
// printf("Running %s %s < %s\n",cmd,argv[2],input);
// ofd=open(input,O_RDONLY);
// dup2(ofd,0); // same as: close(1); dup(odf);
// execlp(cmd, cmd, (char*) NULL);

//ejecutar-----> ./write arc1 arc2 >> arc3
printf("Running %s %s << %s\n",cmd,argv[2],input);
ofd = open(input, O_WRONLY|O_APPEND);
dup2(ofd,1);
// execlp(cmd,cmd, (char*) NULL);

char** M = malloc(sizeof(char*) * 3) ;
M[0] = cmd ;
M[1] = argv[2] ;
M[2] = NULL ;
execvp(cmd, M) ;
}
wait((int *)NULL);
}
