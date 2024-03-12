/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:15:08 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/12 09:25:17 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_global1(char **sprites)
{
	sprites[0] = SPRITE_1;
	sprites[1] = SPRITE_2;
	sprites[2] = SPRITE_3;
	sprites[3] = SPRITE_4;
	sprites[4] = SPRITE_5;
	sprites[5] = SPRITE_6;
	sprites[6] = SPRITE_7;
	sprites[7] = SPRITE_8;
	sprites[8] = SPRITE_9;
	sprites[9] = SPRITE_10;
	sprites[10] = SPRITE_11;
	sprites[11] = SPRITE_12;
	sprites[12] = SPRITE_13;
	sprites[13] = SPRITE_14;
	sprites[14] = SPRITE_15;
	sprites[15] = SPRITE_16;
	sprites[16] = SPRITE_17;
	sprites[17] = SPRITE_18;
	sprites[18] = SPRITE_19;
	sprites[19] = SPRITE_20;
	sprites[20] = SPRITE_21;
	sprites[21] = SPRITE_22;
	sprites[22] = SPRITE_23;
	sprites[23] = SPRITE_24;
	sprites[24] = SPRITE_25;
}

void	init_global2(char **sprites)
{
	sprites[25] = SPRITE_26;
	sprites[26] = SPRITE_27;
	sprites[27] = SPRITE_28;
	sprites[28] = SPRITE_29;
	sprites[29] = SPRITE_30;
	sprites[30] = SPRITE_31;
	sprites[31] = SPRITE_32;
	sprites[32] = SPRITE_33;
	sprites[33] = SPRITE_34;
	sprites[34] = SPRITE_35;
	sprites[35] = SPRITE_36;
	sprites[36] = SPRITE_37;
	sprites[37] = SPRITE_38;
	sprites[38] = SPRITE_39;
	sprites[39] = SPRITE_40;
	sprites[40] = SPRITE_41;
	sprites[41] = SPRITE_42;
}

char	*get_path(int n)
{
	static char	*sprites[MAX_SPRITES];

	if (!*sprites)
	{
		init_global1(sprites);
		init_global2(sprites);
	}
	if (n < MAX_SPRITES && n >= 0)
		return (sprites[n]);
	else
		return (NULL);
}
