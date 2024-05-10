#include "cameraClass.h"
#include <iostream>
using namespace std;
Camera::Camera() {

}

void Camera::CameraUpdate(float* cameraPosition, float x, float y, int width, int height) {
	cameraPosition[0] = -(1280 / 2) + (x + width / 2);
	cameraPosition[1] = -(720 / 2) + (y + height / 2);
	cameraPosition[2] = -(1280 / 2) + (x + width / 2) + 1280;
	cameraPosition[3] = -(720 / 2) + (y + height / 2) + 720;
	Transform();


}

void Camera::CameraReset() {
	cameraPosition[0] = 0;
	cameraPosition[1] = 0;
	cameraPosition[2] = 1280;
	cameraPosition[3] = 720;

	Transform();
}

void Camera::Transform() {
	al_identity_transform(&camera);
	al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
	al_use_transform(&camera);
	//cout << cameraPosition[0] << " " << cameraPosition[1] << " " << cameraPosition[2] << " " << cameraPosition[3] << endl;

}