
#ifndef OPTIMIST_WINDOW_H
#define OPTIMIST_WINDOW_H

#include <WebWindow.h>
#include <Messenger.h>
#include <String.h>
#include <WindowStack.h>

class OptimistWindow : public BWebWindow {
public:
	OptimistWindow(BRect frame);
	OptimistWindow(BRect frame, BWebView* view);
	virtual ~OptimistWindow();
	
	// Overriden BWebWindow methods
	virtual void NewPageCreated(BWebView* view, BRect windowFrame, bool modalDialog, bool resizable, bool active);
private:
	void _Init(BWebView* webView);
	
	static bool m_initialized;
	static BWindowStack* m_stack;
};

#endif // OPTIMIST_WINDOW_H

