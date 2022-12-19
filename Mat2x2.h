# pragma once


struct Mat2x2
{
	using value_type = float;

	union
	{
		struct
		{
			value_type _11, _12;
		};

		Float3 _11_12;
	};

	union
	{
		struct
		{
			value_type _21, _22;
		};

		Float3 _21_22;
	};

	Mat2x2() = default;

	Mat2x2(float m11, float m12,float m21, float m22) noexcept;

	[[nodiscard]]
	friend constexpr bool operator ==(const Mat2x2& lhs, const Mat2x2& rhs) noexcept
	{
		return (lhs._11 == rhs._11) && (lhs._12 == rhs._12)
			&& (lhs._21 == rhs._21) && (lhs._22 == rhs._22);
	}

	[[nodiscard]]
	friend constexpr bool operator !=(const Mat2x2& lhs, const Mat2x2& rhs) noexcept
	{
		return (lhs._11 != rhs._11) || (lhs._12 != rhs._12)
			|| (lhs._21 != rhs._21) || (lhs._22 != rhs._22);
	}

	[[nodiscard]]
	constexpr float determinant() const noexcept;

	[[nodiscard]]
	Mat2x2 inverse() const noexcept;

	[[nodiscard]]
	 Float2 transformPoint(Point pos) const;

	[[nodiscard]]
	 Float2 transformPoint(Float2 pos) const;

	[[nodiscard]]
	 Vec2 transformPoint(Vec2 pos) const;

	static void multiMatAndMat(Mat2x2& _dist, const Mat2x2& _src1, const Mat2x2& _src2);

	static Mat2x2 Identity() noexcept {
		return{ 1.0f, 0.0f,
				0.0f, 1.0f };
	}
};

