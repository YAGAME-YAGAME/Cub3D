/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:10:21 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/24 23:10:46 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char *remove_nline(char *str)
{
	int		len;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	while(str[i])
	{
		if(str[i] != '\n')
			len++;
		i++;
	}
	dest = malloc(len + 1);
	i = 0;
	while(str[i])
	{
		if(str[i] != '\n')
			dest[j++] = str[i++];
		else
			i++;
	}
	dest[j] = 0;
	return(dest);
}