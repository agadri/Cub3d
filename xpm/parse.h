
  
#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

# include "mlx/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define ESC	65307

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1000

# define WALL1 "./xpm/sand_floor.xpm"
# define WALL2 "./xpm/sand.xpm"
# define WALL3 "./xpm/stone_wall.xpm"
# define WALL4 "./xpm/stone.xpm"

typedef struct s_pers
{
	int		pos_x;
	int		pos_y;
	char	dir_pers;
	int		dir_x_pers;
	int		dire_y_pers;
}				t_pers;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		endian;
	int		line;
	int		status;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;

	t_pers	pers;
	char	*line;
	int		fd;
	char	**map;
	char	**map3;
	int		width;
	int		lenght;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	int		exit;
}	t_data;

# include "gnl/get_next_line.h"
# include "check/check.h"
# include "init/init_all.h"
# include "move/move.h"
# include "draw/draw.h"
# include "exit/free.h"

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_isspace(char c);
char	*ft_strmalloc(const char *s);
int		get_opt(t_data *data, char *line, int res);
void	exit_opt(t_data *data, char *msg);
int		ft_strlen(char *str);
int		size_width(t_data *data);
int		size_lenght(t_data *data);
char	*ft_str3dup(char *s, t_data *data);
void	*ft_memset(void *b, int c, unsigned int len);
int		get_map(t_data *data, char **av);
char	*ft_strdup(char *src);

#endif