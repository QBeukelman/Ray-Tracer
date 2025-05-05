/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:09:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:08:26 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	util_print_camera(t_camera *camera)
{
	printf("[%d][%s]\n", 0, objects_to_name(camera->type));
	printf("\tPos: \t");
	util_print_vector(camera->position);
	printf("\tFov: \t%d\n", camera->fov);
	printf("\n");
}

static void	util_print_light(t_light *light)
{
	printf("[%d][%s]\n", 1, objects_to_name(light->type));
	printf("\tPos: \t");
	util_print_vector(light->position);
	printf("\tBri: \t%.1f\n\n", light->brightness);
}

static void	util_print_ambi(t_ambi *ambi)
{
	printf("[%d][%s]\n", 2, objects_to_name(ambi->type));
	printf("\tAmbi: \t%.1f\n", ambi->ratio);
	print_color(ambi->color);
	printf("\n");
}

void	util_print_vector(t_vector vec)
{
	printf("%.1f, %.1f, %.1f\n", vec.x, vec.y, vec.z);
}

void	print_scene(t_scene *scene)
{
	if (scene->camera.initialized)
		util_print_camera(&(scene->camera));
	if (scene->light.initialized)
		util_print_light(&(scene->light));
	if (scene->ambi.initialized)
		util_print_ambi(&(scene->ambi));
	print_objects(scene->objects);
}
