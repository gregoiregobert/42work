#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	putstr(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = 0;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, env);
	return (putstr("Error: cd: cannot execute ", argv[0]));
}

int main(int argc, char **argv, char **env)
{
	int i;
	int pid;
	int fd[2];
	int tmp_fd;
	(void)argc;
	
	i = 0;
	pid = 0;
	tmp_fd = dup(STDIN_FILENO);
	while(argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd"))
		{
			if (i != 2)
				putstr("error: cd: bad argument", 0);
			else if (chdir(argv[1]))
				putstr("Error: cd: cannot change direcory to ", argv[1]);
		}
		else if (i && (!argv[i] || !strcmp(argv[i], ";")))
		{
			pid = fork();
			if (pid == 0)
			{
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else 
			{
				close(tmp_fd);
				while (waitpid(-1, 0, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i && !strcmp(argv[i], "|"))
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd[1] ,STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else 
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}