#pragma once

#include "CoreMinimal.h"
#include "imgui/imgui.h"
#include "UserInterface/Overlay.h"

class OutputLog : Overlay
{
	struct ImGuiTextBuffer		Buffer;
	struct ImGuiTextFilter		Filter;
	Array<String>				LogList;
	Array<int32>				LineOffsets;
	bool						bAutoScroll;

public:

	OutputLog() = default;
	OutputLog(const String& InWindowName);

	void Clear();
	void AddLog(const char* Str);

	virtual void RenderLayerUI() override;

protected:

	void Draw(bool* bOpen);

};
