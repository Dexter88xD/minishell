/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:41:41 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/10 13:07:22 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strndup(const char *s, size_t len)
{
	char	*buffer;

	if (s == NULL)
		return (NULL);
	buffer = (char *)malloc((len + 1) * sizeof(*s));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_memcpy(buffer, s, len);
	buffer[len] = '\0';
	return (buffer);
}
