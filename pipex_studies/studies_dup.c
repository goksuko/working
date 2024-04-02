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

// Integer value	Name				<unistd.h> s	<stdio.h> 
// 0				Standard input		STDIN_FILENO	stdin
// 1				Standard output		STDOUT_FILENO	stdout
// 2				Standard error		STDERR_FILENO	stderr

int main()
{
	int	fd;
	int dup_fd;

	dup_fd = 0; // Initialize dup_fd to 0 - what is written to dup_fd will be written to stdout
	fd = open("test.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
	printf("\n1st: fd = %d, dup_fd = %d\n", fd, dup_fd);
	write(fd, "1:Hello, World to fd!\n", 22);
	write(dup_fd, "1:It is dup_fd!\n", 16);

	dup_fd = dup(fd); //now it will be written to the file
	printf("\n2nd: fd = %d, dup_fd = %d\n", fd, dup_fd);
	write(fd, "2:Hello, World to fd!\n", 22);
	write(dup_fd, "2:It is dup_fd!\n", 16);

	dup_fd = dup2(1, fd); //this makes fd 1, and then dup_fd will be copied from fd, so everything will be written to terminal
	printf("\n3rd: fd = %d, dup_fd = %d\n", fd, dup_fd);
	write(fd, "3:Hello, World to fd!\n", 22);
	write(dup_fd, "3:It is dup_fd!\n", 16);
	return (0);
}
