#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

int main(int argc, char * argv[]) {
    int fd;
    int VALUE=1;
    sem_t * mutex;
    mutex = sem_open("mutex", O_CREAT, 0666, VALUE);
    cout<<"Jill comes home.\n";
    sem_wait(mutex);
    cout<<"Jill checks the fridge.\n";
    fd=open("Fridge_B", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd,0,SEEK_END)==0)
    {
        cout<<"Jill goes to buy milk...\n";
        sleep(2);
             write(fd,"milk ",5);
        cout<<"Jill puts milk in fridge and leaves.\n";
        if(lseek(fd,0,SEEK_END)>5)
            cout<<"What a waste of food! The fridge can not hold so much milk!\n";
    }
    else
    {
        cout<<"Jill closes the fridge and leaves.\n";
    }
    close(fd);
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex");
    return 0;
}
