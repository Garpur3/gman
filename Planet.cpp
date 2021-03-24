#pragma once
#include "core/reference.h"
#include "core/math/vector3.h"
class Planet{
	public:
		Vector3 location;
		double mass;
		Planet(){}
		Planet(const Planet& other){
			this->location = other.location;
			this->mass = other.mass;
		}
		Planet& operator=(Planet other){
			this->location = other.location;
			this->mass = other.mass;
        	return *this;
		}
		Planet(int x, Vector3 location){
			this->location = location;
			this->mass = mass;
		}
};