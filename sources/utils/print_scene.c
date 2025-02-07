/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:09:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/07 02:05:36 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// static void print_color(t_color *color)
// {
// 	printf("\tCol: \t%d, %d, %d\n", color->r, color->g, color->b);
// }

// static void print_ambi(t_ambi *ambi)
// {
// 	printf("[%s]\n", objects_to_name(ambi->type));
// 	printf("\tAmbi: \t%.1f\n", ambi->ambi_ratio);
// 	print_color(ambi->color);
// 	printf("\n");
// }

// static void print_vector(t_vect *vec)
// {
// 	printf("%.1f, %.1f, %.1f\n", vec->x, vec->y, vec->z);
// }
// static void print_camera(t_camera *camera)
// {
// 	printf("[%s]\n", objects_to_name(camera->type));
// 	printf("\tPos: \t");
// 	print_vector(camera->position);
// 	printf("\tDir: \t");
// 	print_vector(camera->orientation);
// 	printf("\tFov: \t%d\n", camera->fov);
// 	printf("\n");
// }

// static void	print_light(t_light *light)
// {
// 	printf("[%s]\n", objects_to_name(light->type));
// 	printf("\tPos: \t");
// 	print_vector(light->position);
// 	printf("\tBri: \t%.1f\n\n", light->brightness);
// }

// // ------------------- Planes --------------
// static void print_plane(t_plane *plane)
// {
// 	printf("[%s]\n", objects_to_name(plane->type));
// 	printf("\tPos: \t");
// 	print_vector(plane->position);
// 	printf("\tDir: \t");
// 	print_vector(plane->orientation);
// 	print_color(plane->color);
// 	printf("\n");
// }

// static void	print_planes(t_plane *planes)
// {
// 	t_plane		*current;

// 	current = planes;
// 	while (current)
// 	{
// 		print_plane(current);
// 		current = current->next;
// 	}
// }

// // ------------------- Spheres --------------
// static void	print_sphere(t_sphere *sphere)
// {
// 	printf("[%s]\n", objects_to_name(sphere->type));
// 	printf("\tPos: \t");
// 	print_vector(sphere->position);
// 	printf("\tDiam: \t%.1f\n", sphere->diameter);
// 	print_color(sphere->color);
// 	printf("\n");
// }

// static void	print_spheres(t_sphere *spheres)
// {
// 	t_sphere	*current;

// 	current = spheres;
// 	while (current)
// 	{
// 		print_sphere(current);
// 		current = current->next;
// 	}
// }

// // ------------------- Cylinders --------------
// static void	print_cylinder(t_cylinder *cylinder)
// {
// 	printf("[%s]\n", objects_to_name(cylinder->type));
// 	printf("\tPos: \t");
// 	print_vector(cylinder->position);
// 	printf("\tAxis: \t");
// 	print_vector(cylinder->axis);
// 	printf("\tDiam: \t%.1f\n",(cylinder->diameter));
// 	printf("\tHeig: \t%.1f\n",(cylinder->height));
// 	print_color(cylinder->color);
// 	printf("\n");
// }

// static void print_cylinders(t_cylinder *cylinders)
// {
// 	t_cylinder	*current;

// 	current = cylinders;
// 	while (current)
// 	{
// 		print_cylinder(current);
// 		current = current->next;
// 	}
// }

// void	print_scene(t_scene *scene)
// {
// 	printf("\n========= [Scene] =========\n\n");
// 	if (scene->ambi)
// 		print_ambi(scene->ambi);
// 	if (scene->camera)
// 		print_camera(scene->camera);
// 	if (scene->light)
// 		print_light(scene->light);
// 	if (scene->planes)
// 		print_planes(scene->planes);
// 	if (scene->spheres)
// 		print_spheres(scene->spheres);
// 	if (scene->cylinders)
// 		print_cylinders(scene->cylinders);
// }
