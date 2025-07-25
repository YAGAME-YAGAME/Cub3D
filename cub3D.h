/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:24:17 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/25 16:32:54 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_config
{
    char    *no_texture_path;
    char    *so_texture_path;
    char    *we_texture_path;
    char    *ea_texture_path;

    int     floor_color;      // يمكن تخزين اللون كـ int RGB
    int     ceiling_color;

    char    **map;            // الخريطة نفسها بعد تنظيفها (2D array of chars)
    int     map_width;
    int     map_height;

    int     player_x;
    int     player_y;
    char    player_dir;       // 'N' أو 'S' أو 'E' أو 'W'
} t_config;

// read
char	*get_next_line(int fd);
//errors
void	message_error(char *str);
// parssing
bool	parssing(t_config *game, char *f_name);
bool	check_name(char *name);
bool	path_name(char *name);
bool	color_init(char *str);

// parssing utils
int	size_tab(char **str);
char *remove_nline(char *str);

// textur init
bool 	text_init(t_config *game, char *line);
//leaks
void	clean_tab(char ***arg);
#endif