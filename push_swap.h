/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/06 15:55:37 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h> 

// noeud liste chaine, val = entier aui stocke la valeur du noeud, next = pointeur vers le prochain element de la liste
typedef struct s_pile {
	int	val;	//Donnee (valeur de l elem)
	struct s_pile *next; //Pointeur vers le prochain noeud
}							t_pile;

// deux pointeur (a et b) chacun pointe vers la tete d une liste chaine 
// a = contient tous les arguments donnes au pgrommae
// b = vide au debut sert unisauement a trier les nombres avec les deplacement
typedef struct pile {
	t_list *a;
	t_list *b;
}					pile;


//fonction principal et main
//int	main(int argc, char **argv)
//int	push_swap()
//fonction en lien avec la manipulation des liste chainees
void	ft_lstaddfront(t_list *lst, t_list *new);

//check error arguments
//void	ft_check_arguments(char *str);
void	ft_check_only_num(char *str);
void	ft_check_max_min_int(char *str);
void	ft_check_doublon(int argc, char **argv);

/*mouvements possibles
int	ft_reverse_rotate_rra()
int	ft_reverse_rotate_rrb()
int	ft_reverse_rotate_rrr()
int	ft_rotate_ra()
int	ft_rotate_rb()
int	ft_rotate_rr()
int	ft_swap_sa()
int	ft_swap_sb()
int	ft_swap_ss()
int	ft_push_pa()
int	ft_push_pb()
*/
#endif
