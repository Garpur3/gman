#pragma once

#include "core/reference.h"
#include "core/math/vector3.h"
#include <iostream>
#include <unordered_map>
#include "Planet.cpp"

using namespace std;

class GMan : public Reference {
	GDCLASS(GMan, Reference);

protected:
	static void _bind_methods();

public:
	unordered_map<int, Planet> planets;
	unordered_map<int, Planet> objects;

	Vector3 force_of_planet(int id);
	void add_planet(int id, double mass, Vector3 location);
	void set_planet_location(int id, Vector3 location);
	Vector3 get_planet_location(int id);
	double get_planet_mass(int id);

	Vector3 force_of_object(int id);
	void add_object(int id, double mass, Vector3 location);
	void  set_object_location(int id, Vector3 location);
	GMan();

};


