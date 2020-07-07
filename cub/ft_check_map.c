/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:45 by acharras          #+#    #+#             */
/*   Updated: 2020/07/07 14:51:31 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_check_line_next(t_cub3d *game, int i, int k)
{
	if (game->map[i][k] == 'N' || game->map[i][k] == 'E' ||
		game->map[i][k] == 'W' || game->map[i][k] == 'S')
	{
		if (++game->map_false == 1)
			game->dir_player = game->map[i][k];
		game->posx = (double)k;
		game->posy = (double)i;
	}
	if (game->map[i][k] != '0' && game->map[i][k] != '1' && game->
		map[i][k] != '2' && game->map[i][k] != 'N' && game->map[i][k]
		!= 'S' && game->map[i][k] != 'E' && game->map[i][k] != 'W')
	{
		ft_putstr("Error\nMap error...\n");
		ft_exit(game);
	}
}

static void	ft_check_line(t_cub3d *game, int i, int k)
{
	while (game->map[i][k])
	{
		ft_check_line_next(game, i, k);
		if (game->map[i][k] == 'N' || game->map[i][k] == 'E' ||
			game->map[i][k] == 'W' || game->map[i][k] == 'S' ||
			game->map[i][k] == '0' || game->map[i][k] == '2')
		{
			if ((game->map[i + 1] && (int)ft_strlen(game->map
			[i + 1]) <= k) || (i - 1 < 0) ||
			(((int)ft_strlen(game->map[i - 1]) <= k && game->map[i - 1])))
			{
				ft_putstr("Error\nMap error : a | 0 | 2 | N | S | E | W |");
				ft_putstr(" out of the map...\n");
				ft_exit(game);
			}
		}
		if (game->map[i][k++] == '2')
			game->sp_nbr++;
	}
	if (game->map[i][k - 1] != '1')
	{
		ft_putstr("Error\nMap error : no '1' at the end of line...\n");
		ft_exit(game);
	}
}

static int	ft_all_line(t_cub3d *game, int i, int k)
{
	i = 0;
	k = -1;
	while (game->map[1][++k])
	{
		if (game->map[1][k] == '0' && game->map[0][k] != '1')
		{
			ft_putstr("Error\nMap error : missing '1' at the begining ");
			ft_putstr("of line...\n");
			ft_exit(game);
		}
	}
	k = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
		{
			ft_putstr("Error\nMap error : no '1' at the begining ");
			ft_putstr("of line...\n");
			ft_exit(game);
		}
		ft_check_line(game, i, k);
		k = 0;
		i++;
	}
	return (i);
}

static int	ft_check_map_error_next(t_cub3d *game, int i)
{
	if (ft_strcmp(game->map[0], NULL) == 0)
	{
		ft_putstr("Error\nMap error : missing map...\n");
		ft_exit(game);
	}
	while (game->map[++i])
		;
	if (i < 2)
	{
		ft_putstr("Error\nMap error : missing map...\n");
		ft_exit(game);
	}
	return (i);
}

void		ft_check_map_error(t_cub3d *game)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_check_space(game, i, j);
	}
	i = -1;
	i = ft_check_map_error_next(game, i);
	i = ft_all_line(game, i, k);
	ft_alloc_sprite_order(game);
	if (ft_strcheck_chr(game->map[i - 1], '1') != 0 || game->map_false != 1)
	{
		ft_putstr("Error\nMap error : no '1' at the last line ||");
		ft_putstr(" many or no | N | S | W | E | in the map...\n");
		ft_exit(game);
	}
}
