# `libft` -- Simple C Library
libft is a collection of helpful C functions mostly involving string and memory manipulation.\
A bonus section also includes list manipulation.
## Learning Outcomes
### Challenges faced
- This project was not challenging in terms of code. Most of the functions are simply review of content already covered in the Pisine.
- The most difficult portion was creating the Makefile which combines all the functions into a library
### Key Takeaways
- Using libraries can cut down significantly on coding time and avoiding simple mistakes. While most of these functions shouldn't be really used for a real project, using real libraries allows one to avoid reinventing the wheel.
- Makefiles are a strong tool for quickly building a project. In addition to making it easier for you to test your project, as you don't have to retype the series of commmands each time, it makes it easier for others to build your project as intended.
### In Retrospect
- I should have spent more time adding functions to this project as suggested in the subject.
## Functions
| Function | Description |
|---|---|
| `int isalpha(int c)` | Checks if a character is alphabetic |
| `int isdigit(int c)` | Checks if a character is a digit |
| `int isalnum(int c)` | Checks if a character is alpha or digit |
| `int isascii(int c);` | Checks if a character is in the ASCII character set |
| `int isprint(int c);` | Checks if a character is printable (including space) |
| `size_t strlen(const char *s);` | Returns the length of a string excluding the terminating null byte |
| `void *memset(void *s, int c, size_t n);` | Fills the first `n` bytes pointed to by `s` with the constant byte `c` |
| `void bzero(void *s, size_t n);` | Fills the first `n` bytes pointed to by `s` with `\0` |
| `void *memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from memory area `src` to memory area `dest`. Does not handle overlap. |
| `void *memmove(void *dest, const void *src, size_t n);` | Copies `n` bytes from memory area `src` to memory area `dest`. Overlap is allowed. |
| `size_t strlcpy(char *dst, const char *src, size_t size);` | Copies the string `src` to `dst`, with at most `size-1` bytes. Guaranteed to null terminate the result as long as `size` is greater than zero. `src` must be null terminated |
| `size_t strlcat(char *dst, const char *src, size_t size);` | Appends the string `src` to `dst`, with at most `size-strlen(dst)-1` bytes. Guaranteed to null terminate if there is at least one byte free in `dst`. Both `src` and `dst` must be null terminated. |
| `int toupper(int c);` | Converts lowercase letter to uppercase |
| `int tolower(int c);` | Converts uppercase letter to lowercase |
| `char *strchr(const char *s, int c);` | Returns pointer to first occurrence of the char `c` in the string `s`. Otherwise returns null. |
| `char *strrchr(const char *s, int c);` | Returns pointer to last occurrence of the char `c` in the string `s`. Otherwise returns null. |
| `int strncmp(const char *s1, const char *s2, size_t n);` | Returns `0` if `s1` and `s2` are equal, a negative value if `s1` is less than `s2`, and a positive value if `s1` is greater than `s2`. Only compares the first (at most) `n` bytes. |
| `void *memchr(const void *s, int c, size_t n);` | Returns a pointer to the first occurrence of the byte `n` within `n` bytes. The bytes are interpreted as unsigned chars. |
| `int memcmp(const void *s1, const void *s2, size_t n);` | Returns an integer representing if the first `n` bytes are greater, less than, or equal (positive, negative or zero respectively). The bytes are interpreted as unsigned chars. |
| `char * strnstr(const char *big, const char *little, size_t len);` | Locates the first occurrence of the string `little` in the string `big`, where not more then `len` characters are searched. |
| `int atoi(const char *nptr);` | Converts the initial portion of the string pointed to by `nptr` to an integer. Returns 0 on error. |
| `void *calloc(size_t nmemb, size_t size);` | Allocates memory for an array of `nmemb` elements of `size` bytes each and returns a pointer to that memory. The memory is set to zero. |
| `void *strdup(const char *s);` | Returns a pointer to a new string which is a duplicate of `s` |
| `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring from the string `s`, beginning at index `start` and is of maximum size `len` |
| `char *ft_strjoin(char const *s1, char const *s2);` | Allocates and returns a new string, which is the concatenation of `s1` and `s2` |
| `char *ft_strtrim(char const *s1, char const *set);` | Allocates and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string. |
| `char **ft_split(char const *s, char c);` | Allocates and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must end with a NULL pointer |
| `char *ft_itoa(int n);` | Allocates and returns a string representing the integer received as an argument. |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies the function `f` to each character of `s`, passing its index as the first argument and the character as the second. A new string is created to collect the results from the successive applications of `f`. |
| `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Applies the function `f` on each character of `s`, passing its index as first argument. Each character is passed by address to `f` to be modified if necessary. |
| `void ft_putchar_fd(char c, int fd);` | Outputs the character `c` to the given file descriptor. |
| `void ft_putstr_fd(char *s, int fd);` | Outputs the string `s` to the given file descriptor |
| `void ft_putendl_fd(char *s, int fd);` | Outputs the string `s` to the given file descriptor followed by a newline |
| `void ft_putnbr_fd(int n, int fd);` | Outputs the integer `n` to the given file descriptor. |
| `typedef struct s_list {` <br>`   void *content;` <br>`   struct s_list *next;` <br>`}  t_list;` | Struct containing the members: `content`: Data contained in node `next`: The address of the next node or `NULL` |
| `t_list *ft_lstnew(void *content);` | Allocates and returns a new node with `content` initialized with the given parameter and `next` initialized to `NULL`. |
| `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node `new` at the beginning of `lst`. |
| `int ft_lstsize(t_list *lst);` | Counts the number of nodes in a list. |
| `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. |
| `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node `new` at the end of the list. |
| `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees the given node and its content with the `del` function, The memory of `next` is not be freed. |
| `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees the given node and every successor of that node, using the function `del` and free. The pointer to the list is set to `NULL` |
| `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates `lst` and applies the function `f` on the content of each node. |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates `lst` and applies `f` on the content of each node. Creates a new list resulting of the successive applications of `f`. The `del` function is used to delete the content of a node if needed. |
## Installation and Usage
### Building the library
To build the library, simply run
```
make
```
## License
This project is licensed under the MIT License. See the LICENSE file for details.
