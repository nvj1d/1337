/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:33:31 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/23 00:35:54 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);

char	*get_full_line(char *src, int fd);
char	*ft_read_line(char *src);
char	*ft_get_remainder(char *src);

char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(char *s);
char	*ft_strchr1(char *src, int c);

#endif
