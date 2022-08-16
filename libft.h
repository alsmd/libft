/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:03:57 by flavio            #+#    #+#             */
/*   Updated: 2021/08/09 09:20:09 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <ctype.h>
/*-------List-------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
	@param (content)	The content to create the new element with.
	@brief				Allocates(malloc) and returns a new element.
						The t_list's content will come from the parameter,
						and it will have 'next' pointing to null.
	@return				The new element.
*/
t_list	*ft_lstnew(void *content);

/*
	@param (lst)	The address of a pointer to the first link ofa list.
	@param (new)	The address of a pointer to the element to be added to the list.
	@brief			Adds the element ’new’ at the beginning of the list.
	@return			noen.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*
	@param (lst)	The beginning of the list
	@brief			Counts the number of elements in a list.
	@return			Length of the list.
*/
int		ft_lstsize(t_list *lst);

/*
	@param (lst)	The beginning of the list
	@brief			Returns the last element of the list.
	@return			Last element of the list..
*/
t_list	*ft_lstlast(t_list *lst);

/*
	@param (lst)	The beginning of the list
	@param (new)	The address of a pointer to the element to be added to the list.
	@brief			Adds the element ’new’ at the end of the list..
	@return			none.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*
	@param (lst)	The element to free.
	@param (del)	The address of the function used to delete the content.
	@brief			Delete de element's content with 'del' and free the element
					The memory of 'next' must not be freed.
	@return			none.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*
	@param (lst)	The adress of a pointer to an element.
	@param (del)	The address of the function used to delete the content.
	@brief			Deletes and frees the given element and every successor of
					that element, using the function ’del’and free(3).Finally,
					the pointer to the list must be set toNULL.
	@return			none.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*));

/*
	@param (lst)	The beginning of the list.
	@param (f)		The adress of the function used to iterate on the list.
	@brief			Iterates the list ’lst’ and applies the function’f’
					to the content of each element.
	@return			none.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
	@param (lst)	The beginning of the list.
	@param (f)		The adress of the function used to iterate on the list
	@param (del)	The adress of the function used to delete the content of
					an element if needed.
	@brief			Iterates the list ’lst’ and applies the function’f’ to the
					content of each element.  Creates a new list resulting of the
					successive applications ofthe function ’f’.  The ’del’ function
					is used to delete the content of an element if needed.
	@return			The new list.  NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*-------TYPES-------*/

/*
	@param (c)		Char that will be tested.
	@brief			Checks if c is an alphabedic character on ascii table.
	@return			Return 1 if c is alpha or 0 otherwise.
*/
int		ft_isalpha(int c);

/*
	@param (c)		Char that will be tested.
	@brief			Checks if c is a digit character on ascci table.
	@return			Return 1 if c is a digit or 0 otherwise.
*/
int		ft_isdigit(int c);

/*
	@param (c)		Char that will be tested.
	@brief			Checks if c is a alphanumeric character on ascci table.
	@return			Return 1 if c is an alphanumeric or 0 otherwise.
*/
int		ft_isalnum(int c);

/*
	@param (c)		Char that will be tested.
	@brief			Checks if c is a character on ascci table.
	@return			Return 1 if c is into ascii or 0 otherwise.
*/
int		ft_isascii(int c);

/*
	@param (c)		Char that will be tested.
	@brief			Checks for any printable character including space.
	@return			Return 1 if c is printable or 0 otherwise.
*/
int		ft_isprint(int c);

/*
	@param (c)		Char that will be converted.
	@brief			Convert lowercase letters to uppercase.
	@return			The value returned is the converted letter, or c if the
					conversion failed.
*/
int		ft_toupper(int c);

/*
	@param (c)		Char that will be converted.
	@brief			Convert uppercase letters to lowercase.
	@return			The value returned is the converted letter, or c
					if the conversion failed.
*/
int		ft_tolower(int c);

