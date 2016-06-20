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

#ifndef LITTLENAVMAP_DATABASEMANAGER_H
#define LITTLENAVMAP_DATABASEMANAGER_H

#include <QAction>
#include <QObject>

#include "sql/sqldatabase.h"
#include "fs/fspaths.h"
#include "db/dbtypes.h"

namespace atools {
namespace fs {
class BglReaderProgressInfo;
}
}

class QProgressDialog;
class QElapsedTimer;
class DatabaseDialog;
class DatabaseMeta;

class DatabaseManager :
  public QObject
{
  Q_OBJECT

public:
  DatabaseManager(QWidget *parent);
  virtual ~DatabaseManager();

  void run();

  void saveState();
  void restoreState();

  bool progressCallback(const atools::fs::BglReaderProgressInfo& progress, QElapsedTimer& timer);

  bool hasSchema();
  bool hasData();
  bool isDatabaseCompatible();
  void createEmptySchema(atools::sql::SqlDatabase *sqlDatabase);
  bool hasRegistrySims() const;

  const int DB_VERSION_MAJOR = 1;
  const int DB_VERSION_MINOR = 0;

  void openDatabase();
  void closeDatabase();
  QString getSimShortName() const;

  atools::sql::SqlDatabase *getDatabase();

  /* Actions have to be freed by the caller and are connected to switchSim */
  void insertSimSwitchActions(QAction *before, QMenu *menu);

  const QString& getDatabaseDirectory() const
  {
    return databaseDirectory;
  }

  /* if false quit application */
  bool checkIncompatibleDatabases();

  atools::fs::FsPaths::SimulatorType getCurrentFsType() const
  {
    return currentFsType;
  }

signals:
  void preDatabaseLoad();
  void postDatabaseLoad(atools::fs::FsPaths::SimulatorType type);

private:
  QString databaseFile, databaseDirectory;
  atools::sql::SqlDatabase db;
  QWidget *parentWidget;
  QProgressDialog *progressDialog = nullptr;
  bool loadScenery();
  void runNoMessages();

  QActionGroup *group = nullptr;
  QList<QAction *> actions;

  atools::fs::FsPaths::SimulatorType currentFsType = atools::fs::FsPaths::UNKNOWN,
                                     loadingFsType = atools::fs::FsPaths::UNKNOWN;
  FsPathTypeMap paths;

  void simulatorChangedFromCombo(atools::fs::FsPaths::SimulatorType value);

  bool runInternal(bool& loaded);

  void backupDatabaseFile();

  void restoreDatabaseFileBackup();

  QString buildDatabaseFileName(atools::fs::FsPaths::SimulatorType currentFsType);

  void updateDialogInfo();

  DatabaseDialog *databaseDialog = nullptr;
  void switchSimFromMenu();

  void freeActions();
  void updateSimSwitchActions();

  void removeDatabaseFileBackup();

  void fillPathsFromDatabases();

  void updatePathsFromDialog();

};

#endif // LITTLENAVMAP_DATABASEMANAGER_H
