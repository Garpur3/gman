#pragma once
#include "core/reference.h"
#include "core/math/vector3.h"
class Planet{
	public:
		Vector3 location;
		Vector3 velocity;
		double mass;
		// int parent = -1;
		Planet(){}
		Planet(const Planet& other){
			this->velocity = other.velocity;
			this->location = other.location;
			this->mass = other.mass;
		}
		Planet& operator=(Planet other){
			this->velocity = other.velocity;
			this->location = other.location;
			this->mass = other.mass;
        	return *this;
		}
		Planet(double mass, Vector3 location, Vector3 velocity){
			this->velocity = velocity;
			this->location = location;
			this->mass = mass;
		}
		// set_parent(int parent_id) { this->parent_id = parent_id; }
};