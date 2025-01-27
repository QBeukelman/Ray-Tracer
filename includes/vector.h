/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 17:14:14 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/01/27 17:20:17 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct t_vector
{
	double	x;
	double	y;
	double	z;
}	s_vector;

typedef struct t_point
{
	double	x;
	double	y;
	double	z;
}	s_point;

typedef struct t_ray
{
	struct t_point	origin;
	struct t_vector	direction;
}	s_ray;

