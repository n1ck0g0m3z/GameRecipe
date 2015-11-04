#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <ppltasks.h>
#include "GameRecipe.h"
#include "CCApplication.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace Windows::Phone::UI::Input;
using namespace Windows::Graphics::Display;
using namespace concurrency;
USING_NS_CC;

GameRecipe::GameRecipe()
{
}

void GameRecipe::Initialize(CoreApplicationView^ applicationView)
{
	applicationView->Activated +=
		ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &GameRecipe::OnActivated);

	CoreApplication::Suspending +=
		ref new EventHandler<SuspendingEventArgs^>(this, &GameRecipe::OnSuspending);

	CoreApplication::Resuming +=
		ref new EventHandler<Platform::Object^>(this, &GameRecipe::OnResuming);
}

void GameRecipe::SetWindow(CoreWindow^ window)
{
    // Specify the orientation of your application here
    // The choices are DisplayOrientations::Portrait or DisplayOrientations::Landscape or DisplayOrientations::LandscapeFlipped
	DisplayProperties::AutoRotationPreferences = DisplayOrientations::Landscape;

	window->VisibilityChanged +=
		ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &GameRecipe::OnVisibilityChanged);

	window->Closed += 
		ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &GameRecipe::OnWindowClosed);

	window->PointerPressed +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &GameRecipe::OnPointerPressed);

	window->PointerMoved +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &GameRecipe::OnPointerMoved);

	window->PointerReleased +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &GameRecipe::OnPointerReleased);

    CCEGLView* eglView = new CCEGLView();
	eglView->Create(window);
    eglView->setViewName("GameRecipe");
}

void GameRecipe::Load(Platform::String^ entryPoint)
{
}

void GameRecipe::Run()
{
    CCApplication::sharedApplication()->run();
}

void GameRecipe::Uninitialize()
{
}

void GameRecipe::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnVisibilityChanged(sender, args);
}

void GameRecipe::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnWindowClosed(sender, args);
}

void GameRecipe::OnPointerPressed(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerPressed(sender, args);
}

void GameRecipe::OnPointerMoved(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerMoved(sender, args);
}

void GameRecipe::OnPointerReleased(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerReleased(sender, args);
}

void GameRecipe::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
	HardwareButtons::BackPressed += ref new EventHandler<BackPressedEventArgs^>(this, &GameRecipe::OnBackButtonPressed);   
	CoreWindow::GetForCurrentThread()->Activate();
}

void GameRecipe::OnBackButtonPressed(Object^ sender, BackPressedEventArgs^ args)
{
    // Leave args->Handled set to false and the app will quit when user presses the back button on the phone
}

void GameRecipe::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
	// Save app state asynchronously after requesting a deferral. Holding a deferral
	// indicates that the application is busy performing suspending operations. Be
	// aware that a deferral may not be held indefinitely. After about five seconds,
	// the app will be forced to exit.
	SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();
	//m_renderer->ReleaseResourcesForSuspending();

	create_task([this, deferral]()
	{
		// Insert your code here.

		deferral->Complete();
	});
}
 
void GameRecipe::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
	// Restore any data or state that was unloaded on suspend. By default, data
	// and state are persisted when resuming from suspend. Note that this event
	// does not occur if the app was previously terminated.
	// m_renderer->CreateWindowSizeDependentResources();
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
	return ref new GameRecipe();
}

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DApplicationSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}