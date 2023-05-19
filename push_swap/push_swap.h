/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:47:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/28 13:31:40 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push
{
	int				size_a;
	int				size_b;
	int				total_size;
	int				bit_size;
	struct s_list	*head_a;
	struct s_list	*head_b;
	struct s_list	*stack_a;
	struct s_list	*stack_b;
}					t_push;

int					*ft_check_argv(int argc, char **argv);
int					*ft_index(int argc, int *input);
void				ft_init(int *index, t_push *push);
void				ft_sa(t_push *push, int print);
void				ft_sb(t_push *push, int print);
void				ft_ss(t_push *push);
void				ft_pa(t_push *push);
void				ft_pb(t_push *push);
void				ft_ra(t_push *push, int print);
void				ft_rb(t_push *push, int print);
void				ft_rr(t_push *push);
void				ft_rra(t_push *push, int print);
void				ft_rrb(t_push *push, int print);
void				ft_rrr(t_push *push);
void				ft_init(int *index, t_push *push);
t_push				*ft_init_push(int argc);
void				ft_radix(t_push *push, int bit);
void				ft_correct(t_push *push);
void				ft_print(t_push *push);
void				ft_small_radix(t_push *push);
int					ft_counter(t_push *push);
void				ft_correct_a(t_push *push);
void				ft_free_split(char **split);

#endif