/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:35:56 by acharras          #+#    #+#             */
/*   Updated: 2020/07/10 16:49:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_check_arg_next_2(t_cub3d *game, char *line, int j, int i)
{
	int		k;

	while (line[j] == ' ')
		j++;
	k = j;
	while (line[j] == '0')
		j++;
	while (line[j] == '0' || line[j] == '1' || line[j] == '2' || line[j] == '3'
		|| line[j] == '4' || line[j] == '5' || line[j] == '6' || line[j] == '7'
		|| line[j] == '8' || line[j] == '9')
	{
		i++;
		j++;
	}
	if (i > 4)
		game->height = 10000;
	else
		game->height = ft_atoi(&line[k]);
	while (line[(j = k + ft_int_len(ft_atoi(&line[k])))] == ' ')
		j++;
	if (line[j] != '\0')
	{
		ft_putstr("Error\nArgument | R | had a bad format...\n");
		ft_exit(game);
	}
}

static int	ft_check_arg_next(t_cub3d *game, char *line, int j, int i)
{
	int		k;

	while (line[j] == ' ')
		j++;
	k = j;
	if (game->width != -1 || game->height != -1)
	{
		ft_putstr("Error\nMultiple or no argument 'R'...");
		ft_exit(game);
	}
	while (line[j] == '0')
		j++;
	while (line[j] == '0' || line[j] == '1' || line[j] == '2' || line[j] == '3'
		|| line[j] == '4' || line[j] == '5' || line[j] == '6' || line[j] == '7'
		|| line[j] == '8' || line[j] == '9')
	{
		i++;
		j++;
	}
	if (i > 4)
		game->width = 10000;
	else
		game->width = ft_atoi(&line[k]);
	j = k + ft_int_len(ft_atoi(&line[k]));
	return (j);
}

static void	ft_check_no_empty_line(t_cub3d *game, char *line)
{
	if (line[0] != '\0' && ft_check_full_arg(game, line) != 1)
	{
		if ((line[0] != 'R' || line[1] != ' ') && (line[0] != 'N'
			|| line[1] != 'O') && (line[0] != 'S' || line[1] != ' ')
			&& (line[0] != 'S' || line[1] != 'O') && (line[0] != 'E' ||
			line[1] != 'A') && (line[0] != 'W' || line[1] != 'E') &&
			line[0] != 'C' && line[0] != 'F')
		{
			ft_putstr("Error\nOnly empty lines are accepted...\n");
			ft_exit(game);
		}
	}
}

static int	ft_check_map_empty_line(t_cub3d *game, char *line)
{
	if (game->verif_we == 1 && game->verif_sp == 1 && game->verif_so == 1
		&& game->verif_no == 1 && game->verif_f == 1 && game->verif_c
		== 1 && game->arg_r == 1 && game->verif_ea == 1)
	{
		if (line[0] != '\0' && ft_chrcheck_str(line, '1') == 1)
			game->arg_map = 1;
		if (line[0] == '\0' && game->arg_map == 1)
		{
			ft_putstr("Error\nMap error : empty lines in the map...\n");
			ft_exit(game);
		}
	}
	return (1);
}

void		ft_check_arg(t_cub3d *game, char *line)
{
	int		j;
	int		i;

	j = 0;
	ft_check_no_empty_line(game, line);
	i = ft_check_map_empty_line(game, line);
	if (line[0] == 'R')
	{
		while (line[++j] != '\0')
		{
			if (line[j] != '0' && line[j] != '1' && line[j] != '2' && line[j]
				!= '3' && line[j] != '4' && line[j] != '5' && line[j] != '6'
				&& line[j] != '7' && line[j] != '8' && line[j] != '9' &&
				line[j] != ' ')
			{
				ft_putstr("Error\nArgument | R | had a bad format...\n");
				ft_exit(game);
			}
		}
		j = ft_check_arg_next(game, line, 1, i);
		ft_check_arg_next_2(game, line, j, i);
		game->arg_r = 1;
	}
	ft_path(game, line);
	ft_colors(game, line);
}
