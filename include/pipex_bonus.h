/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:33:36 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 15:46:15 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_SIZE 1

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdarg.h>
# include<string.h>
# include <sys/wait.h>

typedef struct s_pip
{
	char			*cmd;
	char			*cmd_path;
	char			**spl;
	int				is_program;
	struct s_pip	*next;
}		t_pip;

typedef struct s_data
{
	int		ac;
	int		num_cmd;
	char	*ft_path;
	char	**path_spl;
	char	**path;
	char	**spl;
	t_pip	*pip;
	int		**end;
	pid_t	pid1;
	pid_t	pid2;
	int		outfile;
	int		infile;
	int		here_doc;
	int		i;
	int		j;
}			t_data;
//*Prototypes Tools ******************************************//
void	ft_exit_ps(char *arg, int err);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strlen(char const *str);
int		ft_strncmp(char const *s1, char const *s2, unsigned int n);
char	*str_space(char *str);
char	*first_str(char *av);
//***********************X***************************//
t_pip	*get_p(t_data *data, int num_cmd);
char	*get_str(char **envp, int i, char *path);
char	*get_path(char *envp[]);
char	*get_thecmd(t_data data);
char	**add_back_slash(char *envp[], t_data *data);
int		counter(char **map);
int		check_if_path(t_data *data);
void	open_file(t_data *data, char **av, int ac);
void	close_pipes(t_data *data);

//*Prototypes free.c**************************************//
void	free_all(t_data *data);
void	free_array(char **str);
void	free_single_pip(t_pip *data);
//***********************X***************************//

//* Prototypes of ft_printf *****************************//

int		ft_2lowerhexa(unsigned int nb);
int		ft_checkprintf(char a, va_list *av);
int		ft_checksize(long long nb);
int		ft_printf(const char *format, ...);
int		ft_point(long unsigned nb);
int		ft_putdeci(unsigned int nb);
int		ft_upperhexa(unsigned int nb);
int		ft_lowerhexa(unsigned long nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long int nb);

//********************************************/

//*Prototypes of Get_Next_line******************************//
char	*get_next_line(int fd);
int		ft_indexof(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_g(const char *s1, const char *s2);
char	*ft_save_remainder(char *line, char *remainder);
//********************************************/
void	check_here_doc(t_data *data, char **av);
void	check_path(t_data *data);
//*Prototypes pipe.c********************************//

void	nbr_pipe(t_data *data, int ac);
t_pip	*pip_alloc(char **av, int ac, int here_doc);
void	malloc_pip(t_data *data, int size);
void	ft_dup2(t_data *data);

//***********************X***************************//
#endif