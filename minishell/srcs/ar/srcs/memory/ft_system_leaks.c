/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system_leaks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:01:42 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 16:48:20 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	leaks(void)
{
	system("leaks minishell");
}

// export MallocStackLogging=1 
// system("leaks --list -- [PROGRAM_NAME]");
// while true; do leaks minishell; sleep 3; done;