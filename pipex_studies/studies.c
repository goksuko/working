#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

// In C programming, when a child process terminates, but the parent process has not yet collected its exit status using functions like wait() or waitpid(), the child process enters a state known as a "zombie process". This state occurs because the process descriptor for the child still exists in the process table, but the process itself has terminated.

// Zombie processes consume system resources such as process table entries, but they do not execute any code. They persist until the parent process collects their exit status using one of the wait functions.

// After creating a child process using fork(), the parent process continues execution.
// The child process executes its task and eventually terminates.
// If the parent process doesn't call wait() or waitpid() to collect the child's exit status, the child becomes a zombie process.
// When the parent process calls wait() or waitpid(), it suspends its execution until one of its child processes terminates.
// When the parent process collects the child's exit status, the zombie process is removed from the process table, and its resources are released.

// In C programming, pid_t is a data type used to represent process IDs (PIDs). A process ID is a unique identifier assigned to each running process in a Unix-like operating system. The pid_t data type is defined in the <sys/types.h> header file.

// To ensure that the child process properly terminates and returns when it's done executing, you should call the exit() function at the end of the child process's code. This function terminates the calling process and returns the status code to the operating system.

// int main() {
//     pid_t pid;

//     // Create a child process
//     pid = fork();

//     if (pid < 0) {  // Fork failed
//         fprintf(stderr, "Fork failed\n");
//         return 1;
//     } else if (pid == 0) {  // Child process
//         printf("Child process executing\n");
//         // Child process exits successfully
//         exit(0);
//     } else {  // Parent process
//         // Wait for the child process to terminate
//         wait(NULL);
//         printf("Parent process executing\n");
//     }

//     return 0;
// }

// int main()
// {
// 	int	fd;
// 	int dup_fd;

// 	fd = open("test.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
// 	// dup_fd = dup(fd);
// 	printf("fd = %d, dup_fd = %d\n", fd, dup_fd);
// 	dup_fd = dup2(1, fd);
// 	printf("fd = %d, dup_fd = %d\n", fd, dup_fd);
// 	write(fd, "Hello, World!\n", 14);
// 	write(dup_fd, "It is me!\n", 10);
// 	return (0);
// }

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

// The reason for creating the pipe before forking lies in how the pipe is utilized for communication between the parent and child processes.

// When you create a pipe, you essentially create a unidirectional communication channel, allowing one process to write to one end of the pipe and another process to read from the other end. This communication channel is established by the pipe's file descriptors. After forking, both the parent and child processes inherit these file descriptors, enabling them to communicate through the pipe.

// If you were to fork before creating the pipe, each process (parent and child) would have its own pipe, which defeats the purpose of communication between them. You need both processes to share the same pipe to facilitate communication. Hence, the pipe must be created before forking.

// int main(int argc, char *argv[])
// {
// 	int	pipefd[2];
// 	int pid;
// 	int     w_status;
//     w_status = 0;

// 	if (argc != 2)
// 	{
// 		fprintf(stderr, "Please write an argument!\n");
// 		return (1);
// 	}
// 	if(pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		return (1);
// 	}
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		return (1);
// 	}
// 	else if (pid == 0)
// 	{
// 		close(pipefd[1]); //child yazmayi kapatti, okumaya devam edecek
// 		char c;
// 		while (read(pipefd[0], &c, 1) > 0)
// 		{
// 			c = toupper(c);
// 			write(STDOUT_FILENO, &c, 1);
// 		}
// 		write(STDOUT_FILENO, "\n", 1);
// 		close(pipefd[0]);
// 		exit(0);
// 	}
// 	else
// 	{
// 		close(pipefd[0]); //parent okumayi kapatti, yazmaya devam edecek
// 		write(pipefd[1], argv[1], strlen(argv[1])); //pipe'a yazdik
// 		close(pipefd[1]); //yazmayi kapatti
// 		wait(NULL);
// 	}
// 	if (WIFEXITED(w_status))
//     {
//         printf("\e[1;32m");
//         w_status++;
//         printf("Child process exited with status :%d\n", w_status);  
//         printf("\e[0m");
//     }
// 	return (0);
// }