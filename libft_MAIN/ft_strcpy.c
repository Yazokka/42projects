/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gciub <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:37:23 by gciub             #+#    #+#             */
/*   Updated: 2016/11/25 19:37:24 by gciub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *s1, const char *s2)
{
	size_t	cur;

	cur = 0;
	while (s2[cur] != '\0')
	{
		s1[cur] = s2[cur];
		cur++;
	}
	s1[cur] = '\0';
	return (s1);
}
