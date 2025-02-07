/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_cleanup.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/19 12:54:07 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/02/07 02:06:32 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	free_split(char **split)
{
	int		i;

	i = 0;
	if (split == NULL)
		return;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

// // ------------------------------------------------------------/ Components
// static void	free_planes(t_plane *planes)
// {
// 	t_plane		*prev_plane;

// 	while (planes)
// 	{
// 		free (planes->position);
// 		free (planes->orientation);
// 		free (planes->color);
// 		prev_plane = planes;
// 		planes = planes->next;
// 		prev_plane->next = NULL;
// 		free (prev_plane);
// 	}
// }

// static void free_spheres(t_sphere *spheres)
// {
// 	t_sphere	*prev_sphere;

// 	while (spheres)
// 	{
// 		free (spheres->position);
// 		free (spheres->color);
// 		prev_sphere = spheres;
// 		spheres = spheres->next;
// 		prev_sphere->next = NULL;
// 		free (prev_sphere);
// 	}
// }

// static void	free_cylinders(t_cylinder *cylinders)
// {
// 	t_cylinder		*prev_cylinder;

// 	while (cylinders)
// 	{
// 		free (cylinders->position);
// 		free (cylinders->axis);
// 		free (cylinders->color);
// 		prev_cylinder = cylinders;
// 		cylinders = cylinders->next;
// 		prev_cylinder->next = NULL;
// 		free (prev_cylinder);
// 	}
// }

// void	free_scene(t_scene *scene)
// {
// 	if (scene->ambi)
// 	{
// 		free (scene->ambi->color);
// 		free (scene->ambi);
// 	}
// 	if (scene->camera)
// 	{
// 		free (scene->camera->position);
// 		free (scene->camera->orientation);
// 		free (scene->camera);
// 	}
// 	if (scene->light)
// 	{
// 		free (scene->light->position);
// 		free (scene->light);
// 	}
// 	if (scene->planes)
// 		free_planes(scene->planes);
// 	if (scene->spheres)
// 		free_spheres(scene->spheres);
// 	if (scene->cylinders)
// 		free_cylinders(scene->cylinders);
// 	free (scene);
// }
