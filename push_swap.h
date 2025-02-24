/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/24 13:37:52 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

//implantation de la structure pour mes listes chainées, cette structure represente un noeud individuel. Chaque noeud contient une valeur "val" qui pointe vers le suivant "next"; cette struct permet de creer une pile dynamique, qui peut changer de taille, chaque element stocké sous forme de node dans la memoire. 
typedef struct s_pile{
	int	val; //stocke la valeur de noeud
	struct	s_pile *next; //Pointeur vers le prochain noeud
}	t_pile;

//cette structure représente les 2 piles principales manipulable dans le programme; a représente la pile de stockage ou les argc seront placés, la pile b "pile de travail" représente une pile tmp utilisé pendant l'algo de trie. Cette struct piles contient les pointeurs vers mes 2 piles. Chaque pile est une listé chainé composé de plusieurs noeuf (t_pile).
typedef struct piles{
 t_pile *a; //contient tous les arguments données au programme
 t_pile *b; //vide sert a trier avec les deplacements
} 						piles;
//check_arguments
void	ft_check_only_num(char *str);
int		ft_check_sign(char *str, int *i);
void	ft_check_max_min_int(char *str);
void	ft_check_doublon(int argc, char **argv);
void	ft_check_tri(char **argv);
//check_one_string_with_split
char	**ft_split(char const *s);
int		ft_isspace(char c);
int		ft_countmot(char const *s);
char	**ft_freemallocerror(char **bigtab);
int		ft_start(char const *s, int *i);
//check_arguments_utils
char	*ft_substr(char const *s, unsigned int start, size_t len);
//error
char	error(void);
//ft_initilisation_node
//utils
int		ft_atoi(const char *str);
void	init_pile(t_pile **a, int argc, char **argv);
void	*ft_lstadd_front(t_pile **lst, t_pile *new);
void	freepile(t_pile *a);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
int		ft_lstsize(t_pile *lst);
t_pile	*ft_lstlast(t_pile *lst);
t_pile	*ft_lstnew(int val);
//ft_instructions
void	ft_push_pa(t_pile **a, t_pile **b);
void	ft_push_pb(t_pile **b, t_pile **a);
void	ft_reverse_rotate_rra(t_pile **a);
void	ft_reverse_rotate_rrb(t_pile **b);
void	ft_reverse_rotate_rrr(t_pile **a, t_pile **b);
void	ft_rotate_ra(t_pile **a);
void	ft_rotate_rb(t_pile **b);
void	ft_rotate_rr(t_pile **a, t_pile **b);
void	ft_swap_sa(t_pile **a);
void	ft_swap_sb(t_pile **b);
void	ft_swap_ss(t_pile **a, t_pile **b);
//utils_instructions
//push_swap.c
void	*ft_mouvement(t_pile *a, t_pile *b);
void	print_pile(t_pile *a);
t_pile	*ft_lstbefore_last(t_pile *lst);
//ALGO
//mediane
int	mediane(t_pile *a);
void	comparaison_pivot_1(t_pile **a, t_pile **b);
void	move_max_top_a(t_pile **a, int pos);
int	position_max_sup_pivot(t_pile *a, int pivot);
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b, int pivot);
void	transfer_max_b(t_pile **a, t_pile **b, int pivot);
void	decroissant_b(t_pile **b);
void    quick_sort(t_pile **a, t_pile **b);
#endif
