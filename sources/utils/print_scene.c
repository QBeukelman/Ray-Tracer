/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:09:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/08 23:35:21 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
// --------------- Functionpoiter Array --------------
typedef void (*print_object)(t_object*);

// ------------------ Print Utils --------------
static void print_colour(t_colour colour)
{
	printf("\tCol: \t%d, %d, %d\n", colour.r, colour.g, colour.b);
}

static void print_vector(t_vector vec)
{
	printf("%.1f, %.1f, %.1f\n", vec.x, vec.y, vec.z);
}

// ---------------- Ambient Light --------------
static void print_ambi(t_ambi *ambi)
{
	printf("[%s]\n", objects_to_name(ambi->type));
	printf("\tAmbi: \t%.1f\n", ambi->ratio);
	print_colour(ambi->colour);
	printf("\n");
}

// ------------------ Camera --------------
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
// ------------------- Light --------------
static void	print_light(t_light *light)
{
	printf("[%s]\n", objects_to_name(light->type));
	printf("\tPos: \t");
	print_vector(light->position);
	printf("\tBri: \t%.1f\n\n", light->brightness);
}

// ------------------- Planes --------------
static void print_plane(t_object *plane)
{
	printf("[%s]\n", objects_to_name(plane->type));
	printf("\tPos: \t");
	print_vector(plane->position);
	printf("\tDir: \t");
	print_vector(plane->orientation);
	print_colour(plane->colour);
	printf("\n");
}

// ------------------- Spheres --------------
static void	print_sphere(t_object *sphere)
{
	printf("[%s]\n", objects_to_name(sphere->type));
	printf("\tPos: \t");
	print_vector(sphere->position);
	printf("\tDiam: \t%.1f\n", sphere->diameter);
	print_colour(sphere->colour);
	printf("\n");
}

// ------------------- Cylinders --------------
static void	print_cylinder(t_object *cylinder)
{
	printf("[%s]\n", objects_to_name(cylinder->type));
	printf("\tPos: \t");
	print_vector(cylinder->position);
	printf("\tAxis: \t");
	print_vector(cylinder->axis);
	printf("\tDiam: \t%.1f\n",(cylinder->diameter));
	printf("\tHeig: \t%.1f\n",(cylinder->height));
	print_colour(cylinder->colour);
	printf("\n");
}

// ----------------- Print Scene --------------
static void print_objects(t_object *objects)
{
	static const print_object print_func[3] = {print_sphere, print_plane, print_cylinder};
	t_object	*current;

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
	// printf("AMBI %p\n", &(scene->ambi));
	if (&(scene->ambi))
		print_ambi(&(scene->ambi));
	if (&(scene->camera))
		print_camera(&(scene->camera));
	if (&(scene->light))
		print_light(&(scene->light));
	print_objects(scene->objects);
}

// ----------------- Print Viewport --------------

// void	print_viewport(t_scene *scene)
// {
// 	t_ray new; 
	
// 	new = calculate_ray(&(scene->camera), 0, 0);
// 	printf("output for pixel 0,0\n");
// 	printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	new = calculate_ray(&(scene->camera), 799, 0);
// 	printf("output for pixel 799,0\n");
// 	printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	new = calculate_ray(&(scene->camera), 799, 499);
// 	printf("output for pixel 799,499\n");
// 	printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	new = calculate_ray(&(scene->camera), 0, 499);
// 	printf("output for pixel 0,499\n");
// 	printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// }

void	print_ray(t_ray ray, int y, int x)
{
	printf("ray for pixel y[%d] x[%d] = x[%f] y[%f] z[%f]\n", ray.direction.x, ray.direction.y, ray.direction.z);
}
