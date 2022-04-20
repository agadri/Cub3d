#ifndef CHECK_H
# define CHECK_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../parse.h"



void	change_space_to_3(t_data *data);
int	check_line_close(t_data *data, int line);
int	check_if_is_close(t_data *data);

#endif