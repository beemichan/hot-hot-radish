#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main ()
{
   system("afplay beginning.wav -v 10 &");
 
   long seconds = 4915000;
   clock_t start_time = clock();
   while(clock() < start_time + seconds){
      //printf("nuts");
   }
   int count = 0;
   while(count < 3){
      system("afplay bodyloop.wav -t 45 &");
      long seconds2 = 41970000;
      clock_t start_time2 = clock();
      while(clock() < start_time2 + seconds2){
 
      }
      count++;
   }
 
}
