#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{

    int fd = open("README", O_RDWR);
    if(fd < 0)
        printf("error");
    

    char buf1[10];
    char buf2[10];
    char buf3[10];
    char buf4[10];
    char buf5[10];

    printf("test1 expected to see the first 10 characters in the file:A fork of  \n");
    read(fd,buf1,sizeof(buf1));
    printf("after test1: %s\n", buf1);

    printf("test2 expected to see the chars form offset 20:upport for  \n");
    seek(fd,20,SEEK_SET);
    read(fd,buf2,sizeof(buf2));
    printf("after test2: %s\n", buf2);


    printf("test3 expected to see the chars form offset 40:Installati\n");
    seek(fd,20,SEEK_CUR);
    read(fd,buf3,sizeof(buf3));
    printf("after test3: %s\n", buf3);

    printf("test4 offset < 0 so the pointer returns to the beginning of the file\n");
    seek(fd,-100,SEEK_SET);
    read(fd,buf4,sizeof(buf4));
    printf("after test4: %s\n", buf4);

    printf("test5 fileSize < offset so the pointer set to the end of the file and then go back 10 characters\n");
    seek(fd,3000,SEEK_SET);
    seek(fd,-10,SEEK_CUR);
    read(fd,buf5,sizeof(buf5));
    printf("after test5 the last 10 chars in the file: %s", buf5);

    close(fd);
    
  

     
    return 0;



}








