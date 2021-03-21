#pragma once

#include "CoreMinimal.h"

inline namespace MARS
{
	class Layer
	{
	public:

		Layer(const String& Name = "Layer");
		virtual ~Layer();


		virtual void OnEnd()									{}
		virtual void OnBegin()									{}
		virtual void OnAttach()									{}
		virtual void OnDetach()									{}
		virtual void OnUpdate()									{}
		virtual void OnEvent(Event& InEvent)					{}

		inline const String& GetName() const { return DebugName; }
		bool bDrawUserInterface;

		template<typename T>
		static T* Get()
		{
			static_assert(std::is_base_of<Layer, T>::value, "T must be child of Layer");
			static T* Instance = nullptr;
			if (Instance == nullptr)
			{
				Instance = new T;
			}

			return Instance;
		}

	private:

		String DebugName;
	};
}