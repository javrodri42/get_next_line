/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:52:57 by javrodri          #+#    #+#             */
/*   Updated: 2019/11/25 13:56:51 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
ssize_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2, ssize_t r_size);
char			*ft_substr(char const *s, unsigned int start, ssize_t len);

#endif
