#pragma once

#include "core/reference.h"
#include "core/math/vector3.h"
#include <iostream>
#include <unordered_map>
#include "Planet.cpp"

using namespace std;

class GMan : public Reference {
	GDCLASS(GMan, Reference);

	int count;

protected:
	static void _bind_methods();

public:
	unordered_map<int, Planet> planets;

	Vector3 force_of(int id);
	Vector3 going();
	void add_planet(int id, int m, Vector3 location);
	void set_planet_location(int id, Vector3 location);
	Vector3 get_planet_location(int id);


	GMan();

};


