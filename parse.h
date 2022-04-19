#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
# include "gnl/get_next_line.h"

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int	ft_isspace(char c);

typedef struct s_data
{
	char	*line;
	int		fd;
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_data;

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

#endif