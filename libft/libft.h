/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   libft.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/09 17:23:00 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:25:11 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

// checks if c is an alphanumeric character
int		ft_isalpha(int c);
// checks if c is a digit
int		ft_isdigit(int c);
// checks if c is a digit or an alphanumeric character
int		ft_isalnum(int c);
// checks if c is ascii
int		ft_isascii(int c);
// checks if c is printable
int		ft_isprint(int c);

// sets the first n bytes of s to c
void	*ft_memset(void *s, int c, size_t n);
// sets the first n bytes of s to 0
void	*ft_bzero(void *s, size_t n);
// copies the first n bytes of src to dest (breaks if the areas overlap)
void	*ft_memcpy(void *dest, void *src, size_t n);
// copies the first n bytes of src to dest (if they overlap src is overwritten)
void	*ft_memmove(void *dest, void *src, size_t n);

// copies src to dst
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// concatenates src to the end of dst
// returns the length of the string that was created
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// converts the character to upper case if it is lowercase
int		ft_toupper(int c);
// converts the character to upper case if it is lowercase
int		ft_tolower(int c);

// finds the *first* occurance of `c` in `s`
char	*ft_strchr(const char *s, int c);
// finds the *last* occurance of `c` in `s`
char	*ft_strrchr(const char *s, int c);

size_t	ft_strlen(const char *s);
// compare the first N characters of the string
// returns the difference of the strings at the first differing character
// returns 0 if the strings are identical
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// create a substring from a range on a string
char	*ft_substr(char const *s, unsigned int start, size_t len);

// scan the first `n` bytes of `s` for `c`
void	*ft_memchr(const void *s, int c, size_t n);

// compare the first `n` bytes of `s1` and `s2`
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// finds substring `little` in `big` doesnt search for 
// more than `len` characters in `big`
char	*ft_strnstr(const char *big, const char *little, size_t len);

// returns the string in `nptr`
int		ft_atoi(const char *nptr);

// allocates a buffer of size elements of nmemb
void	*ft_calloc(size_t nmemb, size_t size);

// duplicates string `s`
char	*ft_strdup(const char *s);
// joins two strings
char	*ft_strjoin(char const *s1, char const *s2);
// returns a copy of the `s1` with the characters from `set` removed 
char	*ft_strtrim(char const *s1, char const *set);
// splits a string at `c` and returns an arrayof strings temrinated with NULL
char	**ft_split(char const *s, char c);
// convert a number to a string representation
char	*ft_itoa(int n);

// maps every character in s to the result of `f` 
// and returns a copy of `s` with that
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// maps every character in `s` to the result of `f` 
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int c, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));

// printf
int		ft_printf(const char *pattern, ...);
// same as printf but takes an output file descriptor
int		ft_fprintf(int fd, const char *pattern, ...);
#endif
