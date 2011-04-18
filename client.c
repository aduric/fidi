#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fidi.h"
#include "client.h"

#define FIFO_NAME "fidi"


int reader(int fp, Rep* rep) {

  char s[256];
  int status=-1;
  int i, num;

  num = read(fp, s, 256);
  if (num == -1)
    return -1;
  else if(num == 0)
    return 0;
  else {
#ifdef DEBUG
    printf("Read in REP\n");
    printf("Parsing...");
#endif
    for(i=0;i<num;i++) {
#ifdef DEBUG
      printf("byte: %02x\n", s[i]);
#endif

      switch((unsigned)s[i]) {
      case REP:
	status=1;
	continue;
      case MUSCLE_GROUP:
	rep->muscle_group=s[++i];
	break; 
      case RESISTANCE:
	rep->resistance=s[++i];
	break;
      case ROTATION_ANGLE:
	rep->rotation=s[++i];
	break;
      case SPEED:
	rep->speed=s[++i];
	break;
      }

    }

  }
  
  return 1;

}

double energyOutput(Rep* r) {

  return (double)(r->resistance+r->speed+r->rotation);

}

double calorieOutput(Rep* r) {

  return (double)(r->resistance+r->speed+r->rotation)*0.1;

}

double fatigueOutput(Rep* r) {

  return (double)(r->resistance*r->speed*r->rotation*0.001);

}

void output(Rep* rep) {

  printf("MUSCLE GROUP: %d\nRESISTANCE: %d\nROTATION: %d\nSPEED: %d\n", 
	  rep->muscle_group, rep->resistance, rep->rotation, rep->speed);

}

int main(void)
{
    char s[256];
    int num, fd, i;
    Rep rep;
    double calories = 0.0;
    double energy = 100.0;
    double fatigue = 0.0;

    mknod(FIFO_NAME, S_IFIFO | 0666, 0);

    printf("waiting for writers...\n");
    fd = open(FIFO_NAME, O_RDONLY);
    printf("got a writer\n");

    do {
      num = reader(fd, &rep);
      if (num!=0) output(&rep);
    } while (num > 0);

    return 0;
}
