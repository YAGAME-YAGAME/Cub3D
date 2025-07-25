/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:49:15 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/25 18:44:14 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac , char **av)
{
	t_config *game;

	game = malloc(sizeof(t_config));
	if(!game)
		return(message_error("error malloc"), 1);
	if(ac == 2)
	{
		parssing(game , av[1]);
	}
	else
		message_error("error in argument");
}