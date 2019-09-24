#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SHMSZ     27


struct data{
  char name[10];
  char lastname[10];
  char age[2];
  char dni[8];
};

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 5678;

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    struct data persona;
    printf("Nombre: -----" );
    scanf("%s", persona.name);
    printf("Apellido: ---" );
    scanf("%s", persona.lastname);
    printf("Edad: -------" );
    scanf("%s", persona.age);
    printf("DNI: --------" );
    scanf("%s", persona.dni);

    // tamaño de la estructura
    char mensaje[30];
    // mensaje = (char) malloc(30);

    // s = shm;
    // *mensaje++ = persona.name;
    // *mensaje++ = persona.lastname;
    // *mensaje++ = persona.age;
    // *mensaje++ = persona.dni;

    // *s++ = persona.name;
    // *s++ = persona.lastname;
    // *s++ = persona.age;
    // *s++ = persona.dni;
    // *s = NULL;

    strcpy(mensaje,persona.name);
    strcat(mensaje,persona.lastname);
    strcat(mensaje,persona.age);
    // strcat(mensaje,persona.dni);
    // printf("mensaje: ----------------%s\n",mensaje );

    s = shm;
    for (int i=0; i < strlen(mensaje); i++)
        *s++ = mensaje[i];
    *s = NULL;

    // /*
    //  * Now put some things into the memory for the
    //  * other process to read.
    //  */

    // s = shm;
    // for (c = 'a'; c <= 'z'; c++)
    //     *s++ = c;
    // *s = NULL;

    /*
     * Finally, we wait until the other process
     * changes the first character of our memory
     * to '*', indicating that it has read what
     * we put there.
     */
    while (*shm != '*')
        sleep(1);

    exit(0);
}
