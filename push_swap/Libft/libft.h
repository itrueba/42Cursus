/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:08:55 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 12:08:41 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
void				*ft_memset(void *b, int c, size_t len);
long long int		ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
t_list				*ft_lstnew(int content);
t_list				*ft_pre_lstlast(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
int					ft_count_size(char const *s, char c);
char				*ft_itoa(int nb);
int					ft_strncmp(char *s1, char *s2, size_t n);

#endif