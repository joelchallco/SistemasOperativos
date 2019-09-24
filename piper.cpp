// ucsp@ubuntu:~/lab03.1$ cat piper.cpp
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;


#define MAX_BUF 1024

int main()
{
int fd;
char * myfifo = "/tmp/myfifo";

int n;
char buff[1000];
string str;


do{

fd = open(myfifo, O_RDONLY);
n = read (fd, buff, 1000);
buff[n]='\0';
cout<<buff<<endl;
close(fd);

fd = open(myfifo, O_WRONLY);
cout << "enter msg : ";
getline(cin,str);
write(fd, str.c_str(), str.size());
close(fd);

}while(str.compare("end")!=0);

return 0;
}
