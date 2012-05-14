/*!
 Linphone Web - Web plugin of Linphone an audio/video SIP phone
 Copyright (C) 2012  Yann Diorcet <yann.diorcet@linphone.org>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "coreapi.h"
#include "coreplugin.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn linphone::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void linphone::StaticInitialize() {
	// Place one-time initialization stuff here; As of FireBreath 1.4 this should only
	// be called once per process
}

///////////////////////////////////////////////////////////////////////////////
/// @fn linphone::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void linphone::StaticDeinitialize() {
	// Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
	// always be called just before the plugin library is unloaded
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  linphone constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
linphone::linphone() {
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  linphone destructor.
///////////////////////////////////////////////////////////////////////////////
linphone::~linphone() {
	// This is optional, but if you reset m_api (the shared_ptr to your JSAPI
	// root object) and tell the host to free the retained JSAPI objects then
	// unless you are holding another shared_ptr reference to your JSAPI object
	// they will be released here.
	releaseRootJSAPI();
	m_host->freeRetainedObjects();
}

void linphone::onPluginReady() {
	// When this is called, the BrowserHost is attached, the JSAPI object is
	// created, and we are ready to interact with the page and such.  The
	// PluginWindow may or may not have already fire the AttachedEvent at
	// this point.
}

void linphone::shutdown() {
	// This will be called when it is time for the plugin to shut down;
	// any threads or anything else that may hold a shared_ptr to this
	// object should be released here so that this object can be safely
	// destroyed. This is the last point that shared_from_this and weak_ptr
	// references to this object will be valid
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<linphone> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr linphone::createJSAPI() {
	FBLOG_DEBUG("linphone::createJSAPI()", this);
	// m_host is the BrowserHost
	return boost::make_shared<CoreAPI>(FB::ptr_cast<linphone>(shared_from_this()), m_host);
}

bool linphone::setReady () {
	FB::VariantMap::iterator fnd = m_params.find("magic");
    if (fnd != m_params.end()) {
		if(fnd->second.is_of_type<std::string>()) {
			FB::ptr_cast<CoreAPI>(getRootJSAPI())->setMagic(fnd->second.convert_cast<std::string>());
		}
	}
	return PluginCore::setReady();
}

bool linphone::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *) {
	//printf("Mouse down at: %d, %d\n", evt->m_x, evt->m_y);
	return false;
}

bool linphone::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *) {
	//printf("Mouse up at: %d, %d\n", evt->m_x, evt->m_y);
	return false;
}

bool linphone::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *) {
	//printf("Mouse move at: %d, %d\n", evt->m_x, evt->m_y);
	return false;
}
bool linphone::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *) {
	// The window is attached; act appropriately
	return false;
}

bool linphone::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *) {
	// The window is about to be detached; act appropriately
	return false;
}

