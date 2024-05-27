/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoury <egoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:39:50 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/25 03:05:39 by egoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# define MAX_UNSIGNED_INT 4294967295
# define INITIAL_SIZE 41
# define READ_SIZE 4096
// number: valid dict number (see numbers.dict)
// characters that the number maps to (see numbers.dict for example)
typedef struct s_pair
{
	unsigned int	number;
	char			*str;
	int				zeros;
}	t_pair;
/**
 * Input:	A pointer to a char sequence delimited by a newline
 * Returns:	The characters following the : , removing leading whitespace
*/
char			*extract_str(char *input);

/**
 * Input: 
 * A line from the dictionary
 * 
 * Returns:
 * If not valid, return -1.
 * If valid but not usuable, return 0.
 * If valid and initial value, return 1.
*/
int				valid_line(char *input);

/**
 * Input:
 * A line from the dictionary.
 * 
 * Returns:
 * The struct t_pair with the number and
 * string extracted from the line.
 * If the line is not valid, return 0.
 * If the line is not usuable, return t_pair with str = 0
 * 
 * Uses:
 * valid_line
*/
t_pair			*read_line(char *input);

/**
 * Input:
 * An array of t_pairs and the dictionary
 * 
 * Ouput:
 * A null pointer
 * 
 * Frees:
 * Every ans element, ans itself, and the dictionary characters
 * 
 * Writes:
 * Dict error\n
 * 
*/
t_pair			**dict_error(t_pair **ans, char *str);

/**
 * Input:
 * A pointer to an array
 * 
 * Returns:
 * The same arrray but with the new size
*/
void			reallocate(char **from, int cur_size, int new_size);

/**
 * Input:
 * The file characters
 * 
 * Returns
 * The number of lines
*/
int				get_count(char *str);

/**
 * Input:
 * The file characters, and index of those characters
 * The t_pair array and current index
 * 
 * If the line is valid, then add it to the array
*/
int				add_line_to_arr(char *str, int i, int *j, t_pair **ans);

/**
 * Input:
 * a t_pair array and an unsigned int
 * Output:
 * 0 if no element has a, otherwise 1
*/
int				contains_num(unsigned int n, int zeros, t_pair **ans);

/**
 * Input:
 * A string containing the file's contents
 * 
 * Output:
 * A t_pair array of the valid rows
 * 
 * Writes:
 * "Dict Error\n" if a line was not valid
*/
t_pair			**read_str(char *str);

/**
 * Input:
 * A char array for the file name
 * 
 * Returns:
 * A t_pair array, or 0 if a line was not valid
 * 
 * Uses:
 * read_line
 * malloc
 * 
 * Writes:
 * "Dict Error\n" if a line was not valid
 * "Dict Error\n" if the file does not exist
*/
t_pair			**read_file(char *file);

/**
 * Input:
 * A char array for the program input
 * 
 * Returns:
 * A pointer to a unsigned integer or NULL (0) if not valid
 * 
 * Writes:
 * "Error\n" if the unsigned integer is not valid
*/
unsigned int	*get_input_number(char *input);

/**
 * Input:
 * an unsigned integer
 * a t_pair array
 * 
 * Returns:
 * char array coressponding to the unsigned int
 * NULL (0) if the number does not exist in the array
 * Returning NULL should NOT happen as 
 * The dictionary will always have at least
 * the keys as in the reference dictionary
 * 
 * Writes:
 * "number did not exist in array" if error
*/
char			*get_str_from_number(unsigned int input, t_pair	**dict);

/**
 * Input:
 * An unsigned integer less than 1000
 * a t_pair array
 * 
 * Returns:
 * 0 if an error occurs 1 if successful
 * 
 * Writes:
 * The number
 * If the number is not less than 1000 write "too large number"
 * 
 * Uses: get_str_from_number()
*/
void			write_100_number(char *input, t_pair	**dict, int len);

/**
 * Input:
 * An unsigned integer
 * a t_pair array
 * 
 * Returns:
 * 0 if an error occurs 1 if successful
 * 
 * Writes:
 * The number
 * 
 * Uses:
 * write_100_number()
 * get_str_from_number()
 * example: (123)(456)(789):
 * write_100_number(123), get_str_from_number(1000000000), write_100...
*/
void			write_number(char *input, t_pair **dict, int len);

/**
 * Main function
 * Uses:
 * get_input_number to get the unsigned int
 * readfile to get the t_pair array
 * write_number to write the final answer
 * uses numbers.dict if a file is not provided
 * 
 * write_number should only be run if no errors occured.
 * 
*/

int				get_len(char *input);

int				check_for_end(char *input);

void			set_first_num(char **input);

void			set_first_str(char **input);

int				contains_num(unsigned int n, int zeros, t_pair **ans);
/**
 * Files:
 * main.c
 * - main function
 * 
 * write_number.c
 * - get_str_from_number
 * - write_100_number
 * - write_number
 * 
 * read_file.c
 * - valid_line
 * - read_line
 * - read_file
*/

#endif