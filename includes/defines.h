/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:31:29 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 18:34:57 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*Error messages*/
# define ERR_ARG		"Not enough arguments"
# define ERR_ARG_PB		"Issue with an argument"
# define ERR_MALL		"Allocation issue"
# define ERR_PTH_IN		"Issue in one of the threads"
# define ERR_PTH_CREA	"Issue when creating threads"
# define ERR_PTH_JOIN	"Issue when joining threads"
# define ERR_MTX_INIT	"Issue when init mutex"
# define ERR_MTX_DTY	"Issue when destroing mutex"
# define ERR_MTX_LOCK	"Issue when destroing mutex"
# define ERR_MTX_UNLOCK	"Issue when destroing mutex"
/*Printf colors*/
# define NRM			"\x1B[0m"
# define RED			"\x1B[31m"
# define GRN			"\x1B[32m"
# define YEL			"\x1B[33m"
# define BLU			"\x1B[34m"
# define MAG			"\x1B[35m"
# define CYN			"\x1B[36m"
# define WHT			"\x1B[37m"

/*Bool*/
# define FALSE			0
# define TRUE			1
/*For mutex tab*/
# define IMPAIRE		0
# define PAIRE			1
# define LAST			2

#endif