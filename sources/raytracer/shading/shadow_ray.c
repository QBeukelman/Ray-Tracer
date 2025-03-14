/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shadow_ray.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/09 20:16:16 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/03/10 13:25:41 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

// bool	object_in_shadow(t_collision *col, t_light *light, t_object *objects)
// {
// 	t_vector	shadow_ray;
// 	t_collision	hit;

// 	shadow_ray = vec_normalize(vec_sub(light->position, col->collision_point));
// 	if (is_collision(objects, shadow_ray, &hit) == true)
// 	{
// 		return (true);
// 	}
// 	return (false);
// }