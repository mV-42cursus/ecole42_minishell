/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:01:14 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 16:03:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node {
	void			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_queue {
	struct s_node	*front;
	struct s_node	*rear;
}	t_queue;

/* bit_mask */
int		ft_is_bit_set_7(char variable, int bit_position);
int		ft_is_bit_set_8(unsigned char variable, int bit_position);

/* data_structure -> linked_list */
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstclear(t_node **lst, void (*del)(void*));
void	ft_lstdelone(t_node *lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, void (*f)(void *));
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));
t_node	*ft_lstnew(void *content);
int		ft_lstsize(t_node *lst);

/* data_structure -> queue */
void	enqueue(struct s_queue *queue, void *data);
void	*dequeue(struct s_queue *queue);
int		is_empty(struct s_queue **queue);

/* display */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* error */
void	ft_exit(char *msg, int flag);

/* is_verification */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* memory */
void	*ft_calloc_exit(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t n);
void	leaks(void);

/* numeric */
int		ft_atoi(const char *nptr);
int		ft_atoi_original(const char *nptr);
char	*ft_itoa(int n);

/* string */
void	ft_bzero(void *s, size_t n);
char	*ft_erase(char *str, int start, int end);
char	*ft_insert(char *str, int i, char *src);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *string1, const char *string2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin_free(char *s1, char *s2, int flag);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *str);
int		ft_strlen_null(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* helper */

# define NONE -1
# define FIRST 0
# define SECOND 1
# define BOTH 2

#endif
