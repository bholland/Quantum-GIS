/***************************************************************************
                          qgsdataframe.h  -  description
                             -------------------
    begin                : Sun May 19 2013
    copyright            : (C) 2013 by Benedict M. Holland
    email                : benedict.m.holland at gmail.com
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#ifndef QGSDATAFRAME_H
#define QGSDATAFRAME_H
class QgsMapCanvas;

#include <QObject>

class CORE_EXPORT QgsDataFrame : public QObject
{
    Q_OBJECT

  public:
    /** Constructor
     * @param name The name of the data frame. This will default to Data Frame N where N is the current number of data frames.
     * @param parent The parent of the map canvas. This should most likely be the centralWidget
     */
    QgsDataFrame(QWidget *parent, QString name = QString::null);

    /** Destructor */
    virtual ~QgsDataFrame();

    /** Set the name of the data frame
     * @param name The new name for the data frame
     */
    void name(const QString &name) { mName = name; }

    /** Get the display name of the data frame
     * @return The data frame name
     */
    const QString& name() const { return mName; }

    /** Get the object name of this data frame
     * @return The object name of this data frame
     */
    const QString& objectName() const {return mObjectName; }

    /** Get the map canvas of this data frame
     * A setter method for this would be silly.
     * @return a pointer to the map canvas
     */
    QgsMapCanvas *mapCanvas() { return mMapCanvas; }

  private:
    /** Global per project setting of a UUID for data frames **/
    /** @todo make sure this gets saved and updated on load **/
     static int UUID;

     /** Incremend the UUID. This is used in the constructor for mUUID **/
     static int getUUID() { return UUID++; }

     /** private uuid for this object */
     const int mUUID;

     /** The name as it is displayed and altered */
     QString mName;

     /** The name of this data frame object */
     const QString mObjectName;

     /** Each data frame has its own map canvas */
     QgsMapCanvas *mMapCanvas;
/*
  signals:
    
  public slots:
*/
};

#endif // QGSDATAFRAME_H
