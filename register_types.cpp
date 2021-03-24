#include "register_types.h"

#include "core/class_db.h"

#include "gman.h"
#include "Planet.cpp"

void register_gman_types() {
    ClassDB::register_class<GMan>();
}

void unregister_gman_types() {
   // Nothing to do here in this example.
}
