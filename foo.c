// gcc -o dupCMDfoo.exe dupCMDfoo.c

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

int int main(int argc, char const *argv[]) {
  ofd = open(output,O_RDONLY);
  dup2(ofd,0);

  char* input = argv[1];
  char** doubleArgument = malloc(sizeof(char*)* 4);
  doubleArgument[0] = input; // grep
  doubleArgument[1] = argv[2]; // exe
  doubleArgument[2] = NULL;
  doubleArgument[3] = NULL;
  execvp(input, doubleArgument); // input= path mas ejecutable ; doubleArgument = parametros del programa
  return 0;
}
