#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

// int main(int argc, char *argv[])
// {
//     int pipefd[2]; // File descriptors for the pipe
//     pid_t pid;     // Process ID variable
	
// 	if (argc != 2)
// 	{
//         fprintf(stderr, "Please write an argument!\n");
//         return 1;
//     }

//     // Create pipe
//     if (pipe(pipefd) == -1)
// 	{
//         perror("pipe");
//         return 1;
//     }

//     // Fork to create a child process
//     pid = fork();
//     if (pid < 0)
// 	{
//         perror("fork");
//         return 1;
//     }
// 	else if (pid == 0)
// 	{
//         // Child process
//         close(pipefd[1]); // Close the write end of the pipe

//         char c;
//         // Read characters from the pipe one byte at a time
//         while (read(pipefd[0], &c, 1) > 0) {
//             // Convert the character to uppercase
//             c = toupper(c);
//             // Write the converted character to stdout
//             write(STDOUT_FILENO, &c, 1);
//             // Write a newline to stdout
//             write(STDOUT_FILENO, "\n", 1);
//         }

//         close(pipefd[0]); // Close the read end of the pipe in the child
//         exit(0);
//     }
// 	else
// 	{
//         // Parent process
//         close(pipefd[0]); // Close the read end of the pipe

//         // Write the command-line argument to the pipe
//         write(pipefd[1], argv[1], strlen(argv[1]));

//         close(pipefd[1]); // Close the write end of the pipe in the parent

//         // Wait for the child process to terminate and check its status
//         wait(NULL);
//     }
//     return 0;
// }

// The reason for creating the pipe before forking lies in how the pipe is utilized 
// for communication between the parent and child processes.

// When you create a pipe, you essentially create a unidirectional communication channel,
//  allowing one process to write to one end of the pipe and another process to read from the other end. 
// This communication channel is established by the pipe's file descriptors. After forking,
// both the parent and child processes inherit these file descriptors, enabling them to communicate through the pipe.

// If you were to fork before creating the pipe, each process (parent and child) would have its own pipe,
//  which defeats the purpose of communication between them. You need both processes 
// to share the same pipe to facilitate communication. Hence, the pipe must be created before forking.


// I wrote again below code to understand better
int main(int argc, char *argv[])
{
	int	pipefd[2];
	int pid;
	int w_status;
	char c;

    w_status = 0;
	if (argc != 2)
	{
		fprintf(stderr, "Please write an argument!\n");
		return (1);
	}
	if(pipe(pipefd) == -1) //int pipe(int pipefd[2]); On success, zero is returned.  On error, -1 is returned
	{
		perror("pipe error");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		return (1);
	}
	else if (pid == 0) //child process
	{
		close(pipefd[1]); //child yazmayi kapatti, okumaya devam edecek 
		// The array pipefd is used to return two file descriptors referring 
		// to the ends of the pipe.  pipefd[0] refers to the read end of the pipe.  
		// pipefd[1] refers to the write end of the pipe.
		while (read(pipefd[0], &c, 1) > 0) //ssize_t read(int fd, void *buf, size_t count). On  success,  the number of bytes read is returned
		{
			c = toupper(c);
			write(STDOUT_FILENO, &c, 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		exit(0);
	}
	else
	{
		close(pipefd[0]); //parent okumayi kapatti, yazmaya devam edecek
		write(pipefd[1], argv[1], strlen(argv[1])); //pipe'a yazdik
		fprintf(stderr, "Parent process wrote to pipe: %s\n", argv[1]);
		write(pipefd[1], "-parent\n", 7);
		close(pipefd[1]); //yazmayi kapatti
		wait(NULL);
	}
	if (WIFEXITED(w_status))
    {
        printf("\e[1;32m");
        w_status++;
        printf("Child process exited with status :%d\n", w_status);  
        printf("\e[0m");
    }
	return (0);
}