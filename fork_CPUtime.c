/* sample code for demonstrate the fork system call.
 * In this program the child process 1 and child process 2 will compete with parent process
 * for CPU time. The output of program will be some unstable.
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
  
    int ch, first, last;
    unsigned int i;
    if (fork() ==0)     // child process 1
    {   
        first = 'A';
        last  = 'Z';
        for(ch = first; ch<=last; ch ++)
        {
             write(1, &ch,1) ;  // write ch onto stdout( terminal window)
             for(i=0;i<LOOP;i++)
                 ;            // do nothing to waste CPU time
         }
         printf("\n");
     }
     else
     {
      	 if(fork() ==0)  //child process 2
         {
            first  = 'a';
            last   = 'z';
            for(ch = first; ch<=last; ch ++)
            {
             	write(1, &ch,1);   // write ch onto stdout( terminal window)
             	for(i=0;i<LOOP;i++)
                   ;            // do nothing to waste CPU time
            }
            printf("\n");
          }
          else                   // parent process
          {
             first  = '0';
             last   = '9';
             for(ch =first; ch<=last; ch++)
             {
              	write(1, &ch,1) ;  // write ch onto stdout( terminal window)
             	for(i=0;i<LOOP;i++)
                   ;            // do nothing to waste CPU time
              }
           }
           printf("\n");
        }
        exit(0);
 }  
