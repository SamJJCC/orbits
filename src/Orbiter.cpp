#include "Orbiter.h"
#include "bn_sprite_items_dot.h"

// Constructor
Orbiter::Orbiter(bn::fixed_point starting_location,
                 bn::fixed_point starting_velocity,
                 Center &center)
    : _sprite(bn::sprite_items::dot.create_sprite(starting_location)),
      _velocity(starting_velocity),
      _center(center)
{
}
static constexpr bn::fixed FORCE_SCALE = 10;
// Update the Orbiter position
void Orbiter::update()
{
    // A vector from the Orbiter to the Center
    bn::fixed_point delta = _center.position() - _sprite.position();

    // Scale the vector by the mass
    bn::fixed_point force = delta * _center.mass();
    force /= FORCE_SCALE;

    // Update velocity
    _velocity += force;

    // Update position
    _sprite.set_position(_sprite.position() + _velocity);
}