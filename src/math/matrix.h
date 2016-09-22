/*********************************************************************
 *           Copyright (C) 2016 mwl4 - All rights reserved           *
 *********************************************************************
 * File       : matrix.h
 * Project    : ConverterPIX
 * Developers : Michal Wojtowicz (mwl450@gmail.com)
 			  : Piotr Krupa (piotrkrupa06@gmail.com)
 *********************************************************************/

#pragma once

#include <prerequisites.h>

#pragma pack(push, 1)

namespace prism
{
	template < typename T, size_t N >
	class mat_sq_t
	{
	public:
		T m[N][N];
	public:
		mat_sq_t()
		{
			loadIdentity();
		}
		mat_sq_t(const glm::mat4 &rhs)
		{
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < N; ++j)
				{
					m[i][j] = rhs[j][i];
				}
			}
		}
		void loadIdentity()
		{
			m[0][0] = 1.f; m[1][0] = 0.f; m[2][0] = 0.f; m[3][0] = 0.f;
			m[0][1] = 0.f; m[1][1] = 1.f; m[2][1] = 0.f; m[3][1] = 0.f;
			m[0][2] = 0.f; m[1][2] = 0.f; m[2][2] = 1.f; m[3][2] = 0.f;
			m[0][3] = 0.f; m[1][3] = 0.f; m[2][3] = 0.f; m[3][3] = 1.f;
		}
		T *operator[](size_t idx)
		{
			return m[idx];
		}
		const T *operator[](size_t idx) const
		{
			return m[idx];
		}
		std::string toString() const
		{
			std::string result = " ";
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < N; ++j)
				{
					result += ((i == 0 && j == 0) ? "" : "  ") + fmt::sprintf(FLT_FT, flh(m[j][i]));
				}
			}
			return result + " ";
		}
	};	ENSURE_SIZE(mat_sq_t<float COMMA 4>, 64);

	typedef mat_sq_t<float, 2> mat2;
	typedef mat_sq_t<float, 3> mat3;
	typedef mat_sq_t<float, 4> mat4;

	static glm::mat4 glm_cast(const mat4 &m)
	{
		return glm::mat4(
			m[0][0], m[1][0], m[2][0], m[3][0],
			m[0][1], m[1][1], m[2][1], m[3][1],
			m[0][2], m[1][2], m[2][2], m[3][2],
			m[0][3], m[1][3], m[2][3], m[3][3]
		);
	}
} // namespace prism

typedef prism::mat2 Float2x2;
typedef prism::mat3 Float3x3;
typedef prism::mat4 Float4x4;

#pragma pack(pop)

/* eof */
