#pragma once

#include "Core/Layers/Layer.h"

inline namespace MARS
{
	class Overlay
	{
	public:

		Overlay() = default;
		Overlay(const String & InWindowName);
		~Overlay();

		virtual void OnUpdate();
		virtual void OnAttach();
		virtual void OnDetach();
		virtual void RenderLayerUI();

		virtual void OnBegin();
		virtual void OnEnd();

		inline const [[nodiscard]] String& GetName() const { return DebugName; }

		template<typename T>
		[[nodiscard]] static T* Get()
		{
			static_assert(std::is_base_of<Overlay, T>::value, "T must be child of Overlay");

			static T* Instance = nullptr;
			if (Instance == nullptr)
			{
				Instance = new T;
			}

			return Instance;
		}

	protected:

		static bool bShowDemoWindow;

		String DebugName;

	private:

		friend class Application;
		float m_Time = 0.f;

	};
}