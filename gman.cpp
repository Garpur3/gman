#include "gman.h"
#include "core/reference.h"
#include "core/math/vector3.h"
#include "Planet.cpp"

#include <iostream>
using namespace std;

Vector3 GMan::force_of_planet(int id) {
	Vector3 force(0, 0, 0);
	double r_squared;
	double m1, m2;
	for (auto x : planets)if(x.first != id){
		m1 = planets[id].mass; m2 = x.second.mass;
		
		r_squared = planets[id].location.distance_squared_to(x.second.location);
		force += (-planets[id].location + x.second.location) * (m1*m2/r_squared);
	}
	return force;
}

void GMan::add_planet(int id, double mass, Vector3 location, Vector3 velocity){
	planets[id] = Planet(mass, location, velocity);
}

void  GMan::set_planet_location(int id, Vector3 location){
	planets[id].location = location;	
}

Vector3 GMan::get_planet_location(int id){
	return planets[id].location;
}

double GMan::get_planet_mass(int id) {
	return planets[id].mass;
}

void GMan::update(double delta){
	double r_squared;
	double m1, m2;
	for (auto a : planets)for (auto b : planets)if(a.first != b.first){
		m1 = planets[a.first].mass; m2 = planets[b.first].mass;
		r_squared = planets[a.first].location.distance_squared_to(planets[b.first].location);
		planets[a.first].velocity += G * delta * (-planets[a.first].location + planets[b.first].location) * (m2/r_squared);
	}

	for (auto a : planets){
		planets[a.first].location += planets[a.first].velocity;
	}
}



Vector3 GMan::force_of_object(int id) {
	Vector3 force(0, 0, 0);
	double r_squared;
	double m1, m2;
	for (auto x : planets){
		m1 = objects[id].mass; m2 = x.second.mass;
		r_squared = objects[id].location.distance_squared_to(x.second.location);
		force += (x.second.location - objects[id].location) * (m1*m2/r_squared);
	}
	return force;
}


void GMan::add_object(int id, double mass, Vector3 location){
	objects[id] = Planet(mass, location, Vector3(0,0,0));
}

void  GMan::set_object_location(int id, Vector3 location){
	objects[id].location = location;	
}

void GMan::set_G(double G){
	this->G = G;
}


void GMan::_bind_methods() {
	ClassDB::bind_method(D_METHOD("force_of_planet", "id"), &GMan::force_of_planet);
	ClassDB::bind_method(D_METHOD("add_planet", "id", "m", "location", "velocity"), &GMan::add_planet);
	ClassDB::bind_method(D_METHOD("set_planet_location", "id", "location"), &GMan::set_planet_location);
	ClassDB::bind_method(D_METHOD("get_planet_location", "id"), &GMan::get_planet_location);
	ClassDB::bind_method(D_METHOD("get_planet_mass", "id"), &GMan::get_planet_mass);

	ClassDB::bind_method(D_METHOD("force_of_object", "id"), &GMan::force_of_object);
	ClassDB::bind_method(D_METHOD("add_object", "id", "m", "location"), &GMan::add_object);
	ClassDB::bind_method(D_METHOD("set_object_location", "id", "location"), &GMan::set_object_location);
	
	ClassDB::bind_method(D_METHOD("set_G", "G"), &GMan::set_G);
	ClassDB::bind_method(D_METHOD("update", "delta"), &GMan::update);
}	


GMan::GMan() {
}
