/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:12:07 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 20:38:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "printf.h"

typedef unsigned char	t_byte;
typedef char			t_bool;

# define FALSE 0
# define TRUE  1

/*
** gnl (get_next_line)
*/

# define BUFF_SIZE 32

int				get_next_line(const int fd, char **line);

/*
** atoi-itoa
*/

int				ft_atoi(const char *s);
int				ft_atoi_base(const char *s, char base);

# define BASE16U "0123456789ABCDEF"
# define BASE16L "0123456789abcdef"
# define BASE8   "01234567"

char			*ft_itoa(int n);
char			*ft_itoa_base(int value, char *base);
char			*ft_ulltoa_base(unsigned long long int value, char *base);

char			*ft_lltoa(long long int n);

char			*ft_mtob(void const *ptr, size_t byte_size);
char			*ft_mtob_raw(void const *ptr, size_t byte_size);

char			*ft_ulltoa(unsigned long long int num);
char			*ft_utoa(unsigned int num);
char			*ft_utoa_base(unsigned int value, char *base);

/*
** is
*/

int				ft_isalnum(int c);
int				ft_isalpha(int ch);
int				ft_isascii(int c);
int				ft_is_blank(char c);
int				ft_isprint(int c);
int				ft_isdigit(int c);

/*
** lst
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstappend(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

/*
** mem
*/
void			*ft_mem_rev(void *pointer_v, size_t count);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *d, const void *s, int c, size_t count);
void			*ft_memchr(const void *p, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *source, size_t count);
void			ft_memdel(void **ap);
void			*ft_memdup(const void *source, size_t count);
void			*ft_memmove(void *dest, const void *source, size_t count);
void			*ft_memset(void *buf, int ch, size_t count);

/*
** put
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl_free(char *s);
void			ft_putendl_int_var(const char *var_name, int var);
int				ft_puterror(int error_code, char *err_msg);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr_free(char *s);

/*
** str
*/

char			**ft_str_div_by(char const *str, int divisor);
char			*ft_str_div_by_ins(char const *str, int d, char const *ins);
char			*ft_str_spam(const char *s, int repetitions);
void			ft_str_up(char *s);
void			ft_str_low(char *s);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcfnr(const char *s, int find, int replace);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *dest, const char *source);

void			ft_strdel(char **as);
char			*ft_strdup(const char *source);

int				ft_strequ(char const *s1, char const *s2);

char			*ft_strfnr(char *s, int find, int replace);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2);

size_t			ft_strlcat(char *s1, const char *s2, size_t length);
size_t			ft_strlen(const char *s);

char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strncat(char *s1, const char *s2, size_t count);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *dest, const char *source, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);

char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *s);
char			*ft_str_dup_rev(const char *s);

char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strtrim(char const *s);

/*
** other
*/

int				ft_abs(int a);
long long int	ft_absl(long long int a);

void			*ft_bzero(void *buf, size_t len);

char			*ft_char_to_str(char c);

void			ft_free_char_2d_arr(char ***input);

int				ft_pow(int num, int pow);
unsigned long
long int		power_ten(unsigned char power);

int				ft_return(int cond, int ok, int err, char *emsg);

int				ft_tolower(int ch);
int				ft_toupper(int ch);

int				ft_word_count(const char *s, char c);

#endif
