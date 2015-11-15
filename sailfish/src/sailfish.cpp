/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Jolla Ltd nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <PlaylistNode.h>
#include <sailfishapp.h>

#include "SettingsPageViewModel.h"
#include "ArtistsPageViewModel.h"

#include "ArtistsModel.h"
#include "CollectionModel.h"
#include "CoverArtImageProvider.h"
#include "GroupModel.h"
#include "MainViewModel.h"
#include "Track.h"
#include "MetadataController.h"
#include "ICollectionNode.h"
#include "ICollectionNodeProxy.h"

int main(int argc, char *argv[])
{
	qmlRegisterType<SettingsPageViewModel>("harbour.subsoniq", 1, 0, "SettingsPageViewModel");
	qmlRegisterType<ArtistsPageViewModel>("harbour.subsoniq", 1, 0, "ArtistsPageViewModel");
	qmlRegisterType<MainViewModel>("harbour.subsoniq", 1, 0, "MainViewModel");

	qmlRegisterType<CollectionModel>("harbour.subsoniq", 1, 0, "CollectionModel");
	qmlRegisterType<ArtistsModel>("harbour.subsoniq", 1, 0, "ArtistsModel");
	qmlRegisterType<GroupModel>("harbour.subsoniq", 1, 0, "GroupModel");
	qmlRegisterType<MetadataController>("harbour.subsoniq", 1, 0, "MetadataController");

	qmlRegisterType<Track>();
	qmlRegisterType<PlaylistNode>();
	qmlRegisterType<Playlist>();
	qmlRegisterType<ICollectionNode>();
	qmlRegisterType<ICollectionNodeProxy>();

	// SailfishApp::main() will display "qml/template.qml", if you need more
	// control over initialization, you can use:
	//
	//   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
	//   - SailfishApp::createView() to get a new QQuickView * instance
	//   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
	//
	// To display the view, call "show()" (will show fullscreen on device).

	QGuiApplication *application = SailfishApp::application(argc, argv);
	QQuickView *view = SailfishApp::createView();

	CoverArtImageProvider coverArtImageProvider;

	QQmlEngine *engine = view->engine();
	engine->addImageProvider("cover", &coverArtImageProvider);

	const QUrl &path = SailfishApp::pathTo("qml/subsoniq.qml");

	view->setSource(path);
	view->show();

	return application->exec();
}

