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

#include <QtQuick>
#include <sailfishapp.h>
#include <QGuiApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    app->setOrganizationName("harbour-currencycalculator");
    app->setOrganizationDomain("winterhalder.ch");
    app->setApplicationName("harbour-currencycalculator");

    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(locale, SailfishApp::pathTo(QString("translations")).toLocalFile());
    app->installTranslator(&translator);

    view->setSource(SailfishApp::pathTo("qml/harbour-currencycalculator.qml"));
    view->rootContext()->setContextProperty("XDG_HOME_DIR", QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
    view->rootContext()->setContextProperty("XDG_DATA_DIR", QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    view->rootContext()->setContextProperty("XDG_CONFIG_DIR", QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
    view->rootContext()->setContextProperty("XDG_CACHE_DIR", QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
    view->show();

    return app->exec();
//    return 0;
}

