#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char    *argv[3];
    int     i;
    int     x;
    int     w_status;
    w_status = 0;
    argv[0] = "/bin/ls";
    argv[1] = "-l";
    argv[2] = NULL;
    x = 5;
    i = fork();
    printf("fork returned %d\n", i);
    if (i == -1)
        return (1);
    else if (i == 0)
    {
        printf("\e[1;34m");
        printf("i = %d, x = %d, and x--\n", i, x);	
        x--;
        printf("i = %d, x = %d\n", i, x);	
        printf("This line is from child, x is %d\n", x);
        // return (0);
        execv(argv[0], argv);
        printf("This line is from child after execv\n");
        printf("\e[0m");
    }
    else
    {
        printf("\e[1;31m");
        printf("i = %d, x = %d, and x++\n", i, x);	
        wait(&w_status);
        x++;
        printf("\e[1;31m");
        printf("i = %d, x = %d\n", i, x);
        printf("This line is from parent, x is %d\n", x);
        printf("\e[0m");
    }
    if (WIFEXITED(w_status))
    {
        printf("\e[1;32m");
        w_status++;
        printf("Child process exited with status :%d\n", w_status);  
        printf("\e[0m");
    }
}