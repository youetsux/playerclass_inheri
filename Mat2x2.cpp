#include "stdafx.h"
#include "Mat2x2.h"

Mat2x2::Mat2x2(
	float m11, float m12,
	float m21, float m22) noexcept
		: _11{ m11 }, _12{ m12 } 
		, _21{ m21 }, _22{ m22 }{}

inline constexpr float Mat2x2::determinant() const noexcept
{
	return (
		+(_11 * _22 )
		-(_12 * _21));
}

inline Mat2x2 Mat2x2::inverse() const noexcept
{
	const float invdet = (1.0f / determinant());

	Mat2x2 result;
	result._11 = (_22) * invdet;
	result._12 = (-_12) * invdet;
	result._21 = (-_21) * invdet;
	result._22 = (_11) * invdet;
	return result;
}

Float2 Mat2x2::transformPoint(Point pos) const 
{

	const float x = (_11 * pos.x + _21 * pos.y);
	const float y = (_12 * pos.x + _22 * pos.y);
	return{ x, y };
}

Float2 Mat2x2::transformPoint(Float2 pos) const 
{
	const float x = (_11 * pos.x + _21 * pos.y);
	const float y = (_12 * pos.x + _22 * pos.y);
	return{ x, y };
}

Vec2 Mat2x2::transformPoint(Vec2 pos) const
{
	const double x = (_11 * pos.x + _21 * pos.y);
	const double y = (_12 * pos.x + _22 * pos.y);
	return{ x, y };
}

void Mat2x2::multiMatAndMat(Mat2x2& _dist, const Mat2x2& _src1, const Mat2x2& _src2)
{
	_dist._11 = _src1._11 * _src2._11 + _src1._12 * _src2._21;
	_dist._12 = _src1._11 * _src2._12 + _src1._12 * _src2._22;
	_dist._21 = _src1._21 * _src2._11 + _src1._22 * _src2._21;
	_dist._22 = _src1._21 * _src2._12 + _src1._22 * _src2._22;

}

