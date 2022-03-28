/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:21:00 by mruizzo           #+#    #+#             */
/*   Updated: 2022/03/25 16:28:49 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_text(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window,
		game->wndw_size.x - IMG_SIZE / 2.3,
		IMG_SIZE - IMG_SIZE / 1.5,
		-1, str);
	free(str);
}

void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	if (tile.up == NULL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs1, pos.x, pos.y);
	else if (tile.down == NULL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs2, pos.x, pos.y);
	else
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs, pos.x, pos.y);
}

static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	mlx_put_image_to_window(game.mlx, game.window,
		game.floor, pos.x, pos.y);
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		if (game.collects > 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_close_img.current_img, pos.x, pos.y);
		else
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_open_img.current_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs, pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.enemy_imgs.basic_current, pos.x, pos.y);
	else if (tile.type == PLAYER && game.player.tile != NULL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.current_img, pos.x, pos.y);
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL )
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			x++;
		}
		y++;
	}
	if (game.status == 1)
		mlx_put_image_to_window(game.mlx, game.window,
			game.winmessage, game.wndw_size.x / 2 - 228,
			game.wndw_size.y / 2 - 174);
	if (game.status == -1)
		mlx_put_image_to_window(game.mlx, game.window,
			game.losemessage, game.wndw_size.x / 2 - 228,
			game.wndw_size.y - 348);
}