/*-------BYTES-------*/
/*
	@param (s)		Pointer to the memory area.
	@param (c)		Byte that will be alocated.
	@param (n)		Quantity of bytes that will be filled.
	@brief			Fills the first n bytes fo the memory area pointed to by s
					with the byte c.
	@return			Returns a pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n);

/*
	@param (s)		Pointer to the memory area.
	@param (n)		Quantity of bytes that will be erased.
	@brief			Erases the data in the n bytes of the memory stating at the
					location pointed to by s, by writing zeroes.
	@return			Returns a pointer to the memory area s.
*/
void	ft_bzero(void *s, size_t n);

/*
	@param (dest)	Where the bytes will be saved.
	@param (src)	Where the bytes come from.
	@param (n)		Quantity of bytes that will be copied.
	@brief			Copies the data in the n bytes of the memory from src to
					memory area dest, the memory areas must not overlap.
	@return			Returns a pointer to the memory area dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*
	@param (dest)	Where the bytes will be saved.
	@param (src)	Where the bytes come from.
	@param (n)		Quantity of bytes that will be copied.
	@brief			Copies the data in the n bytes of the memory from src to
					Memory area dest, the memory areas may overlap.
	@return			Returns a pointer to the memory area dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
	@param (s)		Memory area where we will be searching.
	@param (c)		Byte that we are looking for.
	@param (n)		Quantity of bytes that will be scanned.
	@brief			Scans the initial n bytes of the memory area pointed to
					by s for the first instance of c.
					Both c and the bytes of the area s are interpreted as
					unsigned char.
	@return			Returns a pointer to the match byte or null if the
					char was not found.
*/
void	*ft_memchr(void *s, int c, size_t n);

/*
	@param (s1)		First memory area that will be compared.
	@param (s2)		Second memory area that will be compared.
	@param (n)		Quantity of bytes that will be compared.
	@brief			Compares the initial n bytes of the memory areas s1 and s2.
					Both interpreted as unsigned char.
	@return			Returns a value less than, equal to, or greater
					than zero depending on the difference of s1 and s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
	@param (nmemb)	Number of elements;
	@param (size)	Size of each element;
	@brief			Allocates memory for an array of nmemb elements of size
					bytes each and returns a pointer to the allocated memory.
					The memory is set to zero. If nmemb or size is 0, then
					calloc() return either null, or a unique pointer,
					value that can be later be passed to free().
					Both interpreted as unsigned char.
	@return			Returns a pointer to the allocated memory,
					on error return null, null may also be returned if
					size or nmemb is zero.
*/
void	*ft_calloc(size_t nmemb, size_t size);

/*-------STRINGS-------*/

/*
	@param (s)		String that will be cheacked.
	@brief			Calculates the length of the string pointed to by s.
	@return			Returns the number of characters in the string.
*/
size_t	ft_strlen(const char *s);

/*
	@param (dst)	Where the content will be saved.
	@param (src)	Where the content will come from.
	@param (size)	How many characters of src will be copied to
					dst(including NULL).
	@brief			Copies up to size - 1 characters from the
					NULL-terminated string src,
					to dst, Null terminating the result.
	@return			Length of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*
	@param (dst)	Where the content will be concatened.
	@param (src)	Where the content will come from.
	@param (size)	How many characters of src will be concatened to 
					dst(including NULL).
	@brief			Appends the NULL-terminated string src to the end of dst,
					it will append at most size - ft_strlen(dst) - 1 byte,
					Nul-terminating the result
	@return			The initial length of dst plus the length of src.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t n);

/*
	@param (s)		String that will be scanned.
	@param (c)		Character that we are looking for.
	@brief			Search for the first occurrence of the character
					c in the string s.
	@return			Returns a pointer to the matched character,
					or nUll if the character is not found.
*/
char	*ft_strchr(const char *s, int c);

/*
	@param (s)		String that will be scanned.
	@param (c)		Character that we are looking for.
	@brief			Search for the last occurrence of the character
					c in the string s.
	@return			Returns a pointer to the matched character,
					or nUll if the character is not found.
*/
char	*ft_strrchr(const char *s, int c);

