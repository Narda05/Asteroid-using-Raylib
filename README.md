# Asteroid using Raylib
This project involves the implementation of the iconic video game "Asteroids" using the Raylib graphics library. The main objective was to recreate the classic gameplay of the original title while leveraging Raylib's simplicity and efficiency for graphics development and input handling.

## Authors

- [@Narda05](https://github.com/Narda05)

## 🚀Game play 
![Recording 2024-12-18 at 19 36 12](https://github.com/user-attachments/assets/6c58873f-eadd-433d-888d-d6d249cfe470)


## 🛸 Your Spaceship

Your ship is represented by a sleek purple triangle that responds to your every command:
- The ship automatically follows your mouse cursor
- Left-click to shoot projectiles at the asteroids
- You have 3 lives to start with
- Your ship can wrap around screen edges for quick escapes!


## ☄️ The Asteroids
The space rocks come in three dangerous varieties:

1. **Big Blue Rocks** (2 points)
   - Slow but menacing
   - Split into two medium rocks when destroyed
   - Size: 50 units
   - Speed: 250 units/second

2. **Medium Orange Rocks** (4 points)
   - Faster and more challenging
   - Split into two small rocks when hit
   - Size: 30 units
   - Speed: 330 units/second

3. **Small Pink Rocks** (8 points)
   - The fastest and most valuable
   - Completely destroyed when hit
   - Size: 20 units
   - Speed: 400 units/second
## 🎯 How it All Works

### The Game Loop
1. **Starting Up**
   ```cpp
   void Asteroids::Main() {
       SetRandomSeed(time(0));  // Each game is unique!
       InitWindow(1215, 900, "Asteroids");
       SetTargetFPS(60);  // Smooth gameplay
   ```

2. **During Gameplay**
   - Your ship constantly tracks the mouse position
   - Rocks move in random directions
   - Everything wraps around the screen edges
   - Collisions are checked every frame
   - Score updates in real-time

3. **Scoring System**
   - Bigger rocks split into smaller ones
   - Smaller rocks = more points
   - High scores are saved permanently
   - Top 5 scores displayed on game over
## 🎨 Visual Design 
- Clean, minimalist graphics
- Distinct colors for different rock sizes
- Clear visual feedback for lives and score
- Dedicated play area with boundaries
## 🔧 Behind the Scenes

### Smart Design Choices
1. **Entity System**
   - Everything in the game (rocks, bullets, player) shares common base code
   - Makes adding new features super easy
   - Keeps the code clean and organized

2. **Collision Detection**
   ```cpp
   // Simple but effective circle collision
   float distance = sqrt(dx * dx + dy * dy);
   return distance <= (radius1 + radius2);
   ```

3. **Screen Wrapping**
   ```cpp
   // When something goes off-screen...
   if (position.x > PLAY_AREA_RIGHT_LIMIT)
       position.x = PLAY_AREA_LEFT_LIMIT;
   ```
##  🏆 Score Tracking

- Scores saved to a file
- Automatically sorted
- Persists between game sessions
- Shows player name and score
## 🚀 Quick Start

1. **Launch the Game**
   - Press ENTER to start
   - Move your mouse to control the ship
   - Left-click to shoot

2. **Stay Alive!**
   - Avoid colliding with rocks
   - Shoot rocks for points
   - Bigger rocks split into smaller ones
   - Watch your remaining lives

3. **Game Over**
   - Your score is saved if it's high enough
   - View the top 5 scores
   - Press ENTER to play again

## 🎯 Pro Tips

1. **Survival Strategies**
   - Use screen wrapping to your advantage
   - Target smaller rocks for more points
   - Keep moving to avoid getting cornered
   - Watch out for rock splits!

2. **Score Maximizing**
   - Focus on small rocks (8 points each!)
   - Create chains by splitting big rocks
   - Stay alive longer for more opportunities
   - Practice your aim for efficiency

##  🛠️ Technical Requirements

- Screen Resolution: 1215x900
- Controls: Mouse + Left Click
- Storage: Small file for high scores
- Performance: Runs smoothly at 60 FPS
