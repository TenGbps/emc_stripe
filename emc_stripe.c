#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>

int main(int argc, char **argv) {
 printf("\n");
 printf(" EMC Symmetrix V-Max Systems - Blue Light Stripe Control\n");
 printf(" Version 0.1a - CY7C63803-SXC on USB - TenGbps\n\n");

 if(argc >= 3){
  FILE *fp;
  char hidpath[32];
  int power = 1;
  int bri   = 255;
  int opt1  = 80;
  int opt2  = 80;
  snprintf(hidpath, sizeof hidpath, "/dev/hidraw%i", atoi(argv[1]));
  if(strcmp(argv[2], "on")    == 0) { power = 1;             }
  if(strcmp(argv[2], "blink") == 0) { power = 2;             }
  if(strcmp(argv[2], "off")   == 0) { power = 3;             }
  if(argc >= 4)                     { bri   = atoi(argv[3]); }
  if(argc >= 5)                     { opt1  = atoi(argv[4]); }
  if(argc >= 6)                     { opt2  = atoi(argv[5]); }
  printf(" => Sending to %s, power:%i bri:%i time_on:%i time_off:%i\n", hidpath, power, bri, opt1, opt2);
  fp = fopen(hidpath, "w+");
  fprintf(fp, "%c%c%c%c", power, bri, opt1, opt2);
  fclose(fp);
 } else {
  printf("Usage: %s <hidid> <on,off,blink> {brightness:0-255} {time_on:0-255} {time_off:0-255}\n", *argv);
  exit(1);
 }
}
