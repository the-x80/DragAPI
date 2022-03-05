#pragma once
#ifndef DRAG_API_PHYSICS_ENGINE_H
#define DRAG_API_PHYSICS_ENGINE_H
#include <array>
#include <vector>
#include "../Data Types/Vectors.h"

namespace DragAPI {
	namespace Physics {
		
		class PhysicsBody {
		public:
			Vector<float, 3> velocity;
			Vector<float, 3> angularVelocity;

			PhysicsBody();
			PhysicsBody(PhysicsBody& other);
			PhysicsBody(PhysicsBody&& other);
			~PhysicsBody();


			void ApplyForce(Vector<float, 3> force);
			void ApplyTorque(Vector<float, 3> torque);
		};

		class Simulation {
		private:
			std::vector<PhysicsBody> bodies;
		public:
			Simulation();
			Simulation(Simulation& other);
			Simulation(Simulation&& other);
			~Simulation();


			void Simulate(float timestep);
		};

		class PhysicsEngine {
		private:
			std::vector<Simulation*> simulations;
		public:
			PhysicsEngine();
			PhysicsEngine(PhysicsEngine& other);
			PhysicsEngine(PhysicsEngine&& other);
			~PhysicsEngine();

			void Simulate(float timestep);
		};
	}
}


#endif