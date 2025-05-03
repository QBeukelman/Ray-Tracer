/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 16:33:16 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/03 13:37:39 by quentinbeuk   ########   odam.nl         */
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

void	print_value(float value, bool is_hilighted, e_edit_vec vec)
{
	if (is_hilighted)
		printf(C_YELLOW);
	if (vec == V_X)
		printf("\t\tx: ");
	if (vec == V_Y)
		printf("\t\ty: ");
	if (vec == V_Z)
		printf("\t\tz: ");
	if (vec == V_NONE)
		printf("\t\tf: %.1f\n", value);
	else
		printf("%.1f\n", value);
	printf(RESET_COLOR);
}

void print_color(t_color color)
{
	printf("\tCol: \t%d, %d, %d\n", color.r, color.g, color.b);
}
