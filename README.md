# Aircraft-Flight-Simulation-using-C-Airbus-A350-Master
## This C code simulates the flight of an Airbus A350 aircraft using a simplified physics-based model.

- The `Aircraft` struct defines the aircraft's physical characteristics: mass, thrust, drag coefficient, and wing area.

- The `calculate_drag` function computes aerodynamic drag based on velocity and air density.

- The `simulate_flight` function:
  - Starts at an initial altitude and updates velocity, position, and altitude at each time step.
  - Uses a basic exponential model to adjust air density with altitude.
  - Calculates net force considering thrust, drag, and gravity, then updates the aircraft's motion accordingly.
 
- The `main` function initializes an Airbus A350 object and runs the simulation for 1 hour (3600 seconds).

> 🔍 It’s a simplified simulation, not a full dynamics model, but great for understanding core flight physics in code form.
