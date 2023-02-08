#pragma once
#include "Interfaces/IWindow.h"
#include "../Delegate.h"
#include "../W32/Memory.h"
#include "../W32/RTTI.h"
#include <memory>

class MainWindow : public IWindow
{
public:
	MainWindow();
	~MainWindow();
	void Draw() override;
	EWindowType GetWindowType() override { return EWindowType::MainWindow; };
	
	MulticastDelegate<std::shared_ptr<_Class>> OnClassSelected;
	MulticastDelegate<std::shared_ptr<TargetProcess>, std::shared_ptr<RTTI>> OnProcessSelected;
protected:
	void DrawProcessList();
	void RefreshProcessList();
	void SelectProcess();
	void DrawClassList();
	void DrawClass(std::shared_ptr<_Class> cl);
	
	

	std::string selectedProcessName;
	std::string processFilter;
	std::vector<ProcessListItem> ProcessList;
	std::shared_ptr<TargetProcess> Target;
	std::shared_ptr<RTTI> RTTIObserver;
	std::shared_ptr<_Class> SelectedClass;
};