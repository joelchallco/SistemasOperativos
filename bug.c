* Locate the segment.
     /
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char ) -1) {
        perror("shmat");
        exit(1);
    }

    /
     * Now read what the server put in the memory.
     /

    strcpy(nombre,shm);
    printf("%s\n", nombre);



    /
     * Finally, change the first character of the
     * segment to '*', indicating we have read
     * the segment.
     */
    shm = '';

    exit(0);
}
//////////////////////////////////
////////////////////////////////////
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SHMSZ     27

typedef struct{
        char nombre[10];
        char apellido[10];
        int edad;
        long dni;
}data;

main()
{
    data myS;
    int shmid;
    key_t key;
    char *shm, s,n,a,e,d;

    strcpy(myS.nombre,"Fabrizio");
    strcpy(myS.apellido,"Rosado");
    myS.edad=19;
    myS.dni=72665314;


    /
     * We'll name our shared memory segment
     * "5678".
     /
    key = 5678;

    /
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char ) -1) {
        perror("shmat");
        exit(1);
    }

    /
     * Now put some things into the memory for the
     * other process to read.
     /

    n = shm;
   / a = shm;
    e = shm;
    d = shm;/
char nombre[10];
strcpy(nombre,myS.nombre);
strcpy(n,nombre);
/strcpy(a,myS.apellido);
strcpy(e,myS.edad);
strcpy(d,myS.dni);/


    /int i;
    for(i=0;c[i]!='\0';i++)
        *s++ = c[i];
    s = NULL;/

    /*
     * Finally, we wait until the other process
     * changes the first character of our memory
     * to '*', indicating that it has read what
     * we put there.
     /
    while (shm != '*')
        sleep(1);

    exit(0);
}
