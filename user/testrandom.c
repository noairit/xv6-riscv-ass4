#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include "kernel/fcntl.h"



int
main(int argc, char *argv[])
{
    int fd = open("random", O_RDWR);
    if(fd < 0)
        printf("error");
    uint8 buf1[255];
    uint8 buf2[255];
    uint8 buf3[255];
    uint8 buf4[255];
 
    read(fd,buf1,1);
    printf("random number 1 is: %x\n", buf1[0]);



    read(fd,buf2,255);
    for(int i = 0 ; i < 10; i++){
        printf( "%x ", buf2[i]);
    }

    printf("\n");
    printf( "should print the same number as the first print %x \n", buf2[254]);
    printf( "should print 0x2A %x \n", buf2[253]);


    uint64 new_seed = '1';

    write(fd,&new_seed,1);
    

    read(fd,buf3,1);
    printf("random number 1 is: %x\n", buf3[0]);

    read(fd,buf4,255);
    printf( "should print the same number as the last print %x \n", buf4[254]);
    
    close(fd);

    return 0;

    


}
