#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fidi.h"

#define FIFO_NAME "fidi"
#define QUAD 0x01;

int main(void)
{
    char s[256];
    int num, fd, c,group, weight, rot, speed, i;

    mknod(FIFO_NAME, S_IFIFO | 0666, 0);

    printf("waiting for readers...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    printf("got a reader--type some stuff\n");

    while (1) {

      c=0;
      scanf("%d %d %d %d", &group, &weight, &rot, &speed);
      
      // create rep
      s[c++]=0xAB;
      s[c++]=MUSCLE_GROUP;
      s[c++]=QUAD;
      s[c++]=RESISTANCE;
      s[c++]=(unsigned)weight;
      s[c++]=ROTATION_ANGLE;
      s[c++]=(unsigned)rot;
      s[c++]=SPEED;
      s[c++]=(unsigned)speed;
      
      /*      printf("Read in REP\n");
      for(i=0;i<c;i++)
	printf("byte: %02x\n", s[i]);
      */

      // write rep
      if ((num = write(fd, s, c)) == -1)
	perror("write");
      else
	printf("speak: wrote %d bytes\n", num);
      
    }

    return 0;
}
