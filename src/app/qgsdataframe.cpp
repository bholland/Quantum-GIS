#include <QSettings>

#include "qgsdataframe.h"
#include "qgsmapcanvas.h"

int QgsDataFrame::UUID = 0;

QgsDataFrame::QgsDataFrame(QWidget *parent, QString name) :
  mUUID(getUUID()),
  mObjectName("dataFrame" + QString(mUUID))
{
  if (name == QString::null)
  {
    mName = QString("Data Frame ") + QString(mUUID);
  }
  else
  {
    mName = name;
  }
  mMapCanvas = new QgsMapCanvas(parent, "mapCanvasDataFrame" + mUUID);


  QSettings settings;

  mMapCanvas->setWhatsThis(tr( "Map canvas. This is where raster and vector "
                               "layers are displayed when added to the map" ));

  int myRed = settings.value( "/qgis/default_canvas_color_red", 255 ).toInt();
  int myGreen = settings.value( "/qgis/default_canvas_color_green", 255 ).toInt();
  int myBlue = settings.value( "/qgis/default_canvas_color_blue", 255 ).toInt();
  mMapCanvas->setCanvasColor( QColor( myRed, myGreen, myBlue ) );

}

QgsDataFrame::~QgsDataFrame()
{
  delete mMapCanvas;
}
