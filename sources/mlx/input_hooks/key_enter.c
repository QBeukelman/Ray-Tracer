/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_enter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:12:52 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:24:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include <time.h>
#include <pthread.h>

void	*spinner(void *arg)
{
	const char		spinner_chars[] = "|/-\\";
	bool			*is_loading;
	int				i;

	i = 0;
	is_loading = (bool *)arg;
	printf(C_MAGENTA);
	while (*is_loading)
	{
		printf("\r%c Rendering...", spinner_chars[i % 4]);
		fflush(stdout);
		usleep(100000);
		i++;
	}
	printf(RESET_COLOR);
	return (NULL);
}

static void	will_normalize_orientation(t_scene *scene)
{
	t_object	*selected_object;

	if (scene->index_selected >= 3)
	{
		if (scene->edit.editing_prop == O_ORIENTATION)
		{
			selected_object = obj_for_index(scene->objects, \
				scene->index_selected);
			if (selected_object == NULL)
				return ;
			selected_object->orientation = \
				vec_normalize(selected_object->orientation);
		}		
	}
}

void	enter_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	int			msec;
	clock_t		time_before;
	clock_t		time_diff;
	pthread_t	spinner_thread;

	msec = 0;
	time_before = clock();
	scene->is_rendering = true;
	will_normalize_orientation(scene);
	anounce_selection(scene);
	pthread_create(&spinner_thread, NULL, spinner, &scene->is_rendering);
	render_image(mlx_data, scene);
	scene->is_rendering = false;
	pthread_join(spinner_thread, NULL);
	time_diff = clock() - time_before;
	msec = time_diff * 1000 / CLOCKS_PER_SEC;
	anounce_selection(scene);
	printf(C_GREEN);
	printf("Render complete [%ds %dms]\n", msec / 1000, msec % 1000);
	printf(RESET_COLOR);
}
