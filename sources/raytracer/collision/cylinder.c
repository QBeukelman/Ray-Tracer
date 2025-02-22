/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/24 16:43:15 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/05/01 17:20:17 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define CONST_2 2.0
# define CONST_MIN_2 -2.0
# define CONST_4 4

static void	set_calculation_data(t_cylinder *c, t_object *obj, t_ray ray)
{
	t_vector	half_height;

	half_height = vec_scale(obj->orientation, (obj->height / 2));
	c->top_center = vec_add(obj->position, half_height);
	c->bottom_center = vec_sub(obj->position, half_height);
	c->ray_to_axis_cross = vec_cross(obj->orientation, ray.direction);
	c->center_to_origin = vec_sub(ray.origin, obj->position);
	c->orientation_cross = vec_cross(c->center_to_origin, obj->orientation);
}

static bool	hit_top(t_cylinder c, t_object *cylinder, t_ray ray, t_collision *col)
{
	double		t;
	double		denominator;

	denominator = hit_flat_plane(&t, ray, c.top_center, cylinder->orientation);
	if (denominator == 0.0 || t < 0)
		return (false);
	c.hit_point = vec_add(vec_scale(ray.direction, t), ray.origin);
	if (vec_length(vec_sub(c.hit_point, c.top_center)) > (cylinder->radius))
		return (false);
	col->closest_obj = cylinder;
	col->collision_point = c.hit_point;
	col->distance = t;
	if (denominator < 0)
		col->surface_normal = cylinder->orientation;
	else
		col->surface_normal = vec_negate(cylinder->orientation);
	return (true);
}

static bool	hit_bottom(t_cylinder c, t_object *cylinder, t_ray ray, t_collision *col)
{
	double		t;
	double		denominator;

	denominator = hit_flat_plane(&t, ray, c.bottom_center, cylinder->orientation);
	if (denominator == 0.0 || t < 0 || t > col->distance)
		return (false);
	c.hit_point = vec_add(vec_scale(ray.direction, t), ray.origin);
	if (vec_length(vec_sub(c.hit_point, c.bottom_center)) > (cylinder->radius))
		return (false);
	col->closest_obj = cylinder;
	col->collision_point = c.hit_point;
	col->distance = t;
	if (denominator < 0)
		col->surface_normal = cylinder->orientation;
	else
		col->surface_normal = vec_negate(cylinder->orientation);
	return (true);
}

static bool	hit_body(t_cylinder c, t_object *cylinder, t_ray ray, t_collision *col)
{
	t_quadratic		q;
	t_vector		to_center;
	double			discriminant;
	double			t;

	q.a = vec_dot(c.ray_to_axis_cross, c.ray_to_axis_cross);
	q.b = CONST_2 * vec_dot(c.ray_to_axis_cross, c.orientation_cross);
	q.c = vec_dot(c.orientation_cross, c.orientation_cross) - (cylinder->radius * cylinder->radius);
	discriminant = ((q.b * q.b) - CONST_4 * q.a * q.c);
	if (discriminant < 0)
		return (false);
	t = collision_dst(q.a, q.b, discriminant);
	if (t <= 0 || t > col->distance)
		return (false);
	c.hit_point = vec_add(ray.origin, vec_scale(ray.direction, t));
	c.body_from_center = vec_sub(c.hit_point, cylinder->position);
	c.axis_distance = vec_dot(c.body_from_center, cylinder->orientation);
	if (fabs(c.axis_distance) > (cylinder->height / 2))
		return (false);
	col->distance = t;
	col->collision_point = c.hit_point;
	col->surface_normal = vec_normalize(vec_sub(c.body_from_center, vec_scale(cylinder->orientation, c.axis_distance)));
	col->closest_obj = cylinder;
	return (true);
}

bool	cylinder_collision(t_object *cylinder, t_ray ray, t_collision *col)
{
	t_cylinder	c;
	bool		hit;

	ft_memset(&c, 0, sizeof(c));
	set_calculation_data(&c, cylinder, ray);
	hit = false;
	if (hit_top(c, cylinder, ray, col))
		hit = true;
	if (hit_bottom(c, cylinder, ray, col))
		hit = true;
	if (hit_body(c, cylinder, ray, col))
		hit = true;
	return (hit);
}