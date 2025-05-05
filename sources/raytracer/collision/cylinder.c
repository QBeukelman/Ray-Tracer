/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/24 16:43:15 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/05/05 19:44:16 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static bool	solve_for_t(double *t, t_cylinder *c, t_object *cyl, t_ray ray)
{
	double			discriminant;
	t_quadratic		q;
	t_vector		half_height;
	t_vector		ray_to_axis_cross;
	t_vector		orientation_cross;

	half_height = vec_scale(cyl->orientation, cyl->height * 0.5);
	c->top_center = vec_add(cyl->position, half_height);
	c->bottom_center = vec_sub(cyl->position, half_height);
	ray_to_axis_cross = vec_cross(cyl->orientation, ray.direction);
	c->center_to_origin = vec_sub(ray.origin, cyl->position);
	orientation_cross = vec_cross(c->center_to_origin, cyl->orientation);
	q.a = vec_dot(ray_to_axis_cross, ray_to_axis_cross);
	q.b = CONST_2 * vec_dot(ray_to_axis_cross, orientation_cross);
	q.c = vec_dot(orientation_cross, orientation_cross) \
		- (cyl->radius * cyl->radius);
	discriminant = ((q.b * q.b) - CONST_4 * q.a * q.c);
	if (discriminant < 0)
		return (false);
	*t = collision_dst(q.a, q.b, discriminant);
	if (*t <= 0)
		return (false);
	return (true);
}

static bool	hit_top(t_cylinder c, t_object *cyl, t_ray ray, t_collision *col)
{
	double		t;
	double		denominator;

	denominator = hit_flat_plane(&t, ray, c.top_center, cyl->orientation);
	if (denominator == 0.0 || t < 0 || t > col->distance)
		return (false);
	c.hit = vec_add(vec_scale(ray.direction, t), ray.origin);
	if (vec_length(vec_sub(c.hit, c.top_center)) > (cyl->radius))
		return (false);
	col->closest_obj = cyl;
	col->collision_point = c.hit;
	col->distance = t;
	if (denominator < 0)
		col->surface_normal = cyl->orientation;
	else
		col->surface_normal = vec_negate(cyl->orientation);
	return (true);
}

static bool	hit_bottom(t_cylinder c, t_object *cyl, t_ray ray, t_collision *col)
{
	double		t;
	double		denominator;

	denominator = hit_flat_plane(&t, ray, c.bottom_center, cyl->orientation);
	if (denominator == 0.0 || t < 0 || t > col->distance)
		return (false);
	c.hit = vec_add(vec_scale(ray.direction, t), ray.origin);
	if (vec_length(vec_sub(c.hit, c.bottom_center)) > (cyl->radius))
		return (false);
	col->closest_obj = cyl;
	col->collision_point = c.hit;
	col->distance = t;
	if (denominator < 0)
		col->surface_normal = cyl->orientation;
	else
		col->surface_normal = vec_negate(cyl->orientation);
	return (true);
}

static bool	hit_body(t_cylinder *c, t_object *cyl, t_ray ray, t_collision *col)
{
	double			t;
	t_vector		body_from_center;
	double			axis_distance;

	if (solve_for_t(&t, c, cyl, ray) == false || t > col->distance)
		return (false);
	c->hit = vec_add(ray.origin, vec_scale(ray.direction, t));
	body_from_center = vec_sub(c->hit, cyl->position);
	axis_distance = vec_dot(body_from_center, cyl->orientation);
	if (fabs(axis_distance) > (cyl->height / 2))
		return (false);
	col->distance = t;
	col->collision_point = c->hit;
	col->surface_normal = vec_normalize(vec_sub(body_from_center, \
		vec_scale(cyl->orientation, axis_distance)));
	col->closest_obj = cyl;
	return (true);
}

bool	cylinder_collision(t_object *cylinder, t_ray ray, t_collision *col)
{
	t_cylinder	c;
	bool		hit;

	ft_memset(&c, 0, sizeof(c));
	hit = false;
	if (hit_body(&c, cylinder, ray, col))
		hit = true;
	if (hit_top(c, cylinder, ray, col))
		hit = true;
	if (hit_bottom(c, cylinder, ray, col))
		hit = true;
	return (hit);
}
