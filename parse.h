#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


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
	char	*line;
	int		fd;
	char	**map;
	char	**map3;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_data;

# include "gnl/get_next_line.h"
# include "check/check.h"

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_isspace(char c);
char	*ft_strmalloc(const char *s);
int		get_opt(t_data *data, char *line, int res);


#endif