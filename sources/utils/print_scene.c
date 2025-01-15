/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:09:42 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/10 15:05:06 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void print_color(t_color *color)
{
	printf("\tCol: \t %d, %d, %d\n", color->r, color->g, color->b);
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
	printf("\tDir: \t");
	print_vector(camera->orientation);
	printf("\tFov: \t%d\n", camera->fov);
	printf("\n");
}

static void	print_light(t_light *light)
{
	printf("[%s]\n", objects_to_name(light->type));
	printf("\tPos: \t");
	print_vector(light->position);
	printf("\tBri: \t%.1f\n\n", light->brightness);
}

// ------------------- Planes --------------
static void print_plane(t_plane *plane)
{
	printf("[%s]\n", objects_to_name(plane->type));
	printf("\tPos: \t");
	print_vector(plane->position);
	printf("\tDir: \t");
	print_vector(plane->orientation);
	print_color(plane->color);
}

static void	print_planes(t_plane *plane)
{
	printf("PLANE: %p\n", plane);
	while (plane)
	{
		print_plane(plane);
		plane = plane->next;
	}
}

void	print_scene(t_scene *scene)
{
	printf("\n========= [Scene] =========\n\n");
	print_ambi(scene->ambi);
	print_camera(scene->camera);
	print_light(scene->light);
	print_planes(scene->planes);
}
