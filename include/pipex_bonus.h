/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:33:36 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/20 16:23:34 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
#define PIPEX_H

#define BUFFER_SIZE 1

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdarg.h>
#include<string.h>
#include <sys/wait.h>

typedef struct s_pip{
		char *cmd;// command
		char *cmd_path;
		char **spl;
		int is_program;
		struct s_pip *next; // next command
} t_pip;

typedef struct s_data {
	int		ac;
	int  num_cmd;
	char *ft_path;
	char **path_spl;
	char **path;
	char **spl;
	t_pip *pip;
	char *cmd_arg;
	pid_t pid1;
	pid_t pid2;
	int **end;
	int outfile;
	int infile;
	int here_doc;
	int i;
	int j;
}			t_data;

void	ft_exit_ps(char *arg, int err);

char	**ft_split(char const *s, char c);

int	ft_strcmp(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

int	ft_strlen(char const *str);

int	ft_strncmp(char const *s1, char const *s2, unsigned int n);

char *first_str(char *av);

char *get_str(char **envp,int i,char *path);

char *get_path(char *envp[]);

char	**add_back_slash(char *envp[],t_data *data);

char *str_space(char *str);

int	counter(char **map);

void	child_process_exe(t_data *data, char *envp[], int i);

void	child2_process_exe(t_data *data, char *envp[], int i);

void	child_process_all(t_data *data, char *envp[], int i);
char	*get_thecmd(t_data data);
void	free_all(t_data *data);
void	pipex_mandatory(t_data *data, char **av, char *envp[]);
int		check_if_path(t_data *data);

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

//********************************************/

char	*get_next_line(int fd);
int	ft_indexof(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_g(const char *s1, const char *s2);
char	*ft_save_remainder(char *line, char *remainder);
//********************************************/


void	free_array(char **str);

#endif