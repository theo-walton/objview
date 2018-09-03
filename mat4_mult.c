/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:39:08 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:38:53 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

#define A00 a.array[0]
#define A01 a.array[1]
#define A02 a.array[2]
#define A03 a.array[3]
#define A10 a.array[4]
#define A11 a.array[5]
#define A12 a.array[6]
#define A13 a.array[7]
#define A20 a.array[8]
#define A21 a.array[9]
#define A22 a.array[10]
#define A23 a.array[11]
#define A30 a.array[12]
#define A31 a.array[13]
#define A32 a.array[14]
#define A33 a.array[15]

#define B00 b.array[0]
#define B01 b.array[1]
#define B02 b.array[2]
#define B03 b.array[3]
#define B10 b.array[4]
#define B11 b.array[5]
#define B12 b.array[6]
#define B13 b.array[7]
#define B20 b.array[8]
#define B21 b.array[9]
#define B22 b.array[10]
#define B23 b.array[11]
#define B30 b.array[12]
#define B31 b.array[13]
#define B32 b.array[14]
#define B33 b.array[15]

#define CAT2(X, Y) X ## Y
#define CAT3(X, Y, Z) X ## Y ## Z

#define MULT1(ROW, COL) CAT2(A0, ROW) * CAT3(B, COL, 0)
#define MULT2(ROW, COL) CAT2(A1, ROW) * CAT3(B, COL, 1)
#define MULT3(ROW, COL) CAT2(A2, ROW) * CAT3(B, COL, 2)
#define MULT4(ROW, COL) CAT2(A3, ROW) * CAT3(B, COL, 3)

#define MULT(X, Y) MULT1(X, Y) + MULT2(X, Y) + MULT3(X, Y) + MULT4(X, Y)

t_mat4	mat4_mult(t_mat4 a, t_mat4 b)
{
	return ((t_mat4){{
		MULT(0, 0), MULT(1, 0), MULT(2, 0), MULT(3, 0),
		MULT(0, 1), MULT(1, 1), MULT(2, 1), MULT(3, 1),
		MULT(0, 2), MULT(1, 2), MULT(2, 2), MULT(3, 2),
		MULT(0, 3), MULT(1, 3), MULT(2, 3), MULT(3, 3)}});
}
