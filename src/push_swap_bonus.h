/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:08:04 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/12 18:10:53 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

t_stack		*ft_lstnew(int value, int rank);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rrb(t_stack **stack);
void		rra(t_stack **stack);
void		sa(t_stack **stack);
void		sb(t_stack **stack);
void		back_to_a(t_stack **b, t_stack **a, int len);
int			is_sorted(t_stack *a);
void		free_stack(t_stack **stack);
void		error_exit(t_stack **a, t_stack **b, int *arr);
void		help_sorted(int size, int *arr, t_stack **s_stack);
void		help2_sorted(t_stack **current, int size, int *arr);
void		help_main(int ac, char **av, t_stack **stack_a);
void		find_pos(t_stack **a, int len, int min, int max);
char		*get_next_line(int fd);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
char		*ft_strcpy(char *dest, char *src);
int			ft_strlen(char *s);
char		*ft_after_new_line(char *s);
char		*ft_return(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);
void		prepare(char *s, t_stack **a, t_stack **b);
int			is_double(t_stack *stack);
int			ft_atoi_2(char *str);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		help_the_help(char **s, t_stack **stack_a, t_stack **current);

#endif
