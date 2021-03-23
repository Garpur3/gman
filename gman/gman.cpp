#include "gman.h"

Vector3 GMan::boing() {
	count++;
	return Vector3(3, 2, 1);
}

Vector3 GMan::going() {
	return Vector3(1, 2, 3);
}

void GMan::_bind_methods() {
	ClassDB::bind_method(D_METHOD("boing"), &GMan::boing);
	ClassDB::bind_method(D_METHOD("going"), &GMan::going);
}	

GMan::GMan() {
	count = 0;
}
