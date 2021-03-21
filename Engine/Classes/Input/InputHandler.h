#pragma once

#include "Types\CoreTypes.hpp"
#include <utility>

inline namespace MARS
{
	class Input
	{
	public:
		
		inline static bool IsKeyPressed(int32 Key) { return Instance->IsKeyPressed_Implementation(Key); }
		inline static bool IsMouseButtonPressed(int32 Button) { return Instance->IsMouseButtonPressed_Implementation(Button); }
		inline static std::pair<double, double> GetMousePos() { return Instance->GetMousePos_Implementation(); }
		inline static double GetMouseX() { return Instance->GetMouseX_Implementation(); }
		inline static double GetMouseY() { return Instance->GetMouseX_Implementation(); }

	protected:

		virtual bool IsMouseButtonPressed_Implementation(int32 Button) = 0;
		virtual bool IsKeyPressed_Implementation(int32 Key) = 0;
		virtual std::pair<double, double> GetMousePos_Implementation() = 0;
		virtual double GetMouseX_Implementation() = 0;
		virtual double GetMouseY_Implementation() = 0;

	private:

		static Input* Instance;
	};
}