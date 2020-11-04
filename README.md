# Libft 

This project aims to re-write basic C functions in standard C library

## Getting Started
```
git clone https://github.com/arkim42/libft.git
```

## Extra functions
| Name | Prototype and Description |
| ----- | ----------|
| ft_abs | `unsigned int		   ft_abs(int n)` <br> - gets absolute value of an integer |
| ft_max | `int			ft_max(int a, int b)` <br> - finds a bigger integer between two integers |
| ft_min | `int			ft_min(int a, int b)` <br> - return a smaller integer between two integers |
| ft_pow | `uint64_t	ft_pow(int n, unsigned int exp)` <br> - computes a power of an integer |
| ft_iswspace3 | `int			ft_iswspace3(char c)` <br> - checks if the character is space or `\t` or `\n` |
| ft_nbrlen | `int			ft_nbrlen(int n)` <br> - computes the length of an integer |
| ft_nbrlen_base | `int			ft_nbrlen_base(int n, unsigned int base)` <br> - computes the length of an integer in base `base` |
| ft_swap | `void		ft_swap(void *a, void *b, size_t n)` <br> - swaps two characters |
| ft_strswap | `void		ft_strswap(char **s1, char **s2)` <br> - swaps two strings |
| ft_puterror | `void		ft_puterror(char const *error_msg)` <br> - puts an error message |
| ft_isdigit_base | `int			ft_isdigit_base(char c, int base)` <br> - checks if the character is digit in base `base` |
| ft_strchr_idx | `int			ft_strchr_idx(const char *s, int c)` <br> - locates the first occurrence of a charcter in given the string |
| ft_itoa_base | `char		*ft_itoa_base(int n, unsigned int base)` <br> - transforms an integer to string in base `base` |
| ft_strtolower | `char		*ft_strtolower(char *str)` <br> - converts a string to a lower case string |
| ft_strtoupper | `char		*ft_strtoupper(char *str)` <br> - converts a string to a upper case string |
| ft_nputchar| `void		ft_nputchar(char c, int n)` <br> - puts a character `n` times |
| ft_nputchar_fd | `void		ft_nputchar_fd(char c, int n, int fd)` <br> - puts a character to the file descriptor |
| ft_iselem | `int			ft_iselem(char c, char *str)` <br> - checks if a character is an element of a string |
| ft_strappend | `char		*ft_strappend(char const *s1, char const *s2, int n1, int n2)` <br> - similar to `ft_strjoin` function but able to free memories of each string |
| ft_readfd | `int			ft_readfd(int fd, char **file)` <br> - reads from file descriptor |
