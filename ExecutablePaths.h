#ifndef DEF_ExecutablePaths
#define DEF_ExecutablePaths

#include <iostream>
#include <vector>
#include <map>

#include <QString>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoListIterator>
#include <QProcessEnvironment>

//#include <itksys/SystemTools.hxx> // for findProgramm

class ExecutablePaths
{
   public:

   ExecutablePaths();

   bool checkExecutablePath(QString path);
   void setExecutablePath(QString name, QString path); 
   void setDefaultExecutablePath(QString name);
   QString getExecutablePath(QString name); 

   QString findExecutablePath(QStringList splitPath, QString executableName);
  
   private: 

   std::map<QString, QString> m_executables; 

   QStringList m_splitPath;
};

#endif