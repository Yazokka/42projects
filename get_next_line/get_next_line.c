/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gciub <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:36:10 by gciub             #+#    #+#             */
/*   Updated: 2017/02/14 19:40:35 by gciub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*tmp;
	int				bol;
	int				res;
	char			temp[2];

	res = read(-1, temp, BUFF_SIZE);
	bol = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(1);
	while ((res = read(fd, temp, 1)) > 0)
	{
		bol = 1;
		if (temp[0] == '\n')
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, temp);
		ft_strdel(&tmp);
	}
	if (res < 0)
		return (-1);
	return (bol);
}

#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	pid_t	child;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open("me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, &n, 1);					// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	close(fd);
	close(fd2);
	child = fork();
	if (child == 0)
	{
		char	*arg[] = {"/usr/bin/diff", NULL, "me.txt", NULL};

		arg[1] = argv[1];
		execve(arg[0], arg, NULL);
		exit(0);
	}
	else
		wait(NULL); // bad code I know ... but it's not the project
	(void)argc;
	(void)argv;
	return (0);
}
