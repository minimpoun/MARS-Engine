#pragma once

#include "CoreMinimal.h"
#include "Application/Window.h"
#include "Core/Events/ApplicationEvent.h"
#include "Rendering/VertexArray.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/Shader.h"
#include "Rendering/OrthoCamera.h"

inline namespace MARS
{
	class Layer;
	class Overlay;

	class EXPORT_TYPE Application
	{
	public:

		Application();
		virtual ~Application();

		/** 
		 *	Global init function. Called by the application.
		 *	Starts the main loop and creates the Window class.
		 *	This is the first init function call of the engine
		 *	so it's a bad idea to try and add code here, 
		 *	it will most likely rely on system that haven't been initialized yet.
		 **/
		void InitMARS();

		void OnEvent(Event& e);

		void PushLayer(Layer* InLayer);
		void PushOverlay(Overlay* InOverlay);

		inline Window& GetWindow() { return *WindowPtr; }
		inline static Application& Get() { return *Instance; }
		inline static Overlay* GetImGuiLayer() { return ImGuiOverlayPtr; }

	protected:

		void Run();

		bool OnWindowClose(WindowCloseEvent& e);

		MStack<Layer> m_LayerStack;
		MStack<Overlay> m_OverlayStack;

	private:

		virtual void UpdateLayers() const;

		static Overlay* ImGuiOverlayPtr;
		static Application* Instance;
		std::unique_ptr<Window> WindowPtr;
		bool bRunning = false;
	};
}

/** We want to force the MARS namespace for these two functions to avoid confusion */
namespace MARS
{
	Application* CreateApplication();
	Overlay* CreateImGuiLayer();
}