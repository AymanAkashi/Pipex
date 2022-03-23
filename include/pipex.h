/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:10:57 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/23 16:14:19 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
#define PIPEX_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

typedef struct s_data {
	char *ft_path;
	char **path_spl;
	char **path;
	char **spl;
	char *cmd_arg;
	pid_t pid1;
	pid_t pid2;
	int end[2];
	int outfile;
	int infile;
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

void	child_process_exe(t_data *data, char *envp[], char **av);

void	child2_process_exe(t_data *data, char *envp[], char **av);

char	*get_thecmd(t_data data);

void	free_all(t_data *data);

#endif