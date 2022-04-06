
#include <doodle/drawing.hpp>
#include "Sprite.h"
#include <iostream>


using namespace std;

CS230::Sprite::Sprite()
{

}

void CS230::Sprite::Load(const std::filesystem::path& texturePath)
{
	texture.Load(texturePath);
	hotSpot = texture.GetSize() / 2;

}

void CS230::Sprite::Load(const std::filesystem::path& texturePath, math::ivec2 hotSpotPosition)
{
	texture.Load(texturePath);
	hotSpot = hotSpotPosition;


}

void CS230::Sprite::Draw(math::vec2 position)
{

	texture.Draw(position);
	position = hotSpot;
}

math::ivec2 CS230::Sprite::GetTextureSize()
{
	return texture.GetSize();
}