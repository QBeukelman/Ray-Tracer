/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perser_post_validation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 10:11:31 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 10:21:14 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

bool	validate_non_objects(t_scene *scene)
{
	if (scene->camera.initialized == false)
	{
		show_error(E_MISSING_OBJ, "Camera");
		return (false);
	}
	if (scene->light.initialized == false)
	{
		show_error(E_MISSING_OBJ, "Point light");
		return (false);
	}
	if (scene->ambi.initialized == false)
	{
		show_error(E_MISSING_OBJ, "Ambient light");
		return (false);
	}
	return (true);
}
