/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:39:57 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/25 19:07:13 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	valid_cara(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (2);
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	else
		return (0);
}

bool	check_caracter(char **map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(valid_cara(map[i][j]))
			{
				if(valid_cara(map[i][j]) == 2)
				{
					if(check)
						return(false);
					check = 1;
				}
			}
			else
				return(false);
			j++;
		}
		i++;
	}
	if(check != 1)
		return(false);
	return (true);
}

bool	parssing_map(t_config *game, char *str)
{
	char **map;

	(void)game;
	map = ft_split(str, '\n');
	if(!check_caracter(map))
		return(message_error("map : caracter not valid") , false);
	else
		return (true);
}