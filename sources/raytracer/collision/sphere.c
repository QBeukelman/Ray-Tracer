/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/22 12:38:49 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/03/08 23:51:48 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define CONST_2 2.0
# define CONST_MIN_2 -2.0
# define CONST_4 4

static double collision_dst(double a, double b, double discriminant)
{
    const double sqrt_d = sqrt(discriminant);
    double t1 = (-b - sqrt_d) / (CONST_2 * a);
    double t2 = (-b + sqrt_d) / (CONST_2 * a);
    
    if (t1 < 0 && t2 < 0)
        return (-1);
    
    return ((t1 > 0) ? t1 : t2);
}

bool	sphere_collision(t_object *sphere, t_ray ray, t_collision *collision)
{
	const t_vector		oc = vec_sub(sphere->position, ray.origin);
	const double		a = vec_dot(ray.direction, ray.direction);
	const double		b = CONST_MIN_2 * vec_dot(ray.direction, oc);
	const double 		c = vec_dot(oc, oc) - (sphere->diameter / 2) * (sphere->diameter / 2);
	const double		discriminant = ((b * b) - CONST_4 * a * c);

	if (discriminant < 0)
		return (false);

	const double t = collision_dst(a, b, discriminant);

    if (t <= 0)
        return (false);
    
    collision->distance = t;
    collision->collision_point = vec_add(ray.origin, vec_scale(ray.direction, t));
    collision->surface_normal = vec_normalize(vec_sub(collision->collision_point, sphere->position));
    collision->closest_obj = sphere;
	return (true);
}
