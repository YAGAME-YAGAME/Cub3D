/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:49:15 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/30 18:12:03 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	desplay_struct(t_config *game)
{
	int	i;

	printf("NO Texture Path: %s\n", game->no_texture_path);
	printf("SO Texture Path: %s\n", game->so_texture_path);
	printf("WE Texture Path: %s\n", game->we_texture_path);
	printf("EA Texture Path: %s\n", game->ea_texture_path);
	printf("Floor Color: %d\n", game->floor_color);
	printf("Ceiling Color: %d\n", game->ceiling_color);
	printf("Player Position: (%d, %d)\n", game->player_x, game->player_y);
	printf("Player Direction: %c\n", game->player_dir);
	printf("Map Width: %d\n", game->map_width);
	printf("Map Height: %d\n", game->map_height);
	i = 0;
	if (game->map)
	{
		printf("Map:\n");
		while (game->map[i])
		{
			printf("%s\n", game->map[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_config	*game;

	game = malloc(sizeof(t_config));
	if (!game)
		return (message_error("error malloc"), 1);
	if (ac == 2)
	{
		if (parssing(game, av[1]))
			desplay_struct(game);
	}
	else
		message_error("error in argument");
}
