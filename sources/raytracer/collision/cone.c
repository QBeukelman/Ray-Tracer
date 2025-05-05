/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:43:24 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/05/05 18:37:16 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static bool	solve_for_t(double *t, t_cone *c, t_object *cone, t_ray ray)
{
	double			discriminant;
	t_quadratic		q;
	t_vector		half_height;
	t_vector		tip_to_origin;

	half_height = vec_scale(cone->orientation, cone->height * 0.5);
	c->tip = vec_sub(cone->position, half_height);
	c->base = vec_add(cone->position, half_height);
	tip_to_origin = vec_sub(ray.origin, c->tip);
	c->ray_dot_axis = vec_dot(ray.direction, cone->orientation);
	c->tipray_dot_axis = vec_dot(tip_to_origin, cone->orientation);
	c->tan_theta_sqr = pow(cone->radius, 2) / pow(cone->height, 2);
	q.a = 1 - c->tan_theta_sqr * pow(c->ray_dot_axis,2) - pow(c->ray_dot_axis,2);
	q.b = CONST_MIN_2 * (vec_dot(ray.direction, tip_to_origin) - c->tan_theta_sqr * c->ray_dot_axis * c->tipray_dot_axis - c->ray_dot_axis * c->tipray_dot_axis);
	q.c = vec_dot(tip_to_origin, tip_to_origin) - c->tan_theta_sqr * pow(c->tipray_dot_axis, 2) - pow(c->tipray_dot_axis, 2);
	discriminant = q.b * q.b - CONST_4 * q.a * q.c;
	if (discriminant < 0)
		return (false);
	*t = collision_dst(q.a, q.b, discriminant);
	if (*t <= 0)
		return (false);
	return (true);
}

static bool	hit_base(t_cone c, t_object *cone, t_ray ray, t_collision *col)
{
	double		t;
	double		denominator;
	t_vector	hit;

	denominator = hit_flat_plane(&t, ray, c.base, cone->orientation);
	if (denominator == 0.0 || t < 0 || t > col->distance)
		return (false);
	hit = vec_add(vec_scale(ray.direction, t), ray.origin);
	if (vec_length(vec_sub(hit, c.base)) > cone->radius)
		return (false);
	col->closest_obj = cone;
	col->collision_point = hit;
	col->distance = t;
	if (denominator < 0)
		col->surface_normal = cone->orientation;
	else
		col->surface_normal = vec_negate(cone->orientation);
	return (true);
}

static bool	hit_body(t_cone *c, t_object *cone, t_ray ray, t_collision *col)
{
	double			t;
	t_vector		hit;
	t_vector		tip_to_hit;
	double			hit_height;

	if (solve_for_t(&t, c, cone, ray) == false || t > col->distance)
		return (false);
	hit = vec_add(ray.origin, vec_scale(ray.direction, t));
	tip_to_hit = vec_sub(hit, c->tip);
	hit_height = vec_dot(tip_to_hit, cone->orientation);
	if (hit_height < 0 || hit_height > cone->height)
		return (false);
	col->distance = t;
	col->collision_point = hit;
	col->surface_normal = vec_normalize(vec_sub(tip_to_hit, vec_scale(cone->orientation, hit_height)));
	if (vec_dot(col->surface_normal, ray.direction) > 0)
		col->surface_normal = vec_negate(col->surface_normal);
	col->closest_obj = cone;
	return (true);
}

bool	cone_collision(t_object *cone, t_ray ray, t_collision *col)
{
	t_cone		c;
	bool		hit;

	ft_memset(&c, 0, sizeof(c));
	hit = false;
	if (hit_body(&c, cone, ray, col))
		hit = true;
	if (hit_base(c, cone, ray, col))
		hit = true;
	return (hit);
}
