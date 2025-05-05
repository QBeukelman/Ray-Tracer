/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 19:39:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:41:40 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	compute_tip_and_base(t_cone *c, t_object *cone)
{
	t_vector	half_height;

	half_height = vec_scale(cone->orientation, cone->height * 0.5);
	c->tip = vec_sub(cone->position, half_height);
	c->base = vec_add(cone->position, half_height);
}

static void	compute_ray_cone_parameters(t_cone *c, t_object *cone, t_ray ray)
{
	t_vector	tip_to_origin;

	tip_to_origin = vec_sub(ray.origin, c->tip);
	c->ray_dot_axis = vec_dot(ray.direction, cone->orientation);
	c->tipray_dot_axis = vec_dot(tip_to_origin, cone->orientation);
	c->tan_theta_sqr = pow(cone->radius, 2) / pow(cone->height, 2);
}

static t_quadratic	setup_quadratic(t_cone *c, t_ray ray)
{
	t_quadratic		q;
	t_vector		tip_to_origin;
	double			d_dot_to;
	double			tip_to_origin_len_sqr;

	tip_to_origin = vec_sub(ray.origin, c->tip);
	d_dot_to = vec_dot(ray.direction, tip_to_origin);
	tip_to_origin_len_sqr = vec_dot(tip_to_origin, tip_to_origin);
	q.a = 1 - c->tan_theta_sqr * pow(c->ray_dot_axis, 2)
		- pow(c->ray_dot_axis, 2);
	q.b = CONST_MIN_2 * (d_dot_to - c->tan_theta_sqr * c->ray_dot_axis * \
		c->tipray_dot_axis - c->ray_dot_axis * c->tipray_dot_axis);
	q.c = tip_to_origin_len_sqr - c->tan_theta_sqr * pow(c->tipray_dot_axis, 2) \
		- pow(c->tipray_dot_axis, 2);
	return (q);
}

/**
 * solve_for_t - Solves for the intersection between a ray and a finite cone.
 *
 * @t: Pointer to the variable that will hold the intersection distance 
 * if it exists.
 * @c: Pointer to a cone-specific intersection data structure (t_cone).
 * @cone: Pointer to the cone object, which holds geometry data like position,
 * height, radius, and orientation.
 * @ray: The ray to be tested for intersection with the cone.
 *
 * Return: true if the ray intersects the cone and t > 0
 * (i.e., in front of the ray origin), false otherwise.
 *
 * This function works by:
 * 1. Computing the tip and base of the cone from its position and orientation.
 * 2. Calculating dot products and other terms related to the ray and cone axis.
 * 3. Setting up a quadratic equation derived from substituting the ray equation
 *    into the implicit surface equation of the cone.
 * 4. Computing the discriminant to check for real solutions.
 * 5. Returning the smallest positive intersection distance, if it exists.
*/
bool	solve_for_t_cone(double *t, t_cone *c, t_object *cone, t_ray ray)
{
	t_quadratic	q;
	double		discriminant;

	compute_tip_and_base(c, cone);
	compute_ray_cone_parameters(c, cone, ray);
	q = setup_quadratic(c, ray);
	discriminant = q.b * q.b - CONST_4 * q.a * q.c;
	if (discriminant < 0)
		return (false);
	*t = collision_dst(q.a, q.b, discriminant);
	return (*t > 0);
}
