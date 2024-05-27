/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:29:17 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/26 22:17:25 by dchetela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define READ_SIZE 4096
/**
 * char empty:		empty character
 * char block:		obstacle character
 * char fill:		square fill character
 * int num_lines:	number of lines
 * int line_len:	the length of a line excluding the \n
*/
typedef struct s_chars
{
	char			empty;
	char			block;
	char			fill;
	unsigned int	num_lines;
	unsigned int	line_len;
}	t_chars;

/**
 * The main function takes argc, argv.
 * If there are no added arguments (argc = 1), pass 0 as the file array
 * If there are added arguments, pass the file array.
 * 
 * Uses:
 * write_ans_from_files()
 * 
*/

//int	main(int argc, char **argv);

/**
 * This function takes an array of file names and writes the answer
 * for each file. If there is more than 1 file, an extra line break must be added
 * after each file
 * If any of the functions returns null, write map error.
 * 
 * Input:
 * Number of files
 * 
 * Output:
 * Writes the answer for each file
 * 
 * Uses:
 * write_ans_from_file
*/
void	write_ans_from_files(char **files, int num_files);

/**
 * This function takes a file name and writes the answer.
 * If a function returns null, write an error.
 * If the file name is null, read from stdin
 * 
 * Input: file name
 * 
 * Returns: 0 if an error occurred
 * 
 * Uses
 * get_str_from_file()
 * get_char_types_from_str()
 * get_arr_from_str()
 * get_str_from_stdin()
 * 
 * Frees:
 * the string from the file
 * The char array
*/
int		write_ans_from_file(char *file);

/**
 * This function takes a file name and returns the file's contents in a string
 * and a struct with the empty, block, fill characters and number of lines
 * Input:
 * File name
 * 
 * Output:
 * Returns a character set ending with a null character,
 * or null if the file does not exist
 * 
 * 
 * Uses:
 * reallocate
 * malloc
 * open, close, read
*/
char	*get_str_from_file(char *file);

/**
 * This function reads from stdin and returns a string as a result
 * 
 * Returns a string
 * 
 * Uses:
 * reallocate
 * malloc
 * open, close, read
*/
char	*get_str_from_stdin(void);

/**
 * This function takes a string and reallocates it in a larger array
 * Input:
 * Array pointer, old size, new size
 * 
 * Ouput:
 * The same array but with new size allocated
 * 
 * Uses:
 * malloc
*/
void	reallocate(char **str, int old_size, int new_size);

/**
 * This function takes the file as a string and returns a 2D array,
 * where each 'row' is a string
 * 
 * Input:
 * the file as a string
 * the character types
 *
 * Output:
 * The array starting at the map, or null if the map violates a constraint
*/
char	*verify_file(char *str, t_chars *chars);

/**
 * This function takes the file as a string and returns a struct
 * filled with the character types
 * 
 * Input:
 * The file as a string
 * 
 * Output:
 * A struct with its respective values
 * or null if there is an error
 * ex: 0 lines, duplicate character, too many characters
*/
t_chars	*get_char_types_from_str(char *str, int i);

/**
 * This function takes an array of strings and writes the largest square
 * 
 * Input:
 * The string array
 * 
 * Output:
 * Writes the answer
 * 
 * Uses:
 * largest_square_at
 * write_square_at
*/
void	find_answer_from_arr(char *arr, t_chars *c_types);

/**
 * This function returns the largest possible square for the given coordinate
 * 
 * Input:
 * The string array
 * The x position and y position (used like arr[y][x])
 * The block character
 * 
 * Output:
 * Returns an int for the largest possible square
*/
int		largest_square_at(char *arr, int pos, t_chars *c_types);

/**
 * This function write the board with the largest
 * possible square at the given coordiante
 * 
 * Input:
 * The string array
 * The x position and y position (used like arr[y][x])
 * The fill character
 * 
 * Ouptupt:
 * Writes the largest board
*/
void	write_square_at(char *arr, int x, int y, t_chars *c_types);

#endif
