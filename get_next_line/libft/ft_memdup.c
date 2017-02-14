/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gciub <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:25:03 by gciub             #+#    #+#             */
/*   Updated: 2016/11/25 21:34:08 by gciub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_memdup(char *s, size_t size)
{
	char	*new;

	if ((new = ft_memnew(size)) == NULL)
		return (NULL);
	ft_memcpy(new, s, size);
	return (new);
}
