/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:02:23 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/25 16:39:35 by ymouchta         ###   ########.fr       */
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


bool	parssing(t_config *game, char *f_name)
{
	char	*line;
	int		list;
	int		fd;

	list = 0;
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
				if(color_init(line))
					list++;
				else
					return(message_error("color parssing faild"), false);
			}
		}
		line = get_next_line(fd);
	}
	return (true);
}