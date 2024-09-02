# Simon Says Game in Arduino

## Introduction

**Simon Says** is a classic memory game that tests players' memory and reaction time. This Arduino-based version of the game features four push buttons, each associated with a different color LED. The game also includes a potentiometer to control the speed of the sequence display, an LCD screen to display the level and game status, and a speaker for audio feedback.

---

## Gameplay

The game starts by flashing a random sequence of LED lights. The player must repeat the sequence by pressing the corresponding buttons in the same order. With each correct sequence, the game adds one more step to the sequence. If the player repeats the sequence correctly, the level increases, and the new, extended sequence must be memorized and repeated.

If the player makes a mistake or takes too long to input the sequence, the game resets, plays a sound, and displays "GAME OVER" on the LCD screen. The player must then start over with a new random sequence.

---

## Parts of the Game

1. **LCD Monitor:**
   - Displays the current level, sequence, and game status (e.g., "GAME OVER", "YOU WIN").

2. **Potentiometer:**
   - Allows the player to adjust the difficulty by changing the duration of the LED flashes.

3. **LEDs:**
   - Four LEDs used to display the sequence for the player to memorize.

4. **Speaker:**
   - Provides audio feedback for correct/incorrect sequences and other game events.

5. **Push Buttons:**
   - Four push buttons serve as the primary input for the player to repeat the sequence.

6. **Arduino Uno:**
   - The microcontroller that controls the game logic, LED sequences, and interactions between all components.

---

## How to Play

1. **Start the Game:** 
   - Watch the sequence of LED flashes carefully.

2. **Repeat the Sequence:**
   - Press the buttons in the same order as the LEDs flashed.

3. **Advance to the Next Level:**
   - If you correctly repeat the sequence, the game will add another step, and you must repeat the new, longer sequence.

4. **Game Over:**
   - If you make a mistake or take too long, the game will display "GAME OVER" on the LCD, play a sound, and reset the sequence.

5. **Win the Game:**
   - Reach the final level, and the LEDs will flash together six times, followed by a "YOU WIN" message on the LCD screen. The game will then restart.

---

## How to End the Game

- The game ends when you either lose by making a mistake or win by completing all levels. Upon winning, the LEDs will flash six times, and "YOU WIN" will be displayed on the LCD before the game restarts.

---
