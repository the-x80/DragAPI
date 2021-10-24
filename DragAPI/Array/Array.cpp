#include "Array.h"

DragAPI::Exceptions::ArrayEmptyException::ArrayEmptyException()
{
}

DragAPI::Exceptions::ArrayEmptyException::ArrayEmptyException(char* msg) : Exception(msg)
{
}
