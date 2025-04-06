/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:35:09 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/20 21:17:37 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_dlist;

char				*ft_strtrim_all(const char *s1, const char *set);
int					ft_isspace(char c);
int					ft_strisspace(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
char				*get_next_line(int fd);
char				*gnl_strchr(char *buffer, int c);
char				*gnl_strjoin(char *buffer, char *temp);
int					gnl_strlen(char *str);
int					ft_printf(const char *imput, ...);
int					print_char(int c);
int					print_string(char *s);
int					print_hex(unsigned long int ap, int imput);
int					print_number(int number);
int					print_unsigned(unsigned int number);
int					print_pointer(void *ptr);

// Doubly linked list
void				ft_dlstadd_after_another(t_dlist *node,
						t_dlist *node_to_insert);
void				ft_dlstadd_front(t_dlist **list, t_dlist *new);
void				dlstclear(t_dlist **list, void (*del)(void*));
void				ft_dlstdel_first(t_dlist **list, void (*del)(void*));
void				ft_dlstdel_last(t_dlist *lst, void (*del)(void*));
void				ft_dlstdelone(t_dlist *list, void (*del)(void*));
t_dlist				*ft_dlstlast(t_dlist *list);
t_dlist				*ft_dlstnew(void *data);
int					dlstsize(t_dlist *list);

#endif
