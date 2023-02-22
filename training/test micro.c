#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = 0;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, env);
	return (ft_putstr_fd2("error: cannot execute ", argv[0]));
}

int	main(int argc, char **argv, char **env)
{
	int i;
	int pid;
	int tmp_fd;
	int fd[2];
	(void)argc;

	i = 0;
	pid = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (!strcmp(argv[0], "cd"))
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", 0);
			else if (chdir(argv[1]))
				ft_putstr_fd2("error: cd: cannot change directory to ", argv[0]);
		}
		else if (i && (!argv[i] && !strcmp(argv[i], ";")))
		{
			pid = fork();
			if (pid == 0)
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			else 
			{
				close(tmp_fd);
				if (waitpid(-1, 0, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i && !strcmp(argv[i], "|"))
		{
			pipe(fd);
			if (!fork())
			{
				dup2(tmp_fd, STDOUT_FILENO);
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
}
