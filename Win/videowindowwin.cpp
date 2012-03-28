#include <PluginWindowWin.h>
#include <logging.h>
#include "videowindowwin.h"

boost::shared_ptr<VideoWindow> VideoWindow::create() {
	return boost::make_shared<VideoWindowWin>();
}

VideoWindowWin::VideoWindowWin() {
	FBLOG_DEBUG("VideoWindowWin::VideoWindowWin()", this);
}

VideoWindowWin::~VideoWindowWin() {
	FBLOG_DEBUG("VideoWindowWin::~VideoWindowWin()", this);
}

void VideoWindowWin::setBackgroundColor(int r, int g, int b) {
}

void VideoWindowWin::setWindow(FB::PluginWindow *window) {
	FBLOG_DEBUG("VideoWindowWin::setWindow()", "window=" << window);
	FB::PluginWindowWin* wnd = reinterpret_cast<FB::PluginWindowWin*>(window);
	if (wnd) {
	} else {
	}
}

unsigned long VideoWindowWin::getId() {
	FBLOG_DEBUG("VideoWindowWin::getId()", this);
	return 0;
}