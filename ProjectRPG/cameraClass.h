#ifndef CAMERACLASS_H
#define CAMERACLASS_H

#include <allegro5/allegro5.h>

class Camera {
private:
	void Transform();

public:
	ALLEGRO_TRANSFORM camera;

	float cameraPosition[4] = { 0, 0, 1280, 720 };

	Camera();
	void CameraUpdate(float*, float, float, int, int);
	void CameraReset();
};

#endif // !CAMERACLASS_H


