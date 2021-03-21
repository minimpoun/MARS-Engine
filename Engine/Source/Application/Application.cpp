#include "Application/Application.h"
#include "Input/InputHandler.h"
#include "UserInterface/Overlay.h"
#include "Rendering/BufferLayout.h"
#include "Rendering/Renderer.h"
#include "UserInterface/OutputLog.h"
#include "Rendering/RenderTypes.h"

extern Overlay* MARS::CreateImGuiLayer();

inline namespace MARS
{
	Application* Application::Instance = nullptr;
	Overlay* Application::ImGuiOverlayPtr = nullptr;

	Application::Application()
	{
		Log::Get(LogTemp).Info(TEXT("{}"), __FUNCTION__);

		bRunning = true;
		Instance = this;
		WindowPtr = std::unique_ptr<Window>(Window::Create());
		WindowPtr->SetEventCallback(BIND_EVENT_ONE_PARAM(Application::OnEvent));
		ImGuiOverlayPtr = MARS::CreateImGuiLayer();
	}

	Application::~Application()
	{

	}

	void Application::InitMARS()
	{	
		Log::Get(LogInit).Info("MARS Pre-Init Completed with 0 errors."); // TODO update this when the error log is written.
		Run();
	}

	void Application::Run()
	{
		while (bRunning)
		{
			ImGuiOverlayPtr->OnBegin();
			UpdateLayers();
			ImGuiOverlayPtr->OnEnd();

			WindowPtr->Refresh();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher _Dispatcher(e);
		_Dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_ONE_PARAM(Application::OnWindowClose));

		for (auto It = m_LayerStack.end(); It != m_LayerStack.begin();)
		{
			(*--It)->OnEvent(e);
			if (e.IsEventHandled())
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* InLayer)
	{
		m_LayerStack.PushElement(InLayer);
		InLayer->OnAttach();
	}

	void Application::PushOverlay(Overlay* InOverlay)
	{
		m_OverlayStack.PushOverlay(InOverlay);
		InOverlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		UNUSED_PROPERTY(e)
		bRunning = false;
		return true;
	}

	void Application::UpdateLayers() const
	{
		for (auto* Element : m_LayerStack)
		{
			Element->OnUpdate();
		}

		for (auto* Element : m_OverlayStack)
		{
			Element->OnUpdate();
			Element->RenderLayerUI();
		}
	}
}