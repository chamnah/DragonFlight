#pragma once
class CCameraMgr
{
	SINGLE(CCameraMgr)

private:
	Vec2  m_vLook;
	Vec2  m_vDiff;
	float m_fSpeed;

public:
	void update();
	const Vec2 GetRealPos(float _x, float _y) {	return Vec2(_x - m_vDiff.x, _y - m_vDiff.y);}
	void SetLook(float _x, float _y) { m_vLook.x = _x; m_vLook.y = _y; }
	void SetSpeed(float _speed) { m_fSpeed = _speed; }
	Vec2 GetDifference() { return m_vDiff; }
	float GetCameraSpeed() { return m_fSpeed; }
};