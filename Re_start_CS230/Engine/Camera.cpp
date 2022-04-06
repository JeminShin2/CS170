

#include "Camera.h"

CS230::Camera::Camera(math::rect2 movableRange)
	:movableRange(movableRange){}

void CS230::Camera::SetPosition(math::vec2 newPosition)
{
	math::vec2 position = newPosition;
}

void CS230::Camera::SetExtent(math::irect2 newExtent)
{
	math::irect2 extent = newExtent;
}

void CS230::Camera::Update(const math::vec2& followObjPos)
{
	
}

const math::vec2& CS230::Camera::GetPosition() const
{
	return  position;
}
