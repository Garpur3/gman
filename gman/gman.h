#ifndef GMAN_H
#define GMAN_H

#include "core/reference.h"
#include "core/math/vector3.h"
#include <iostream>

using namespace std;

class GMan : public Reference {
	GDCLASS(GMan, Reference);

	int count;

protected:
	static void _bind_methods();

public:
	Vector3 boing();
	Vector3 going();


	GMan();

};

#endif
