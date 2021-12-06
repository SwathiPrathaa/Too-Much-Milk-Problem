#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main(int argc, char * argv[]) {
    int fd;
    cout<<"Jill comes home.\n";
    cout<<"Jill checks the fridge.\n";
    fd=open("Fridge_A", O_CREAT|O_RDWR|O_APPEND, 0777);
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
    return 0;
}
