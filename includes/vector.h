/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 17:14:14 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/01/28 21:14:48 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_ray
{
	struct s_vector	origin;
	struct s_vector	direction;
}	t_ray;

t_vector	vec_add(t_vector a, t_vector b);
t_vector	vec_sub(t_vector a, t_vector b);
t_vector	vec_scale(t_vector v, double scalar);
t_vector	vec_negate(t_vector v);
t_vector	vec_cross(t_vector a, t_vector b);
t_vector	vec_normalize(t_vector v);
double		vec_dot(t_vector a, t_vector b);
double		vec_length(t_vector v);

#endif