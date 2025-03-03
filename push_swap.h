/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/03 09:32:18 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

/*
** Implantation de la structure pour les listes chaînées.
** Cette structure représente un nœud individuel. Chaque nœud
** contient une valeur "val" et un pointeur vers le suivant "next".
** Cette structure permet de créer une pile dynamique qui peut
** changer de taille, chaque élément étant stocké sous forme de
** nœud dans la mémoire.
*/
typedef struct s_pile
{
	int				val;// Valeur du nœud
	struct s_pile	*next;// Pointeur vers le nœud suivant
}				t_pile;

/*
** Cette structure représente les deux piles principales manipulables
** dans le programme : la pile "a" contient les arguments donnés
** au programme, et la pile "b" est utilisée temporairement pendant
** l'algorithme de tri.
** Chaque pile est une liste chaînée composée de plusieurs nœuds.
*/
typedef struct piles
{
	t_pile	*a;// Pile des arguments
	t_pile	*b;// Pile de travail
}				t_piles;

/* Fonctions liées à la vérification des arguments */
char	error(void);
int		ft_check_sign(char *str, int *i);
void	ft_check_tri(char **argv);
void	ft_check_only_num(char *str);
void	ft_check_max_min_int(char *str);
void	if_argc_is_2(char **argv, t_pile **a);
void	ft_check_doublon(int argc, char **argv);
void	if_argc_more_than_2(int argc, char **argv, t_pile **a);

/* Fonctions liées à la séparation d'une chaîne en sous-chaînes */
int		ft_isspace(char c);
int		ft_countmot(char const *s);
int		ft_start(char const *s, int *i);
char	**ft_split(char const *s);
char	**ft_freemallocerror(char **bigtab);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Initialisation des nœuds de la pile */
int		ft_lstsize(t_pile *lst);
int		ft_atoi(const char *str);
t_pile	*ft_lstlast(t_pile *lst);
t_pile	*ft_lstnew(int val);
void	freepile(t_pile *a);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
void	*ft_lstadd_front(t_pile **lst, t_pile *new);
void	init_pile(t_pile **a, int argc, char **argv);

/* Fonctions liées aux instructions de manipulation des piles */
void	ft_push_pa(t_pile **a, t_pile **b);
void	ft_push_pb(t_pile **b, t_pile **a);
void	ft_reverse_rotate_rra(t_pile **a);
void	ft_reverse_rotate_rrb(t_pile **b);
void	ft_reverse_rotate_rrr(t_pile **a, t_pile **b);
t_pile	*ft_lstbefore_last(t_pile *lst);
void	ft_rotate_ra(t_pile **a);
void	ft_rotate_rb(t_pile **b);
void	ft_rotate_rr(t_pile **a, t_pile **b);
void	ft_swap_sa(t_pile **a);
void	ft_swap_sb(t_pile **b);
void	ft_swap_ss(t_pile **a, t_pile **b);

/* Fonctions utiles pour l'exécution des instructions */
void	*ft_mouvement(t_pile *a, t_pile *b);
void	print_pile(t_pile *a);

/* Fonctions pour l'algorithme de tri */
int		mediane(t_pile *a);
void	move_max_top_a(t_pile **a, int pos);
int		position_max_min_pivot(t_pile *a, int pivot);
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b);
void	transfer_max_b(t_pile **a, t_pile **b, int pivot);
void	quick_sort(t_pile **a, t_pile **b);
void	tri_3_elements(t_pile **a);
/*Compteur instruction */
void	count_instruction(void);

#endif
