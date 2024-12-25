/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:09:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/26 00:39:36 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void print_color(t_color *color)
{
	printf("\tColor: \t %d, %d, %d\n", color->r, color->g, color->b);
}

static void print_ambi(t_ambi *ambi)
{
	printf("[%s]\n", objects_to_name(ambi->type));
	printf("\tAmbi: \t %.1f\n", ambi->ambi_ratio);
	print_color(ambi->color);
	printf("\n");
}

static void print_vector(t_vect *vec)
{
	printf("%.1f, %.1f, %.1f\n", vec->x, vec->y, vec->z);
}
static void print_camera(t_camera *camera)
{
	printf("[%s]\n", objects_to_name(camera->type));
	printf("\tPos: \t");
	print_vector(camera->position);
	printf("\n");
}

void	print_scene(t_scene *scene)
{
	printf("\n========= [Scene] =========\n\n");
	print_ambi(scene->ambi);
	print_camera(scene->camera);
}
