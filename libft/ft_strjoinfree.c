/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:40:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/14 06:34:03 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *new;

	if (!s2)
		return (s1);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_strcat(new, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}
