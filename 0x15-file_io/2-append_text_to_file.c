#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text to the end of a file
 *
 * @filename: name of the file
 * @text_content: a NULL terminated string to append 
 * at the end of the file
 *
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, checkw, l = 0;

	if (filename == 0)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[l] != 0)
			l++;

		checkw = write(fd, text_content, l);

		if (checkw == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
