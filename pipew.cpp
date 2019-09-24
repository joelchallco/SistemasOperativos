// ucsp@ubuntu:~/lab03.1$ cat pipew.cpp
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
int fd;
int n;
char * myfifo = "/tmp/myfifo";
char buff[1000];
string str;
/* create the FIFO (named pipe) */
mkfifo(myfifo, 0666);

do{

fd = open(myfifo, O_WRONLY);
cout << "enter msg : ";
getline(cin,str);
write(fd, str.c_str(), str.size());
close(fd);

fd = open(myfifo, O_RDONLY);
n = read (fd, buff, 1000);
buff[n]='\0';
cout<<buff<<endl;
close(fd);

}while(str.compare("end")!=0);

/* remove the FIFO */
unlink(myfifo);

return 0;
}
