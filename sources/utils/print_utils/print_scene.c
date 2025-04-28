/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:09:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 22:51:18 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
// --------------- Functionpoiter Array --------------
typedef void (*print_object)(t_object*);

static void	util_print_vector(t_vector vec)
{
	printf("%.1f, %.1f, %.1f\n", vec.x, vec.y, vec.z);
}

// ------------------ Camera --------------
static void util_print_camera(t_camera *camera)
{
	printf("[%d][%s]\n", camera->index, objects_to_name(camera->type));
	printf("\tPos: \t");
	util_print_vector(camera->position);
	printf("\tFov: \t%d\n", camera->fov);
	printf("\n");
}

// ------------------- Light --------------
static void	util_print_light(t_light *light)
{
	printf("[%d][%s]\n", light->index, objects_to_name(light->type));
	printf("\tPos: \t");
	util_print_vector(light->position);
	printf("\tBri: \t%.1f\n\n", light->brightness);
}

// ---------------- Ambient Light --------------
static void util_print_ambi(t_ambi *ambi)
{
	printf("[%d][%s]\n", ambi->index, objects_to_name(ambi->type));
	printf("\tAmbi: \t%.1f\n", ambi->ratio);
	print_colour(ambi->colour);
	printf("\n");
}

// ------------------- Planes --------------
static void util_print_plane(t_object *plane)
{
	printf("[%d][%s]\n", plane->index, objects_to_name(plane->type));
	printf("\tPos: \t");
	util_print_vector(plane->position);
	printf("\tDir: \t");
	util_print_vector(plane->orientation);
	print_colour(plane->colour);
	printf("\n");
}

// ------------------- Spheres --------------
static void	util_print_sphere(t_object *sphere)
{
	printf("[%d][%s]\n", sphere->index, objects_to_name(sphere->type));
	printf("\tPos: \t");
	util_print_vector(sphere->position);
	printf("\tDiam: \t%.1f\n", sphere->diameter);
	print_colour(sphere->colour);
	printf("\n");
}

// ------------------- Cylinders --------------
static void	util_print_cylinder(t_object *cylinder)
{
	printf("[%d][%s]\n", cylinder->index, objects_to_name(cylinder->type));
	printf("\tPos: \t");
	util_print_vector(cylinder->position);
	printf("\tAxis: \t");
	util_print_vector(cylinder->axis);
	printf("\tDiam: \t%.1f\n",(cylinder->diameter));
	printf("\tHeig: \t%.1f\n",(cylinder->height));
	print_colour(cylinder->colour);
	printf("\n");
}

// ----------------- Print Scene --------------
static void print_objects(t_object *objects)
{
	t_object	*current;
	static const print_object print_func[3] = {
		util_print_sphere,
		util_print_plane,
		util_print_cylinder
	};

	current = objects;
	while (current != NULL)
	{
		print_func[(current->type - 3)](current);
		current = current->next;
	}
}

void	print_scene(t_scene *scene)
{
	// printf("\n========= [Scene] =========\n\n");
	if (&(scene->camera))
		util_print_camera(&(scene->camera));
	if (&(scene->light))
		util_print_light(&(scene->light));
	if (&(scene->ambi))
		util_print_ambi(&(scene->ambi));
	print_objects(scene->objects);
}
