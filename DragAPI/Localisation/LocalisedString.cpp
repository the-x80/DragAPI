#include "LocalisedString.h"

DragAPI::Localisation::LocalisedString::LocalisedString() :
	languages(),
	strings()
{
}

DragAPI::Localisation::LocalisedString::LocalisedString(LocalisedString& other) :
	languages(other.languages),
	strings(other.strings)
{
}

DragAPI::Localisation::LocalisedString::LocalisedString(LocalisedString&& other) noexcept
{
}

DragAPI::Localisation::LocalisedString::~LocalisedString()
{
}
