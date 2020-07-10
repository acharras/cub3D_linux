/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:53 by acharras          #+#    #+#             */
/*   Updated: 2020/07/10 16:19:53 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_alloc_sprite_order(t_cub3d *game)
{
	if (!(game->sp_order = (int *)malloc(sizeof(int) * (game->sp_nbr + 1))))
		ft_exit(game);
	if (!(game->sp_dist = (double *)malloc(sizeof(double) *
		(game->sp_nbr + 1))))
		ft_exit(game);
	game->sp_order[game->sp_nbr] = '\0';
	game->sp_dist[game->sp_nbr] = '\0';
}

static int	ft_check_number_next(char *line, int j)
{
	if (line[j] == '0' || line[j] == '1' || line[j] == '2' ||
		line[j] == '3' || line[j] == '4' || line[j] == '5' ||
		line[j] == '6' || line[j] == '7' || line[j] == '8' ||
		line[j] == '9')
		j++;
	if (line[j] != '\0' && line[j] == ' ')
		while (line[j] != '\0' && line[j] == ' ')
			j++;
	return (j);
}

void		ft_check_number(t_cub3d *game, char *line, int j)
{
	while (line[j] != '\0')
	{
		j = ft_check_number_next(line, j);
		if (line[j] != '\0' && (line[j] == '0' || line[j] == '1' ||
			line[j] == '2' || line[j] == '3' || line[j] == '4' ||
			line[j] == '5' || line[j] == '6' || line[j] == '7' ||
			line[j] == '8' || line[j] == '9'))
		{
			while (line[j] != '\0' && (line[j] == '0' || line[j] == '1' ||
				line[j] == '2' || line[j] == '3' || line[j] == '4' ||
				line[j] == '5' || line[j] == '6' || line[j] == '7' ||
				line[j] == '8' || line[j] == '9'))
				j++;
			while (line[j] != '\0' && line[j] == ' ')
				j++;
			if (line[j] != '\0' && line[j] != ',')
			{
				ft_putstr("Error\nArgument | F | C | had a bad format...\n");
				ft_exit(game);
			}
		}
		if (line[j] != '\0')
			j++;
	}
}

int			ft_check_map(t_cub3d *game, char *line)
{
	if (ft_check_full_arg(game, line) == 1 && game->check_map >= 2)
	{
		if (!(game->tmp_map = ft_strjoin_f_s1(game->tmp_map, line)))
			ft_exit(game);
		if (!(game->tmp_map = ft_strjoin_f_s1(game->tmp_map, "\n")))
			ft_exit(game);
		game->map_i++;
	}
	return (1);
}

void		ft_check_w_h(t_cub3d *game)
{
	if (game->width_check < game->width)
	{
		game->width = game->width_check;
		ft_putstr("WARNING !\nmap width resized because ");
		ft_putstr("width is superior than the limit screen\n");
	}
	if (game->width < 250)
	{
		game->width = 250;
		ft_putstr("WARNING !\nmap width resized to 250 because ");
		ft_putstr("too small width\n");
	}
	if (game->height_check < game->height)
	{
		game->height = game->height_check;
		ft_putstr("WARNING !\nmap height resized because ");
		ft_putstr("height is superior than the limit screen\n");
	}
	if (game->height < 150)
	{
		game->height = 150;
		ft_putstr("WARNING !\nmap height resized to 150 because ");
		ft_putstr("too small height\n");
	}
}
