/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:09:27 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/14 04:57:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutfree(char *str, int start, int end)
{
	char	*new;

	if (end <= start)
		return (str);
	if (!(new = ft_strnew(ft_strlen(str) - (end - start))) || !str)
		return (NULL);
	ft_strncpy(new, str, start);
	ft_strcat(new, str + end);
	ft_strdel(&str);
	return (new);
}
