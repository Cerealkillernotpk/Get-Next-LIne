/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:16:03 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/11 19:14:49 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main()
{
    int fd;
    // size_t BUFFER_SIZE = 100;
    char str[BUFFER_SIZE];
    
    // str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    fd = open("Text.txt", O_RDWR);
    read(fd, str, BUFFER_SIZE);
    printf("%s", str);
}