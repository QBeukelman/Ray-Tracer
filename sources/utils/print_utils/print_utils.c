/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 16:33:16 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 20:54:16 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_label(const char *label, bool is_hilighted)
{
	if (is_hilighted)
		printf(C_YELLOW);
	printf("\t%s\n", label);
	printf(RESET_COLOR);
}

void	print_value(float value, bool is_hilighted)
{
	if (is_hilighted)
		printf(C_YELLOW);
	printf("\t\t%.1f\n", value);
	printf(RESET_COLOR);
}

void print_colour(t_colour colour)
{
	printf("\tCol: \t%d, %d, %d\n", colour.r, colour.g, colour.b);
}
