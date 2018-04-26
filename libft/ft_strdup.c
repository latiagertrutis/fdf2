/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:55:57 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/11 02:32:32 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str1;
	char	*srccpy;
	int		len;
	int		i;

	srccpy = (char *)src;
	len = ft_strlen(srccpy);
	str1 = (char *)malloc(sizeof(*str1) * (len + 1));
	if (str1 == NULL)
		return (NULL);
	i = 0;
	while (srccpy[i])
	{
		str1[i] = srccpy[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
