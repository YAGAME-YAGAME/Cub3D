/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:02:23 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/26 22:46:05 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


bool	is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (true);
	return (false);
}

bool	if_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

void	read_mapp()
{

}


bool	parssing(t_config *game, char *f_name)
{
	char	*line;
	char	*map;
	char	*tmp;
	int		list;
	int		fd;

	list = 0;
	map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	if (!check_name(f_name))
		return (message_error("invalide file name"), false);
	fd = open(f_name, O_RDWR, 0777);
	if(fd < 0)
		return (message_error("error in open file"), false);
	line = get_next_line(fd);
	while(line)
	{

		if(!if_line_empty(line))
		{
			if(list < 4)
			{
				if(text_init(game, line))
					list++;
				else
					return(message_error("textur parssing faild"), false);
			}
			else if(list >= 4 && list < 6)
			{
				if(color_init(game, line))
					list++;
				else
					return(message_error("color parssing faild"), false);
			}
			else
			{
				if((int)ft_strlen(line) > game->map_width)
					game->map_width = ft_strlen(line) - 1;
				game->map_height+= 1;
				tmp = ft_strdup(map);
				if(map)
					free(map);
				map = ft_strjoin(tmp, line);
				if(tmp)
					free(tmp);
			}
		}
		line = get_next_line(fd);
	}
	printf("map width : %d\n", game->map_width);
	printf("map height : %d\n", game->map_height);
	parssing_map(game, map);
	return (true);
}
