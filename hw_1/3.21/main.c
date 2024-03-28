#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>   
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    int i=0;
    int status;
    pid_t pid;
    do
    {
    printf("Enter a positive integer: ");
    scanf("%d", &i);
    }while (i<=0);
    
    pid = fork();
    
    if (pid>0)
    {
    wait(&status);
    }
    else  if (pid== 0) 
    {
        while (i!=1){
            if (i%2 == 0)
            {
                i = i/2;
            }
            else if (i%2 == 1)
            {
                i = 3 * (i) + 1;
            }
            printf("%d\n",i);
        }
    }
    return 0;
}