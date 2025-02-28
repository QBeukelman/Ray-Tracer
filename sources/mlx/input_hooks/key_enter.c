
#include "../../../includes/minirt.h"
#include <time.h>

void	key_enter(t_mlx_data *mlx_data, t_scene *scene)
{
		int		msec;
		clock_t time_before;
		clock_t time_diference;

		msec = 0;
		time_before = clock();
		
		render_image(mlx_data, scene);

		time_diference = clock() - time_before;
		msec = time_diference * 1000 / CLOCKS_PER_SEC;
		printf("RENDER [s%d ms%d]\n", msec/1000, msec%1000);
}
