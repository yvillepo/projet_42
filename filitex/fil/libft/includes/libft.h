/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/08 21:15:04 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define ABS(x) x < 0 ? -x : x
# define INIT(t, v, i) t v = i
# define SIGN(x) x < 0 ? -1 : (x > 0)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_alist
{
	int				id;
	void			*content;
	size_t			content_size;
	struct s_alist	*last;
	struct s_alist	*next;
}					t_alist;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int c);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(char *str1, char *str2, size_t n);
char				*ft_strrchr(const char *str, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char *str1, char *str2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_puttab(char **tab);
void				ft_puttab_fd(char **tab, int fd);
void				ft_putlist(t_list **sl);
void				ft_putlist_fd(t_list **sl, int fd);
void				ft_lstappend(t_list **alst, t_list *new);
t_alist				*ft_alstnew(int id, void *content, size_t content_size);
void				ft_alstadd(t_alist *lst, t_alist *new);
void				ft_alstdel(t_alist *lst, void (*del)(void *, size_t));
void				ft_alstdelone(t_alist *lst, void (*del)(void *, size_t));
void				ft_alstappend(t_alist *lst, t_alist *new);
void				ft_alstiter(t_alist *lst, void (*f)(t_alist *elem));
t_alist				*ft_alstmap(t_alist *lst, t_alist *(*f)(t_alist *elem));
t_alist				*ft_alsttop(t_alist *lst);
t_alist				*ft_alstbot(t_alist *lst);
t_alist				*ft_alssearchid(int id, t_alist *lst);
t_alist				*ft_alstdeltop(t_alist *lst, void (*del)(void *, size_t));
t_alist				*ft_alstdelbot(t_alist *lst, void (*del)(void *, size_t));
t_alist				*ft_alstdelnode(t_alist *lst, void (*del)(void *, size_t));
int					ft_isspace(int c);
int					ft_strcntc(char const *str, char c);
char				*ft_readfile(int fd);

#endif
