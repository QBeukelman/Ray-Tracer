/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:38:49 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/22 14:14:01 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define CONST2 -2.0
# define CONST4 4
static bool nearest_collision(double a, double b, double discriminant, double *nearest)
{
    const double sqrt_d = sqrt(discriminant);
    const double t1 = (-b - sqrt_d) / (2 * a);
    const double t2 = (-b + sqrt_d) / (2 * a);

    if (t1 > 0 && t1 < *nearest) 
    {
        *nearest = t1;
        return (true);
    }
    if (t2 > 0 && t2 < *nearest) 
    {
        *nearest = t2;
        return (true);
    }
    return (false);
}

bool hit_sphere(t_object *sphere, t_ray *ray, double *nearest)
{
	t_vector		oc;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	const double	radius_sq = (sphere->diameter/2) * (sphere->diameter/2);
	
	oc = vec_sub(sphere->position, ray->origin);
	a = vec_dot(ray->direction, ray->direction);
	b = CONST2 * vec_dot(ray->direction, oc);
	c = vec_dot(oc, oc) - radius_sq;
	discriminant = ((b*b) - CONST4*a*c);
	
	if (discriminant < 0)
		return (false);
	return (nearest_collision(a, b, discriminant, nearest));
}
