#pragma once
#ifndef DRAG_API_PHYSICS_ENGINE_H
#define DRAG_API_PHYSICS_ENGINE_H
#include <array>
#include <vector>

#include "../Exceptions/Exceptions.h"

#include "../Data Types/Vectors.h"
#include "../Data Types/Quaternion.h"

namespace DragAPI {
	namespace Physics {
		template <typename T, size_t D> class PhysicsBody;

		namespace Exceptions {
			namespace PhysicsBody {
				class TimestepNegativeValue : public DragAPI::Exceptions::Exception {

				};
			}
		}

		/// <summary>
		/// Base object for all colliders
		/// </summary>
		class Collider {
		private:
		protected:
		public:
			//PhysicsBody* physicsBody;


			Collider();
			Collider(Collider& other);
			Collider(Collider&& other);
			~Collider();
		};

		class BoxCollider : public Collider {
		public:
			Vector<float, 3> center;
			Vector<float, 3> extents;

		};
		class SphereCollider : public Collider {
		public:
			Vector<float, 3> center;
			float radius;
		};
		
		template <typename T, size_t D> class PhysicsBody {
		private:
			Vector<T, D> netForce;
		public:
			//Developer note: Position and rotation vectors will be replaced eventually with a Transform class
			Vector<T, D>* position;
			Vector<T, D>* eulerRotation;

			/// <summary>
			/// Describes the current linear velocity of the object
			/// </summary>
			Vector<T, D> velocity;

			/// <summary>
			/// Describes the current angular velocity of the object
			/// </summary>
			Vector<T, D> angularVelocity;

			Vector<T, 4> inertiaTensor;//Find out what the inertia tensor component count is.

			std::vector<Collider*> colliders;

			PhysicsBody(){}
			PhysicsBody(PhysicsBody& other) {}
			PhysicsBody(PhysicsBody&& other) {}
			~PhysicsBody() {}


			void ApplyForce(Vector<float, 3> force) {}
			void ApplyTorque(Vector<float, 3> torque) {}

			void SimulateForward(float timestep) {
				if (timestep < 0.0f) {
					throw DragAPI::Physics::Exceptions::PhysicsBody::TimestepNegativeValue();
				}
			}
			void SimulateBackward(float timestep) {}
		};

		template <typename T, size_t D> class Simulation {
		private:
			std::vector<PhysicsBody<T, D>*> bodies;
		public:
			Simulation() {}
			Simulation(Simulation& other) {}
			Simulation(Simulation&& other) {}
			~Simulation() {}


			void Simulate(float timestep) {}
		};

		template <typename T, size_t D> class PhysicsEngine {
		private:
			std::vector<Simulation<T, D>*> simulations;
		public:
			PhysicsEngine() {}
			PhysicsEngine(PhysicsEngine& other) {}
			PhysicsEngine(PhysicsEngine&& other) noexcept {}
			~PhysicsEngine() {}

			void SimulateAll(float timestep) {}

			Simulation<T, D>* CreateSimulation() {}
			void DeleteSimulation(Simulation<T, D>* s) {}
			void DeleteAllSimulations() {}
		};
	}
}


#endif