#include "../Includes/pipex.h"

void	do_child_process(char *argv[], char **envp, int pipefd[])
{
	int		infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
	{
		perror("Infile error\n");
		exit(1);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	// close(pipefd[0]);
	start_exec(argv[2], envp);
}

void	do_parent_process(char *argv[], char **envp, int pipefd[])
{
	int		outfile;

	close(pipefd[1]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (outfile < 0)
	{
		perror("Outfile error\n");
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	// close(pipefd[1]);
	start_exec(argv[3], envp);
}

//to be deleted later
void	print_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int check_path(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	int		path_no;

	// print_env(envp);
	path_no = check_path(envp);
	if (envp[path_no] == NULL)
	{
		perror("Path not found\n");
		return (1);
	}
	if (argc != 5)
	{
		perror("Please write 4 arguments!\n 1. file1\n 2. cmd1\n 3. cmd2\n 4. file2\n");
		return (1);
	}
	else
	{
		if (pipe(pipefd) == -1)
		{
			perror("Pipe error\n");
			return (1);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("Fork error\n");
			return (1);
		}
		else if (pid == 0)
			do_child_process(argv, envp, pipefd);
		waitpid(pid, NULL, 0);
		do_parent_process(argv, envp, pipefd);
	}
	return (0);
}

//make && ./pipex test.txt "grep h" "wc -m" result.txt
