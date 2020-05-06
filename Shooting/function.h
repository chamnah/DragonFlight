#pragma once

template<typename T1,typename T2>
static bool CollisionRect(T1 first,T2 second)
{
	if (first->GetPos().x + first->GetScale().right / 2 >= second->GetPos().x - second->GetScale().left / 2 && // first에 오른쪽 경계가 second의 왼쪽 경계보다 크거나 같고,
		first->GetPos().x - first->GetScale().left / 2 <= second->GetPos().x + second->GetScale().right / 2 && // first에 왼쪽 경계가 second의 오른쪽 경계보다 작거나 같고,
		first->GetPos().y + first->GetScale().bottom / 2 >= second->GetPos().y - second->GetScale().top / 2 && // first에 아래쪽 경계가 second의 위쪽 경계보다 크거나 같고,
		first->GetPos().y - first->GetScale().top / 2 <= second->GetPos().y + second->GetScale().bottom / 2    // first에 위쪽 경계가 second의 아래 경계보다 작거나 같고,
		)
	{
		return true;
	}
	else
		return false;
}

static const float DegreeToRadian(const float _fAngle)
{
	return float(_fAngle * PI) / 180.f;
}

template<typename T1, typename T2>
static const float OppAngle(T1 first, T2 second)
{
	return -(atan2f(second->GetPos().y - first->GetPos().y, second->GetPos().x - first->GetPos().x));
}

static const float OppAngle(Vec2 first, Vec2 second)
{
	return -(atan2f(second.y - first.y, second.x - first.x));
}

template<typename T1,typename T2>
static const float OppDistance(T1 first,T2 second)
{	
	return sqrtf(powf(second->GetPos().x - first->GetPos().x, 2.f) + powf(second->GetPos().y - first->GetPos().y, 2.f));
}

template<typename T1, typename T2>
static const bool AscendingSort(T1 first, T2 second)
{
	return (UINT)first->GetBelong() < (UINT)second->GetBelong();
}
