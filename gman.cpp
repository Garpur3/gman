#include "gman.h"
#include "core/reference.h"
#include "core/math/vector3.h"
#include "Planet.cpp"

#include <iostream>
using namespace std;

Vector3 GMan::force_of(int id) {
	Vector3 force(0, 0, 0);
	double size,r_squared;
	double m1, m2;
	for (auto x : planets)if(x.first != id){
		m1 = planets[id].mass; m2 = x.second.mass;
		//m1 = 20; m2 = 20;
		r_squared = planets[id].location.distance_squared_to(x.second.location);
		force += (planets[id].location - x.second.location) * (m1*m2/r_squared);
	}
	return force;



	// Vector3 force = planets[id].velocity;
	// double m1 = planets[id].mass;
	// double m2, r_squared;
	// for (auto x : planets) {
	// 	if(x.first != id){
	// 		m2 = x.second.mass;
			
	// 		r_squared = planets[id].location.distance_squared_to(x.second.location);
	// 		force += (planets[id].location - x.second.location) * (m2/r_squared);
	// 	}
	// }
	// force *= 0.8;
	// planets[id].velocity = force;
	// return force;
}

Vector3 GMan::going() {
	return Vector3(1, 69, 3);
}

void GMan::add_planet(int id, double mass, Vector3 location){
	planets[id] = Planet(mass, location);
	
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




void GMan::_bind_methods() {
	ClassDB::bind_method(D_METHOD("force_of", "id"), &GMan::force_of);
	ClassDB::bind_method(D_METHOD("going"), &GMan::going);
	ClassDB::bind_method(D_METHOD("add_planet", "id", "m", "location"), &GMan::add_planet);
	ClassDB::bind_method(D_METHOD("set_planet_location", "id", "location"), &GMan::set_planet_location);
	ClassDB::bind_method(D_METHOD("get_planet_location", "id"), &GMan::get_planet_location);
	ClassDB::bind_method(D_METHOD("get_planet_mass", "id"), &GMan::get_planet_mass);
}	


GMan::GMan() {
}
