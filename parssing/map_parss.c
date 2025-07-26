/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:39:57 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/26 22:56:37 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**map_vertical(int size, char **map)
{
	int		i;
	int		j;
	int		len;
	char	**new;

	i = 0;
	len = ft_strlen(map[0]);
	new = malloc(sizeof(char *) * (len + 1));
	while(i < len)
	{
		j = 0;
		new[i] = malloc(size + 1);
		while(j < size)
		{
			new[i][j] = map[j][i];
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}


int	valid_cara(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (2);
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	else
		return (0);
}

bool	check_caracter(t_config *game, char **map)
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
					game->player_x = i;
					game->player_y = j;
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

void	add_space(int size, char **map)
{
	int i = 0;
	int j;
	char *dest;

	while (map[i])
	{
		j = 0;
		dest = malloc(size + 1);
		while (map[i][j])
		{
			dest[j] = map[i][j];
			j++;
		}
		while (j < size)
			dest[j++] = ' ';
		dest[j] = '\0';

		free(map[i]);
		map[i] = dest;
		i++;
	}
}

void	desplay_map(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

bool	parssing_map(t_config *game, char *str)
{
	char **map;
	char **vertc;

	(void)game;
	map = ft_split(str, '\n');
	add_space(game->map_width, map);
	if(!check_caracter(game , map))
		return(message_error("map : caracter not valid") , false);
	if(!check_walls(game->map_height, map))
		return(message_error("map : wall not valid") , false);
	else
		return (true);
}