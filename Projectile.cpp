#include "Projectile.h"
#include <raylib.h>
#include <raymath.h>
#include <cmath>
using namespace std;

// Empty constructor
Projectile::Projectile() {}

// Create a new projectile to move in the direction the player is aiming at
Projectile::Projectile(Vector2 playerPosition, float playerRotation) : position(playerPosition) {
	// Get the direction of both x and y components based on the player's rotation
	direction = { cos(playerRotation), sin(playerRotation) };
}

void Projectile::Update() {
	// If the object is not active, we ignore it
	if (not active) return;

	// Update the position of the object based on the direction and speed
	position.x += direction.x * PROJECTILE_SPEED * GetFrameTime();
	position.y += direction.y * PROJECTILE_SPEED * GetFrameTime();
}

void Projectile::Draw() {
	// If the object is not active, we ignore it
	if (not active) return;

	// Draw the object
	DrawCircle(position.x, position.y, PROJECTILE_SIZE, PROJECTILE_COLOR);
}
