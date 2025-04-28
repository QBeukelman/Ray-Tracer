/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 16:33:16 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 22:38:26 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

// ------------------ Print Utils --------------
void print_colour(t_colour colour)
{
	printf("\tCol: \t%d, %d, %d\n", colour.r, colour.g, colour.b);
}
