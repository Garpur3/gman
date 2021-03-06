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
	double G = 10;

	Vector3 force_of_planet(int id);
	void add_planet(int id, double mass, Vector3 location, Vector3 velocity);
	Vector3 get_planet_location(int id);
	void set_planet_location(int id, Vector3 location);
	double get_planet_mass(int id);
	void set_planet_velocity(int id, Vector3 velocity);
	Vector3 get_planet_velocity(int id);

	Vector3 force_of_object(int id);
	void add_object(int id, double mass, Vector3 location, Vector3 velocity);
	Vector3 get_object_location(int id);
	void  set_object_location(int id, Vector3 location);
	Vector3 get_object_velocity(int id);
	void set_object_velocity(int id, Vector3 velocity);

	void update(double delta);

	void set_G(double G);

	GMan();

};


