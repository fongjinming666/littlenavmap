/*****************************************************************************
* Copyright 2015-2016 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef LITTLENAVMAP_CONSTANTS_H
#define LITTLENAVMAP_CONSTANTS_H

#include "geo/pos.h"

const atools::geo::Pos MAG_NORTH_POLE_2007 = atools::geo::Pos(-120.72f, 83.95f, 0.f);
const atools::geo::Pos MAG_SOUTH_POLE_2007 = atools::geo::Pos(137.684f, -64.497f, 0.f);

namespace lnm {

/* State of "do not show again" dialog buttons */
const QString ACTIONS_SHOWDISCONNECTINFO = "Actions/ShowDisconnectInfo";
const QString ACTIONS_SHOWQUIT = "Actions/ShowQuit";
const QString ACTIONS_SHOWRESETVIEW = "Actions/ShowResetView";
const QString ACTIONS_SHOWROUTEPARKINGWARNING = "Actions/ShowRouteParkingWarning";
const QString ACTIONS_SHOWROUTEWARNING = "Actions/ShowRouteWarning";
const QString ACTIONS_SHOWROUTEERROR = "Actions/ShowRouteError";

const QString DATABASE_BASEPATH = "Database/BasePath";
const QString DATABASE_LOADINGSIMULATOR = "Database/LoadingSimulator";
const QString DATABASE_PATHS = "Database/Paths";
const QString DATABASE_SCENERYCONFIG = "Database/SceneryConfig";
const QString DATABASE_SIMULATOR = "Database/Simulator";
const QString EXPORT_FILEDIALOG = "Export/FileDialog";
const QString INFOWINDOW_CURRENTMAPOBJECTS = "InfoWindow/CurrentMapObjects";
const QString INFOWINDOW_WIDGET = "InfoWindow/Widget";
const QString MAINWINDOW_FIRSTAPPLICATIONSTART = "MainWindow/FirstApplicationStart";
const QString MAINWINDOW_WIDGET = "MainWindow/Widget";
const QString MAP_DETAILFACTOR = "Map/DetailFactor";
const QString MAP_DISTANCEMARKERS = "Map/DistanceMarkers";
const QString MAP_HISTORY = "Map/History";
const QString MAP_HOMEDISTANCE = "Map/HomeDistance";
const QString MAP_HOMELATY = "Map/HomeLatY";
const QString MAP_HOMELONX = "Map/HomeLonX";
const QString MAP_KMLFILES = "Map/KmlFiles";
const QString MAP_MARKLATY = "Map/MarkLatY";
const QString MAP_MARKLONX = "Map/MarkLonX";
const QString MAP_RANGEMARKERS = "Map/RangeMarkers";
const QString NAVCONNECT_REMOTEHOSTS = "NavConnect/RemoteHosts";
const QString NAVCONNECT_REMOTE = "NavConnect/Remote";
const QString OPTIONS_FOREIGNKEYS = "Options/ForeignKeys";
const QString ROUTE_FILENAME = "Route/Filename";
const QString ROUTE_FILENAMESRECENT = "Route/FilenamesRecent";
const QString ROUTE_FILENAMESKMLRECENT = "Route/FilenamesKmlRecent";
const QString ROUTE_VIEW = "Route/View";
const QString SEARCHPANEAIRPORT_WIDGET = "SearchPaneAirport/Widget";
const QString SEARCHPANENAV_WIDGET = "SearchPaneNav/Widget";

const QString OPTIONS_DIALOG_WIDGET = "OptionsDialog/Widget";
const QString OPTIONS_DIALOG_ASN_FILE_DLG = "OptionsDialog/WeatherFileDialogAsn";
const QString OPTIONS_DIALOG_DB_FILE_DLG = "OptionsDialog/DatabaseFileDialog";
const QString OPTIONS_DIALOG_DB_EXCLUDE = "OptionsDialog/DatabaseExclude";
const QString OPTIONS_DIALOG_DB_ADDON_EXCLUDE = "OptionsDialog/DatabaseAddonExclude";

const QString OPTIONS_LANGUAGE = "Options/Language";
const QString OPTIONS_MARBLEDEBUG = "Options/MarbleDebug";
const QString OPTIONS_VERSION = "Options/Version";
const QString OPTIONS_SETTINGS_VERSION = "Options/SettingsVersion";

// File dialog patterns

#if defined(Q_OS_WIN32)
const QString FILE_PATTERN_SCENERYCONFIG = "(*.cfg)";
const QString FILE_PATTERN_FLIGHTPLAN = "(*.pln)";
const QString FILE_PATTERN_KML = "(*.kml *.kmz)";
#else
const QString FILE_PATTERN_SCENERYCONFIG = "(*.cfg *.CFG)";
const QString FILE_PATTERN_FLIGHTPLAN = "(*.pln *.PLN)";
const QString FILE_PATTERN_KML = "(*.kml *.KML *.kmz *.KMZ)";
#endif
const QString FILE_PATTERN_ASN_SNAPSHOT = "(current_wx_snapshot.txt)";

const QString DATABASE_DIR = "little_navmap_db";

} // namespace lnm

#endif // LITTLENAVMAP_CONSTANTS_H
