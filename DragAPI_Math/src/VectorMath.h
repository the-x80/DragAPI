#pragma once
#include <DragAPI_Core.h>


namespace DragAPI::Math {
	float VectorMagnitude(Vector2f& vec);
	float VectorMagnitude(Vector2d& vec);
	float VectorMagnitude(Vector3f& vec);
	float VectorMagnitude(Vector3d& vec);
	float VectorMagnitude(Vector4f& vec);
	float VectorMagnitude(Vector4d& vec);
}