/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:41:56 by mruizzo           #+#    #+#             */
/*   Updated: 2022/01/16 04:38:10 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ris;

	ris = (char *) s + ft_strlen(s);
	while (*ris != (unsigned char) c)
	{
		if (s == ris)
			return (NULL);
		ris--;
	}
	return (ris);
}
