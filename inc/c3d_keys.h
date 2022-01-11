/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:46:51 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 19:58:09 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_KEYS_H
# define C3D_KEYS_H

# ifdef __linux__

#  define C3D_KEY_ESC 65307
#  define C3D_KEY_TAB 64289
#  define C3D_KEY_SPC 32
#  define C3D_KEY_ENTER 65293
#  define C3D_KEY_BCKSPC 65288
#  define C3D_KEY_LSHIFT 65505
#  define C3D_KEY_LCTRL 65507
#  define C3D_KEY_LOPT_ALT 65513
#  define C3D_KEY_RSHIFT 65506
#  define C3D_KEY_RCTRL 65508
#  define C3D_KEY_ROPT_ALT 65514
#  define C3D_KEY_1 49
#  define C3D_KEY_2 50
#  define C3D_KEY_3 51
#  define C3D_KEY_4 52
#  define C3D_KEY_5 53
#  define C3D_KEY_6 54
#  define C3D_KEY_7 55
#  define C3D_KEY_8 56
#  define C3D_KEY_9 57
#  define C3D_KEY_0 48
#  define C3D_KEY_MINUS 45
#  define C3D_KEY_EQ 61
#  define C3D_KEY_Q 113
#  define C3D_KEY_W 119
#  define C3D_KEY_E 101
#  define C3D_KEY_R 114
#  define C3D_KEY_T 116
#  define C3D_KEY_Y 121
#  define C3D_KEY_U 117
#  define C3D_KEY_I 105
#  define C3D_KEY_O 111
#  define C3D_KEY_P 112
#  define C3D_KEY_A 97
#  define C3D_KEY_S 115
#  define C3D_KEY_D 100
#  define C3D_KEY_F 102
#  define C3D_KEY_G 103
#  define C3D_KEY_H 104
#  define C3D_KEY_J 106
#  define C3D_KEY_K 107
#  define C3D_KEY_L 108
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_
#  define C3D_KEY_

# else
#  ifdef __APPLE__

#   define C3D_KEY_ESC			53
#   define C3D_KEY_TAB			48
#   define C3D_KEY_SPC			49
#   define C3D_KEY_ENTER		36
#   define C3D_KEY_BCKSPC		51
#   define C3D_KEY_LSHIFT		257
#   define C3D_KEY_LCTRL		256
#   define C3D_KEY_LOPT_ALT		261
#   define C3D_KEY_RSHIFT		258
#   define C3D_KEY_RCTRL		269
#   define C3D_KEY_ROPT_ALT		262
#   define C3D_KEY_1			18
#   define C3D_KEY_2			19
#   define C3D_KEY_3			20
#   define C3D_KEY_4			21
#   define C3D_KEY_5			23
#   define C3D_KEY_6			22
#   define C3D_KEY_7			26
#   define C3D_KEY_8			28
#   define C3D_KEY_9			25
#   define C3D_KEY_0			29
#   define C3D_KEY_MINUS		27
#   define C3D_KEY_EQ			24
#   define C3D_KEY_Q			12
#   define C3D_KEY_W			13
#   define C3D_KEY_E			14
#   define C3D_KEY_R			15
#   define C3D_KEY_T			17
#   define C3D_KEY_Y			16
#   define C3D_KEY_U			32
#   define C3D_KEY_I			34
#   define C3D_KEY_O			31
#   define C3D_KEY_P			35
#   define C3D_KEY_A			0
#   define C3D_KEY_S			1
#   define C3D_KEY_D			2
#   define C3D_KEY_F			3
#   define C3D_KEY_G			5
#   define C3D_KEY_H			4
#   define C3D_KEY_J			38
#   define C3D_KEY_K			40
#   define C3D_KEY_L			37
#	define C3D_KEY_LEFT_ARROW	123
#	define C3D_KEY_RIGHT_ARROW	124

#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_
#   define C3D_KEY_

#  endif
# endif

#endif
