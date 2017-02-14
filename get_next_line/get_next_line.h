/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandriut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:55:51 by tandriut          #+#    #+#             */
/*   Updated: 2017/01/17 20:03:28 by gciub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
#include <unistd.h>
# define BUFF_SIZE 32

typedef struct		s_lst
{
	int				fd;
	char			*buff;
	struct s_lst	*next;
	struct s_lst	*begin;
}					t_lst;

int					get_next_line(int const fd, char **line);
#endif
