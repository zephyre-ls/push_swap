/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/12 11:52:10 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

void ft_check_only_num(char *str);
void ft_check_max_min_int(char *str);
void ft_check_doublon(int argc, char **argv);
char **ft_split(char const *s);
int ft_isspace(char c);
int ft_countmot(char const *s);
char **ft_freemallocerror(char **bigtab);
int ft_start(char const *s, int *i);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif
