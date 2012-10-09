
#include "OptimistWindow.h"

#include <WebPage.h>
#include <WebView.h>
#include <WebViewConstants.h>
#include <WebSettings.h>
#include <GroupLayoutBuilder.h>

bool OptimistWindow::m_initialized = false;
BWindowStack* OptimistWindow::m_stack = false;

OptimistWindow::OptimistWindow(BRect frame)
	: BWebWindow(frame, "WebOptimist",
		B_DOCUMENT_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL,
		B_AUTO_UPDATE_SIZE_LIMITS | B_ASYNCHRONOUS_CONTROLS)
{
	_Init(new BWebView("web view"));
	CurrentWebView()->LoadURL("http://haiku-os.org/");
}

OptimistWindow::OptimistWindow(BRect frame, BWebView* webView)
	: BWebWindow(frame, "WebOptimist",
		B_DOCUMENT_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL,
		B_AUTO_UPDATE_SIZE_LIMITS | B_ASYNCHRONOUS_CONTROLS)
{
	_Init(webView);
}

OptimistWindow::~OptimistWindow()
{
}

// Copied from BWebWindow, and modified to be an OptimistWindow instead
void
OptimistWindow::NewPageCreated(BWebView* view, BRect windowFrame,
    bool modalDialog, bool resizable, bool activate)
{
	if (!windowFrame.IsValid())
		windowFrame = Frame().OffsetByCopy(10, 10);

	uint32 flags = Flags();

	window_look look;
	window_feel feel;
	if (modalDialog) {
		feel = B_MODAL_APP_WINDOW_FEEL;
		look = B_BORDERED_WINDOW_LOOK;
	} else {
	    look = B_TITLED_WINDOW_LOOK;
	    feel = B_NORMAL_WINDOW_FEEL;
	}
	if (!resizable)
		flags |= B_NOT_RESIZABLE;

    OptimistWindow* window = new OptimistWindow(windowFrame, view);
    
    m_stack->AddWindow(window);

    window->Show();
}

void
OptimistWindow::_Init(BWebView* webView)
{
	if (!m_initialized) {
		m_stack = new BWindowStack(this);
		m_initialized = true;
	}
	
	SetCurrentWebView(webView);
	
	AddChild(BGroupLayoutBuilder(B_VERTICAL).Add(webView));
}