/*
	@param (s1)		First string to be compared.
	@param (s2)		Second string to be compared.
	@param (size)	The max number of bytes to be compared.
	@brief			Compares two strings s1 and s2,
	@return			Returns the diferrence of s1 and s2,
					or 0 if they are equal.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
	@param (big)	Scanned string.
	@param (little)	Substring that is been searched.
	@param (len)	The max number of characters searched.
	@brief			Locates the first occurence of little in big, 
					where not more than len characters are searched.
	@return			If little is empty, big is returned.
					if little occurs nowehre in bi, Null is returned.
					otherwise a pointer to the first occurence of little
					is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*
	@param (nptr)	Scanned string.
	@brief			Converts the initial portion of nptr to int, 
	@return			The converted value.
*/
int		ft_atoi(const char *nptr);

/*
	@param (s)		String to be copied.
	@brief			Duplicate the string s using malloc.
	@return			Returns a pointer to the new string or 0 if the
					allocation fails.
*/
char	*ft_strdup(const char *s);

/*
	@param (s)		The string which to create the substring.
	@param (start)	The index where the substring begin in s.
	@param (len)	Quantity of characters take from s begining on index start.
	@brief			Create a substring using malloc based on the null-
					termineted  string s on index start, taking at most 
					(len) bytes.
	@return			Returns a pointer to the new string or 0 if the allocation 
					fails.
	@errors			1- if start is higher than ft_strlen(s) a empty string
					created with malloc is returned.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
	@param (s1)		The prefix string.
	@param (s2)		The sufix string.
	@brief			Create a new string(with malloc) that is the result of
					the concatenations of s1 and s2.
	@return			The created string, or null if the allocations fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
	@param (s1)		The string to be trimmed.
	@param (set)	The reference set of characters to trim.
	@brief			Create a copy(with malloc) of s1 without
					the set of characters in the beginning and
					the end of the string.
	@return			The trimed string or null if the alocation fails.
					returns an empty string(malloc) if s1 is an empty string,
					or if all the characters in s1 is into set.
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
	@param (s)		The string to be split.
	@param (c)		The delimiter character.
	@brief			Create an array of strings (malloc) obtained by,
					splitting s using c as delimiter, array must be null
					pointer termineted
	@return			The array of new strings resulting from the split. NULL if 
					the allocation fails.
*/
char	**ft_split(char const *s, char c);

/*
	@param (n)		The integer to be converted.
	@brief			Create an string representing the integer 'n'.
					Negative numbers must be handled.
	@return			The string represeting the integer.
					Null if the allocations fails.
*/
char	*ft_itoa(int n);

/*
	@param (s)		The string on which to iterate.
	@param (f)		The function to apply to each  character.
	@brief			Applies the functions 'f' to each character of the string s
					to create  a new string(malloc) resulting of successive
					applications of 'f'
	@return			The created string Or Null if allocations fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
	@param (s)		The string on which to iterate.
	@param (f)		The ifunctions to apply to each character.
	@brief			Applies the function f to each character of the
					string passed as argument, and passing its index
					as first argument. Each character is passed by
					address to f to be modified if necessary
	@return			None.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
	@param (n)		The character to output.
	@param (n)		The file descriptor on which to write.	
	@brief			Outputs the character ’c’ to the given file descriptor.
	@return			None.
*/
void	ft_putchar_fd(char c, int fd);

/*
	@param (s)		The string to output.
	@param (fd)		The file descriptor on which to write.	
	@brief			Outputs the string ’s’ to the given file descriptor.
	@return			None.
*/
void	ft_putstr_fd(char *s, int fd);

/*
	@param (s)		The string to output.
	@param (fd)		The file descriptor on which to write.	
	@brief			Outputs the string ’s’ to the given file descriptor.
					Followed by a new line.
	@return			None.
*/
void	ft_putendl_fd(char *s, int fd);

/*
	@param (n)		The integer to output.
	@param (fd)		The file descriptor on which to write.	
	@brief			Outputs the integer ’n’ to the given file descriptor.
	@return			None.
*/
void	ft_putnbr_fd(int n, int fd);
#endif